# Json-Performance
Performance profiling of JSON libraries

Latest results (July 07, 2023):

Single Iteration Test Results:

| Library                                           | Test       | Write (MB/s) | Read (MB/s) |
| ------------------------------------------------- | ---------- | ------------ | ----------- |
| [**glaze**](https://github.com/RealTimeChris/glaze) | **Mixed** | **698** | **529** |
| [**glaze**](https://github.com/RealTimeChris/glaze) | **Double** | **851** | **1216** |
| [**glaze**](https://github.com/RealTimeChris/glaze) | **String** | **534** | **3027** |
| [**glaze**](https://github.com/RealTimeChris/glaze) | **Uint64** | **823** | **1439** |
| [**glaze**](https://github.com/RealTimeChris/glaze) | **Int64** | **1990** | **1417** |
| [**Jsonifier**](https://github.com/RealTimeChris/Jsonifier) | **Mixed** | **714** | **731** |
| [**Jsonifier**](https://github.com/RealTimeChris/Jsonifier) | **Double** | **906** | **1432** |
| [**Jsonifier**](https://github.com/RealTimeChris/Jsonifier) | **String** | **648** | **6604** |
| [**Jsonifier**](https://github.com/RealTimeChris/Jsonifier) | **Uint64** | **2790** | **1638** |
| [**Jsonifier**](https://github.com/RealTimeChris/Jsonifier) | **Int64** | **2006** | **1579** |
| [**simdjson (on demand)**](https://github.com/simdjson/simdjson) | **Mixed** | **N/A** | **808** |
| [**simdjson (on demand)**](https://github.com/simdjson/simdjson) | **Double** | **N/A** | **897** |
| [**simdjson (on demand)**](https://github.com/simdjson/simdjson) | **String** | **N/A** | **1142** |
| [**simdjson (on demand)**](https://github.com/simdjson/simdjson) | **Uint64** | **N/A** | **1117** |
| [**simdjson (on demand)**](https://github.com/simdjson/simdjson) | **Int64** | **N/A** | **1082** |

Multi Iteration Test Results:

| Library                                           | Test       | Write (MB/s) | Read (MB/s) |
| ------------------------------------------------- | ---------- | ------------ | ----------- |
| [**glaze**](https://github.com/stephenberry/glaze) | **Mixed** | **808** | **1138** |
| [**glaze**](https://github.com/stephenberry/glaze) | **Double** | **882** | **1309** |
| [**glaze**](https://github.com/stephenberry/glaze) | **String** | **700** | **4229** |
| [**glaze**](https://github.com/stephenberry/glaze) | **Uint64** | **2205** | **1449** |
| [**glaze**](https://github.com/stephenberry/glaze) | **Int64** | **2007** | **1419** |
| [**Jsonifier**](https://github.com/RealTimeChris/Jsonifier) | **Mixed** | **830** | **1396** |
| [**Jsonifier**](https://github.com/RealTimeChris/Jsonifier) | **Double** | **909** | **1438** |
| [**Jsonifier**](https://github.com/RealTimeChris/Jsonifier) | **String** | **666** | **7993** |
| [**Jsonifier**](https://github.com/RealTimeChris/Jsonifier) | **Uint64** | **2804** | **1644** |
| [**Jsonifier**](https://github.com/RealTimeChris/Jsonifier) | **Int64** | **2021** | **1581** |
| [**simdjson (on demand)**](https://github.com/simdjson/simdjson) | **Mixed** | **N/A** | **1181** |
| [**simdjson (on demand)**](https://github.com/simdjson/simdjson) | **Double** | **N/A** | **902** |
| [**simdjson (on demand)**](https://github.com/simdjson/simdjson) | **String** | **N/A** | **2222** |
| [**simdjson (on demand)**](https://github.com/simdjson/simdjson) | **Uint64** | **N/A** | **1225** |
| [**simdjson (on demand)**](https://github.com/simdjson/simdjson) | **Int64** | **N/A** | **1133** |
> 1000 iterations on a 6 core (Intel i7 8700k)

Test object, used in the "Mixed" tests (minified for test):

```json
{"fixed_object": {
      "int_array": [0, 1, 2, 3, 4, 5, 6],
      "float_array": [0.1, 0.2, 0.3, 0.4, 0.5, 0.6],
      "double_array": [3288398.238, 233e22, 289e-1, 0.928759872, 0.22222848, 0.1, 0.2, 0.3, 0.4,
                        3288398.238, 233e22, 289e-1, 0.928759872, 0.22222848, 0.1, 0.2, 0.3, 0.4,
                        3288398.238, 233e22, 289e-1, 0.928759872, 0.22222848, 0.1, 0.2, 0.3, 0.4,
                        3288398.238, 233e22, 289e-1, 0.928759872, 0.22222848, 0.1, 0.2, 0.3, 0.4]
   },
   "fixed_name_object": {
      "name0": "James",
      "name1": "Abraham",
      "name2": "Susan",
      "name3": "Frank",
      "name4": "Alicia"
   },
   "another_object": {
      "string": "here is some text",
      "another_string": "Hello World",
      "boolean": false,
      "nested_object": {
         "v3s": [[0.12345, 0.23456, 0.001345],
                  [0.3894675, 97.39827, 297.92387],
                  [18.18, 87.289, 2988.298],
                  [0.3894675, 97.39827, 297.92387],
                  [18.18, 87.289, 2988.298],
                  [0.3894675, 97.39827, 297.92387],
                  [18.18, 87.289, 2988.298]],
         "id": "298728949872"
      }
   },
   "string_array": ["Cat", "Dog", "Elephant", "Tiger","SuperlongohmygoshIamsomuchlongerthanthepreviousstringsstring", 
	"Cat", "Dog", "Elephant", "Tiger","SuperlongohmygoshIamsomuchlongerthanthepreviousstringsstring", 
	"Cat", "Dog", "Elephant", "Tiger","SuperlongohmygoshIamsomuchlongerthanthepreviousstringsstring", 
	"Cat", "Dog", "Elephant", "Tiger","SuperlongohmygoshIamsomuchlongerthanthepreviousstringsstring", 
	"Cat", "Dog", "Elephant", "Tiger","SuperlongohmygoshIamsomuchlongerthanthepreviousstringsstring", 
	"Cat", "Dog", "Elephant", "Tiger","SuperlongohmygoshIamsomuchlongerthanthepreviousstringsstring", 
	"Cat", "Dog", "Elephant", "Tiger","SuperlongohmygoshIamsomuchlongerthanthepreviousstringsstring", 
	"Cat", "Dog", "Elephant", "Tiger","SuperlongohmygoshIamsomuchlongerthanthepreviousstringsstring", 
	"Cat", "Dog", "Elephant", "Tiger","SuperlongohmygoshIamsomuchlongerthanthepreviousstringsstring", 
	"Cat", "Dog", "Elephant", "Tiger","SuperlongohmygoshIamsomuchlongerthanthepreviousstringsstring", 
	"Cat", "Dog", "Elephant", "Tiger","SuperlongohmygoshIamsomuchlongerthanthepreviousstringsstring", 
	"Cat", "Dog", "Elephant", "Tiger","SuperlongohmygoshIamsomuchlongerthanthepreviousstringsstring", 
	"Cat", "Dog", "Elephant", "Tiger","SuperlongohmygoshIamsomuchlongerthanthepreviousstringsstring", 
	"Cat", "Dog", "Elephant", "Tiger","SuperlongohmygoshIamsomuchlongerthanthepreviousstringsstring", 
	"Cat", "Dog", "Elephant", "Tiger","SuperlongohmygoshIamsomuchlongerthanthepreviousstringsstring", 
	"Cat", "Dog", "Elephant", "Tiger","SuperlongohmygoshIamsomuchlongerthanthepreviousstringsstring", 
	"Cat", "Dog", "Elephant", "Tiger", "SuperlongohmygoshIamsomuchlongerthanthepreviousstringsstring", "SuperlongohmygoshIamsomuchlongerthanthepreviousstringsstring"],
   "string": "Hello world",
   "number": 3.14,
   "boolean": true,
   "another_bool": false
}
```

Test objects, used in the "Double, String, Int64, and Uint64" tests:

```cpp
template<typename OTy> struct Test {
	std::vector<OTy> a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;

	Test() {
		auto fill = [](auto& v) {
			v.resize(1000);
			for (size_t x = 0; x < 1000; ++x) {
				if constexpr (std::same_as<OTy, std::string> || std::same_as<OTy, std::string>) {
					v[x] = std::to_string(1000000000000000) + std::to_string(1000000000000000) + std::to_string(1000000000000000) +
						std::to_string(1000000000000000) + std::to_string(1000000000000000) + std::to_string(1000000000000000) +
						std::to_string(1000000000000000) + std::to_string(1000000000000000);
				} else {
					v[x] = static_cast<OTy>(100000000000000000);
				}
			}
		};

		fill(a);
		fill(b);
		fill(c);
		fill(d);
		fill(e);
		fill(f);
		fill(g);
		fill(h);
		fill(i);
		fill(j);
		fill(k);
		fill(l);
		fill(m);
		fill(n);
		fill(o);
		fill(p);
		fill(q);
		fill(r);
		fill(s);
		fill(t);
		fill(u);
		fill(v);
		fill(w);
		fill(x);
		fill(y);
		fill(z);
	}
};
```

## ABC Test (Out of Sequence Performance)

The JSON documents in the previous tests featured keys ranging from "a" to "z," where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale.

| Library                                           | Test       | Write (MB/s) | Read (MB/s) |
| ------------------------------------------------- | ---------- | ------------ | ----------- |
| [**glaze**](https://github.com/RealTimeChris/glaze) | **Double** | **880** | **1337** |
| [**glaze**](https://github.com/RealTimeChris/glaze) | **String** | **704** | **4235** |
| [**glaze**](https://github.com/RealTimeChris/glaze) | **Uint64** | **2209** | **1449** |
| [**glaze**](https://github.com/RealTimeChris/glaze) | **Int64** | **2021** | **1437** |
| [**Jsonifier**](https://github.com/RealTimeChris/Jsonifier) | **Double** | **907** | **1469** |
| [**Jsonifier**](https://github.com/RealTimeChris/Jsonifier) | **String** | **663** | **7965** |
| [**Jsonifier**](https://github.com/RealTimeChris/Jsonifier) | **Uint64** | **2873** | **1645** |
| [**Jsonifier**](https://github.com/RealTimeChris/Jsonifier) | **Int64** | **2022** | **1581** |
| [**simdjson (on demand)**](https://github.com/simdjson/simdjson) | **Double** | **N/A** | **271** |
| [**simdjson (on demand)**](https://github.com/simdjson/simdjson) | **String** | **N/A** | **1130** |
| [**simdjson (on demand)**](https://github.com/simdjson/simdjson) | **Uint64** | **N/A** | **307** |
| [**simdjson (on demand)**](https://github.com/simdjson/simdjson) | **Int64** | **N/A** | **299** |
> 1001 iterations on a 6 core (Intel i7 8700k)