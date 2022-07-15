# AC(AtCoder) Library Document (@{keyword.tag})

@{keyword.info}

## How to Install

- There is `atcoder` folder in the `ac-library` folder, after extracting the zip file.
- With g++, you can compile by `g++ main.cpp -std=c++14 -I .` with putting `atcoder` folder on the same place as `main.cpp`.
  - You should compile with `-std=c++14` or `-std=c++17`.
- See [Appendix](./appendix.html) for further details.

## Note

- The behavior is undefined if the input does not match the constraints.
- For simplicity, we abbreviate the types as follows.
  - `unsigned int` → `uint`
  - `long long` → `ll`
  - `unsigned long long` → `ull`
- $0^0=1$.
- Multiple edges and self-loops are allowed unless specified.

## List

`#include <lastweapon/all>` : include everything

### Data Structures

- [`#include <lastweapon/fenwicktree>`](./fenwicktree.html)
- [`#include <lastweapon/segtree>`](./segtree.html)
- [`#include <lastweapon/lazysegtree>`](./lazysegtree.html)
- [`#include <lastweapon/string>`](./string.html)

### Math

- [`#include <lastweapon/math>`](./math.html)
- [`#include <lastweapon/convolution>`](./convolution.html)
- 💻[`#include <lastweapon/modint>`](./modint.html)

### Graphs

- [`#include <lastweapon/dsu>`](./dsu.html)
- [`#include <lastweapon/maxflow>`](./maxflow.html)
- [`#include <lastweapon/mincostflow>`](./mincostflow.html)
- [`#include <lastweapon/scc>`](./scc.html)
- [`#include <lastweapon/twosat>`](./twosat.html)

## Appendix

- [Appendix / FAQ](./appendix.html)

## Test

- You can test this Library [here](https://atcoder.jp/contests/practice2?lang=en).


## License

The header files in `atcoder` folder are licensed under a CC0 license. See `lastweapon/LICENSE` for further details.