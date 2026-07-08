#!/usr/bin/env bash

if [ -z "${BASH_VERSINFO:-}" ] || [ "${BASH_VERSINFO[0]}" -lt 4 ]; then
    for candidate in "$(command -v bash 2>/dev/null)"; do
        if [ -n "${candidate}" ] && [ -x "${candidate}" ]; then
            candidate_major="$("${candidate}" -c 'echo "${BASH_VERSINFO[0]}"' 2>/dev/null)"
            if [ -n "${candidate_major}" ] && [ "${candidate_major}" -ge 4 ] 2>/dev/null; then
                exec "${candidate}" "$0" "$@"
            fi
        fi
    done
    echo "[!] No bash >= 4.0 found (associative arrays required)." >&2
    exit 1
fi

set -u

COMPILER_TAG="Linux-Clang"
CXX_COMPILER="${CXX_BIN:-/usr/bin/clang++-23}"
C_COMPILER="${C_BIN:-/usr/bin/clang-23}"
CSV_PATH="./csv/${COMPILER_TAG}/Results.csv"
SWEEP_DIR="./sweep_results/${COMPILER_TAG}"
SUMMARY_FILE="${SWEEP_DIR}/summary.txt"

mkdir -p "${SWEEP_DIR}"
: > "${SUMMARY_FILE}"

declare -A RESULTS_WINS
declare -A RESULTS_TIES
declare -A RESULTS_LOSSES

CPU_NAME=""
CPU_HEADER_WRITTEN=0

extract_cpu_name() {
    local csv_path=$1
    grep -m1 '^#\*\*CPU:\*\*' "${csv_path}" 2>/dev/null | sed -E 's/^#\*\*CPU:\*\*[[:space:]]*//'
}

print_leaderboard() {
    echo ""
    echo "================================================================"
    echo " LIVE LEADERBOARD${CPU_NAME:+ - ${CPU_NAME}} (sorted by Wins desc, Losses asc)"
    echo "================================================================"
    printf "%-40s  %6s  %6s  %6s\n" "CONFIG" "WINS" "TIES" "LOSSES"
    echo "--------------------------------------------------------------------------------"

    for key in "${!RESULTS_WINS[@]}"; do
        printf "%s %s %s %s\n" "${key}" "${RESULTS_WINS["$key"]}" "${RESULTS_TIES["$key"]}" "${RESULTS_LOSSES["$key"]}"
    done | sort -k2,2 -nr -k4,4 -n | while read k w t l; do
        printf "%-40s  %6s  %6s  %6s\n" "$k" "$w" "$t" "$l"
    done
}

run_config() {
    local tape_max=$1
    local tape_step=$2
    local blocks_per_step=$3
    local key="MAX=${tape_max}_STEP=${tape_step}_BLOCKS=${blocks_per_step}"

    echo ""
    echo "================================================================"
    echo " CONFIG: TAPE_MAX=${tape_max}  TAPE_STEP=${tape_step}  BLOCKS_PER_STEP=${blocks_per_step}${CPU_NAME:+ | CPU=${CPU_NAME}}"
    echo "================================================================"

    rm -rf ./Build

    cmake -S . -B ./Build \
        -DCMAKE_BUILD_TYPE=Release \
        -DCMAKE_INSTALL_PREFIX=./Install \
        -DCMAKE_CXX_COMPILER="${CXX_COMPILER}" \
        -DCMAKE_C_COMPILER="${C_COMPILER}" \
        -DJSONIFIER_TAPE_MAX=${tape_max} \
        -DJSONIFIER_TAPE_STEP=${tape_step} \
        -DJSONIFIER_BLOCKS_PER_STEP=${blocks_per_step}

    if [ $? -ne 0 ]; then
        echo "[!] CMake configure failed for ${key}, skipping."
        RESULTS_WINS["$key"]=-1
        RESULTS_TIES["$key"]=-1
        RESULTS_LOSSES["$key"]=-1
        print_leaderboard
        return
    fi

    cmake --build ./Build --config Release --parallel -v

    if [ $? -ne 0 ]; then
        echo "[!] Build failed for ${key}, skipping."
        RESULTS_WINS["$key"]=-1
        RESULTS_TIES["$key"]=-1
        RESULTS_LOSSES["$key"]=-1
        print_leaderboard
        return
    fi

    cmake --install ./Build --config Release

    local BIN_PATH="./Install/bin/Json-Performance"
    if [ ! -x "${BIN_PATH}" ]; then
        BIN_PATH="./Build/Json-Performance"
    fi

    sudo "${BIN_PATH}"

    if [ ! -f "${CSV_PATH}" ]; then
        echo "[!] Results.csv not found at ${CSV_PATH} for ${key}"
        RESULTS_WINS["$key"]=-1
        RESULTS_TIES["$key"]=-1
        RESULTS_LOSSES["$key"]=-1
        print_leaderboard
        return
    fi

    if [ -z "${CPU_NAME}" ]; then
        CPU_NAME="$(extract_cpu_name "${CSV_PATH}")"
        if [ -n "${CPU_NAME}" ] && [ "${CPU_HEADER_WRITTEN}" -eq 0 ]; then
            echo "# CPU: ${CPU_NAME}" >> "${SUMMARY_FILE}"
            CPU_HEADER_WRITTEN=1
        fi
    fi

    cp "${CSV_PATH}" "${SWEEP_DIR}/Results_${key}.csv"

    local wins ties losses
    read wins ties losses < <(
        awk -F',' '
            /^#/ { next }
            /^Library/ { next }
            $1 == "jsonifier" { w=$2; t=$3; l=$4 }
            END { printf "%s %s %s\n", w, t, l }
        ' "${CSV_PATH}"
    )

    RESULTS_WINS["$key"]=${wins:-0}
    RESULTS_TIES["$key"]=${ties:-0}
    RESULTS_LOSSES["$key"]=${losses:-0}

    echo ""
    echo ">>> ${key}: Wins=${wins} Ties=${ties} Losses=${losses}${CPU_NAME:+ | CPU=${CPU_NAME}}"
    echo "${key},${wins},${ties},${losses}" >> "${SUMMARY_FILE}"

    print_leaderboard
}

BLOCK_VALUES=(4)
STEP_VALUES=(32 16 8 4 2 1)

for ((i=0; i<${#BLOCK_VALUES[@]}; i+=1)); do
    blocks_per_step=${BLOCK_VALUES[i]}
    for ((j=0; j<${#STEP_VALUES[@]}; j+=1)); do
    tape_step=${STEP_VALUES[j]}
    run_config 1 "${tape_step}" "${blocks_per_step}"
    done
done

echo ""
echo "Sweep finished.${CPU_NAME:+ CPU: ${CPU_NAME}}"
echo "Per-config CSVs saved to: ${SWEEP_DIR}/"
echo "Summary CSV: ${SUMMARY_FILE}"