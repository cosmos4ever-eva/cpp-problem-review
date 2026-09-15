# 数论常用模板

## 组合数 `C(n,m)`

使用递推关系：

```text
C(n,m) = 1 * (n-m+1)/1 * (n-m+2)/2 * ... * n/m
```

核心更新：

```cpp
total = total * (n - m + i) / i;
```

每轮的 `total` 都是一个完整组合数，因此除法能够整除。与先计算 `n!、m!、(n-m)!` 相比，它不需要保存巨大的阶乘中间值，能够降低溢出风险。

但要注意：代码仍然先算 `total * (n - m + i)`，所以并不能保证永不溢出。若数据范围较大，需要使用更大的整数类型、约分或题目指定的取模算法。

使用 `m = min(m, n - m)` 可以利用：

```text
C(n,m) = C(n,n-m)
```

减少循环次数。

## 非取模快速幂

把指数写成二进制。循环中始终维护：

- `base`：当前二进制位对应的底数贡献；每轮执行 `base *= base`。
- `exponent`：尚未处理的指数；每轮执行 `exponent /= 2`。
- `answer`：已经选中的底数贡献之积。

当指数当前最低位为 `1`，也就是指数为奇数时：

```cpp
answer *= base;
```

随后无论奇偶都执行：

```cpp
base *= base;
exponent /= 2;
```

例如计算 `3^5`，指数 `5` 的二进制是 `101`，会选中 `3^1` 和 `3^4`，最终得到 `3 * 81 = 243`。

原始写法中 `a` 是 `int`，所以 `a *= a` 会按 `int` 运算，可能在赋给 `long long ans` 之前就溢出。复用模板时应让 `base`、`exponent` 和 `answer` 使用 `long long`。

这份模板没有取模。若题目要求 `a^b mod p`，应在答案乘法和底数平方后都取模，并根据数据范围判断乘法本身是否还需要更大的类型。

## 文件

- [combination.cpp](combination.cpp)：加入边界检查与对称优化的可复用模板。
- [combination-original.cpp](combination-original.cpp)：你的原始组合数代码。
- [fast-power.cpp](fast-power.cpp)：把底数与指数提升为 `long long` 的可复用模板。
- [fast-power-original.cpp](fast-power-original.cpp)：你的原始快速幂代码。
