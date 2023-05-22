# Json-Performance
Performance profiling of JSON libraries

Latest results (Dec 05, 2023):

[Test value, used in the following tests:](https://github.com/RealTimeChris/Json-Performance/blob/main/JsonData.json)

Single Iteration Test Results:

| Library | Write (MB/s) | Read (MB/s) |
| ------------------------------------------------- | ---------- | ----------- |
| [**simdjson**](https://github.com/simdjson/simdjson) | **N/A** | **359.36** |
| [**glaze**](https://github.com/stephenberry/glaze) | **1023.13** | **354.06** |
| [**jsonifier**](https://github.com/realtimechris/jsonifier) | **1126.73** | **415.61** |

Multi Iteration Test Results:

| Library | Write (MB/s) | Read (MB/s) |
| ------------------------------------------------- | ---------- | ----------- |
| [**simdjson**](https://github.com/simdjson/simdjson) | **N/A** | **449.80** |
| [**glaze**](https://github.com/stephenberry/glaze) | **1167.90** | **725.44** |
| [**jsonifier**](https://github.com/realtimechris/jsonifier) | **1330.91** | **945.46** |
> 100 iterations on a 6 core (Intel i7 8700k)

## ABC Test (Out of Sequence Performance)

The JSON documents in the previous tests featured keys ranging from "a" to "z," where each key corresponds to an array of values. Notably, the documents in this test arrange these keys in reverse order, deviating from the typical "a" to "z" arrangement.

This test effectively demonstrates the challenges encountered when utilizing simdjson and iterative parsers that lack the ability to efficiently allocate memory locations through hashing. In cases where the keys are not in the expected sequence, performance is significantly compromised, with the severity escalating as the document size increases.

In contrast, hash-based solutions offer a viable alternative by circumventing these issues and maintaining optimal performance regardless of the JSON document's scale, or ordering of the keys being parsed.

| Library | Write (MB/s) | Read (MB/s) |
| ------------------------------------------------- | ---------- | ----------- |
| [**simdjson**](https://github.com/simdjson/simdjson) | **N/A** | **212.42** |
| [**glaze**](https://github.com/stephenberry/glaze) | **1167.02** | **728.99** |
| [**jsonifier**](https://github.com/realtimechris/jsonifier) | **1331.57** | **944.55** |
> 100 iterations on a 6 core (Intel i7 8700k)