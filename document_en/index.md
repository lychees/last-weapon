# My Library Document (@{keyword.tag})

Last Weapon is my own algorithms library for competitive programming, it is a fork from [ACL](https://github.com/lychees/ac-library) with some alternative algorithms and additional features.

![](https://img2.baidu.com/it/u=2865842250,1747329531&fm=253&fmt=auto&app=138&f=GIF?w=214&h=149)

## Reference
### Template
- [(https://github.com/lychees/ac-library) ]((https://github.com/lychees/ac-library) )
- [https://github.com/not522/ac-library-python/](https://github.com/not522/ac-library-python/)
- [https://github.com/hos-lyric/libra](https://github.com/hos-lyric/libra)
- [https://github.com/kth-competitive-programming/kactl](https://github.com/kth-competitive-programming/kactl)

### Textbook
- [https://oi-wiki.org/](https://oi-wiki.org/)
- [https://web.ntnu.edu.tw/~algo/](https://web.ntnu.edu.tw/~algo/)


## How to Install

- There is `atcoder` folder in the `ac-library` folder, after extracting the zip file.
- With g++, you can compile by `g++ main.cpp -std=c++14 -I .` with putting `atcoder` folder on the same place as `main.cpp`.
  - You should compile with `-std=c++14` or `-std=c++17`.
- See [Appendix](./appendix.html) for further details.

## Note

- The behavior is undefined if the input does not match the constraints.
- For simplicity, we abbreviate the types as follows.
  - `unsigned int` -> `uint`
  - `long long` -> `ll`
  - `unsigned long long` -> `ull`
- $0^0=1$.
- Multiple edges and self-loops are allowed unless specified.

## List

`#include <lastweapon/all>` : include everything

### Data Structures

- [`#include <lastweapon/dsu>`](./dsu.html)
- [`#include <lastweapon/fenwicktree>`](./fenwicktree.html)
- [`#include <lastweapon/segtree>`](./segtree.html)
- [`#include <lastweapon/lazysegtree>`](./lazysegtree.html)

### Math

- [`#include <lastweapon/math>`](./math.html)
- [`#include <lastweapon/convolution>`](./convolution.html)
- [`#include <lastweapon/modint>`](./modint.html)

### Graphs

- [`#include <lastweapon/maxflow>`](./maxflow.html)
- [`#include <lastweapon/mincostflow>`](./mincostflow.html)
- [`#include <lastweapon/scc>`](./scc.html)
- [`#include <lastweapon/twosat>`](./twosat.html)

### Strings
- [`#include <lastweapon/string>`](./string.html)
- [`#include <lastweapon/sam>`](./sam.html)

### Geometry
- [`#include <lastweapon/geometry>`](./geometry.html)

## MISC
- [`#include <lastweapon/bignum>`](./bignum.html)

## Appendix

- [Appendix / FAQ](./appendix.html)

## Test

- You can test this Library [here](https://atcoder.jp/contests/practice2?lang=en).


## License

The header files in `atcoder` folder are licensed under a CC0 license. See `lastweapon/LICENSE` for further details.



