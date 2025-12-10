import argparse
import json
import os
import seaborn as sns
import matplotlib.pyplot as plt
import pandas as pd

def parse_args():
    parser = argparse.ArgumentParser(description='Process benchmark results from a JSON file.')
    parser.add_argument('input_file', type=str, help='Path to the input JSON file')
    parser.add_argument('output_directory', type=str, help='Path to store the graphs')
    return parser.parse_args()

def get_raw_speeds(df):
    raw_speeds = {"Read": [], "Write": []}
    libraries = df["library_name"].unique()

    for result_type in raw_speeds.keys():
        result_type_df = df[df["result_type"] == result_type].sort_values(by="result_speed")

        if result_type_df.empty:
            raw_speeds[result_type] = [0] * len(libraries)
            continue

        speed_map = dict(zip(result_type_df["library_name"], result_type_df["result_speed"]))

        raw_speeds[result_type] = [
            speed_map.get(library, 0) for library in libraries
        ]

    return raw_speeds

def calculate_cumulative_speedup(df):
    cumulative_speedups = {"Read": [], "Write": []}
    libraries = df["library_name"].unique()

    for result_type in cumulative_speedups.keys():
        result_type_df = df[df["result_type"] == result_type].sort_values(by="result_speed")

        if result_type_df.empty:
            cumulative_speedups[result_type] = [0] * len(libraries)
            continue

        slowest_speed = result_type_df.iloc[0]["result_speed"]
        result_type_speedups = [100]

        for i in range(1, len(result_type_df)):
            current_speed = result_type_df.iloc[i]["result_speed"]
            speedup = ((current_speed / slowest_speed) - 1) * 100 + 100
            result_type_speedups.append(speedup)

        speedup_map = dict(zip(result_type_df["library_name"], result_type_speedups))
        cumulative_speedups[result_type] = [
            speedup_map.get(library, 0) for library in libraries
        ]

    return cumulative_speedups

def plot_speed_results(
    df, 
    speed_data, 
    output_folder, 
    test_name, 
    is_cumulative=False, 
    y_label="Result Speed (MB/s)",
    label_metric = "MB/s"
):
    """
    Plots either cumulative speedups or raw speed comparisons for libraries.

    Args:
        df (pd.DataFrame): The DataFrame containing library performance data.
        speed_data (dict): The speed data, with keys "Read" and "Write".
        output_folder (str): Path to the folder where the plot will be saved.
        test_name (str): Name of the test for labeling the output.
        is_cumulative (bool): If True, plots cumulative speedups; otherwise, raw speeds.
        y_label (str): Label for the y-axis.
    """
    sns.set_style("dark")
    sns.set_style(rc={'axes.facecolor': '#0d1117'})
    plt.figure(figsize=(10, 6))
    ax = plt.gca()

    sns.set_theme(style="whitegrid", rc={"axes.edgecolor": "#0d1117", "xtick.color": "#0d1117", "ytick.color": "#0d1117"})
    plt.gcf().set_facecolor("#0d1117")
    ax = plt.gca()

    has_read_results = "Read" in df["result_type"].unique()
    has_write_results = "Write" in df["result_type"].unique()

    if has_read_results:
        sort_df = df[df["result_type"] == "Read"].sort_values(by="result_speed", ascending=False)
    elif has_write_results:
        sort_df = df[df["result_type"] == "Write"].sort_values(by="result_speed", ascending=False)
    else:
        print("No read or write results found in the DataFrame.")
        return

    sorted_libraries = sort_df["library_name"].tolist()

    library_colors = {
        (row['library_name'], row['result_type']): row['color']
        for _, row in df.iterrows()
    }

    speed_read = speed_data.get("Read", [0] * len(sorted_libraries))
    speed_write = speed_data.get("Write", [0] * len(sorted_libraries))

    num_libraries = len(sorted_libraries)
    max_libraries = max(2, num_libraries)
    width = 0.8 / max_libraries

    for i, library in enumerate(sorted_libraries):
        read_speed = speed_read[i] if i < len(speed_read) else 0
        write_speed = speed_write[i] if i < len(speed_write) else 0

        read_color = library_colors.get((library, 'Read'), 'gray')
        write_color = library_colors.get((library, 'Write'), 'gray')

        font_size = max(8, width * 30)

        if read_speed != 0 and write_speed != 0:
            ax.bar(i - width / 2, read_speed, label=f"{library} Read", color=read_color, width=width)
            ax.bar(i + width / 2, write_speed, label=f"{library} Write", color=write_color, width=width)
        elif read_speed != 0:
            ax.bar(i, read_speed, label=f"{library} Read", color=read_color, width=width)
        elif write_speed != 0:
            ax.bar(i, write_speed, label=f"{library} Write", color=write_color, width=width)
        
        if read_speed != 0:
            ax.text(i - width / 2 if write_speed != 0 else i, read_speed - 0.05 * read_speed,
                    f"{read_speed:.2f}"+label_metric, ha='center', va='top', color='black', fontsize=font_size, fontweight='bold')
        if write_speed != 0:
            ax.text(i + width / 2 if read_speed != 0 else i, write_speed - 0.05 * write_speed,
                    f"{write_speed:.2f}"+label_metric, ha='center', va='top', color='black', fontsize=font_size, fontweight='bold')
    
    ax.set_xticks(range(len(sorted_libraries)))
    ax.set_xticklabels(sorted_libraries, ha='center')
    ax.set_title(
        f"{test_name} {'Cumulative Speedup (Relative to Slowest Library)' if is_cumulative else 'Result Speed Comparison'}",
        color='white'
    )
    ax.set_xlabel('Library Name', color='white')
    ax.set_ylabel(y_label, color='white')
    
    for text in ax.get_xticklabels() + ax.get_yticklabels():
        text.set_color('lightgray')
    
    ax.legend(title='Library and Result Type', loc='best')
    
    output_file_path = os.path.join(output_folder, f"{test_name}_{'Cumulative_Speedup' if is_cumulative else 'Results'}.png")
    plt.savefig(output_file_path)
    plt.close()

def main():
    args = parse_args()
    input_file = args.input_file
    output_folder = args.output_directory

    with open(input_file, 'r') as file:
        data = json.load(file)

    os.makedirs(output_folder, exist_ok=True)

    for test in data:
        df = pd.DataFrame(test["results"])

        raw_speed = get_raw_speeds(df)

        cumulative_speedups = calculate_cumulative_speedup(df)
        
        plot_speed_results(df, raw_speed, output_folder, test["test_name"], is_cumulative = False, y_label = "Result Speed (MB/s)")
        
        plot_speed_results(df, cumulative_speedups, output_folder, test["test_name"], is_cumulative = True, y_label = "Cumulative Speedup (%)", label_metric="%")
        
        print(f'Graphs saved successfully for {test["test_name"]}!')

if __name__ == "__main__":
    main()