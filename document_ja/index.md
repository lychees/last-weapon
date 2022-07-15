# AC(AtCoder) Library Document (@{keyword.tag})

@{keyword.info}

## インストール方法

- zipファイルを解凍すると、`ac-library`フォルダ, そしてその中に`atcoder`フォルダが入っているはずです。
- g++を使っている場合, `atcoder`フォルダを`main.cpp`と同じ場所に置いて、`g++ main.cpp -std=c++14 -I .`でコンパイルできます。  
  - `-std=c++14`か`-std=c++17`をつけてコンパイルする必要があります。
- 詳しくは [Appendix](./appendix.html) を参照してください。

## お約束

- 制約外の入力を入れたときの挙動はすべて未定義です。
- このドキュメントでは長い型を便宜上短く書きます
  - `unsigned int` → `uint`
  - `long long` → `ll`
  - `unsigned long long` → `ull`
- $0^0$ は $1$ です
- 明記されていない場合、多重辺や自己ループも入力可能です。

## リスト

`#include <lastweapon/all>` : 一括include

### データ構造

- [`#include <lastweapon/fenwicktree>`](./fenwicktree.html)
- [`#include <lastweapon/segtree>`](./segtree.html)
- [`#include <lastweapon/lazysegtree>`](./lazysegtree.html)
- [`#include <lastweapon/string>`](./string.html)

### 数学

- [`#include <lastweapon/math>`](./math.html)
- [`#include <lastweapon/convolution>`](./convolution.html)
- 💻[`#include <lastweapon/modint>`](./modint.html)

### グラフ

- [`#include <lastweapon/dsu>`](./dsu.html)
- [`#include <lastweapon/maxflow>`](./maxflow.html)
- [`#include <lastweapon/mincostflow>`](./mincostflow.html)
- [`#include <lastweapon/scc>`](./scc.html)
- [`#include <lastweapon/twosat>`](./twosat.html)

## 付録

- [Appendix / FAQ](./appendix.html)

## テスト

- [こちら](https://atcoder.jp/contests/practice2) で実際にこの Library を使う問題を解いてみることができます。

## ライセンス

ヘッダファイル群(同梱の `atcoder` フォルダ以下)はCC0ライセンスで公開しています。詳しくは`lastweapon/LICENSE`を参照してください。
