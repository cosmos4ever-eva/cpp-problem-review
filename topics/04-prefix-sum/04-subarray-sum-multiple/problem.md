# 04 连续子序列和的倍数

- 总题号：037
- 日期：2026-09-14
- 类型：前缀和、同余、哈希表、组合计数
- 状态：AI 辅助完成
- 建议复习：2026-09-15
- 原题：[Sunnywhy](https://sunnywhy.com/camp/3415/model/3591?itemId=3059)

## 题意

给定一个长度为 `n` 的整数数组和整数 `k`，统计有多少个非空连续子数组的元素和是 `k` 的倍数。

## 从枚举区间到比较前缀和

定义：

```cpp
prefix[i]
```

表示数组前 `i` 个数之和，并令 `prefix[0] = 0`。区间 `[l, r]` 的和可以写成：

```text
prefix[r] - prefix[l - 1]
```

直接枚举所有 `l`、`r`，即使使用前缀和在 `O(1)` 时间内求出每个区间和，总时间复杂度仍然是 `O(n^2)`，数据较大时会超时。

## 为什么只需要统计余数

区间和是 `k` 的倍数，等价于：

```text
(prefix[r] - prefix[l - 1]) % k == 0
```

也等价于两个前缀和除以 `k` 的余数相同：

```text
prefix[r] % k == prefix[l - 1] % k
```

因此不需要逐一比较所有前缀和。只需使用哈希表统计每一种余数出现了多少次。

如果某个余数出现了 `frequency` 次，从这些前缀中任取两个，较后的前缀减去较前的前缀，就能得到一个和为 `k` 的倍数的非空连续区间。方案数为：

```text
frequency * (frequency - 1) / 2
```

最后把所有余数对应的方案数相加即可。

## 为什么要先记录 `remainderCount[0] = 1`

`prefix[0] = 0` 表示一个数都没有选择时的空前缀，它除以 `k` 的余数是 `0`，因此应先写：

```cpp
remainderCount[0] = 1;
```

这个空前缀不是要作为答案中的空区间，而是用来统计从数组第一个元素开始的合法区间。例如 `prefix[r] % k == 0` 时，`prefix[r] - prefix[0]` 正好表示前 `r` 个元素组成的非空区间。

## 为什么会发生整数溢出

错误写法：

```cpp
long long countPairs(int frequency) {
    return frequency * (frequency - 1) / 2;
}
```

虽然函数返回 `long long`，但乘法的两个操作数都是 `int`，所以乘法会先按 `int` 计算。结果溢出后，错误的值才被转换成 `long long`，返回类型无法挽救此前已经发生的溢出。

可以把参数设为 `long long`：

```cpp
long long countPairs(long long frequency) {
    return frequency * (frequency - 1) / 2;
}
```

也可以显式使用 `1LL` 提升乘法类型：

```cpp
return 1LL * frequency * (frequency - 1) / 2;
```

这里需要保证的是参与乘法的中间结果使用 `long long`。输入长度 `n` 本身仍然可以使用 `int`；数组元素及其累计前缀和是否使用 `long long`，应根据题目给出的数值范围判断。为避免累计和溢出，整理版将元素和前缀和都设为 `long long`。

## 负数余数

如果数组允许出现负数，C++ 的 `%` 结果可能为负。例如 `-1 % 3 == -1`。为了让所有同余的前缀和使用同一个哈希键，可以统一成非负余数：

```cpp
long long remainder = prefixSum % k;
if (remainder < 0) {
    remainder += k;
}
```

如果题目保证数组元素均为非负数，这一步不会影响结果。

## 复杂度

- 时间复杂度：平均 `O(n)`；
- 空间复杂度：`O(n)`，最坏情况下保存 `n + 1` 种前缀余数。

## 主要易错点

1. 区间 `[l, r]` 的和是 `prefix[r] - prefix[l - 1]`，不是减去 `prefix[l]`。
2. 必须先记录空前缀：`remainderCount[0] = 1`。
3. 两个前缀余数相同，它们的差才一定是 `k` 的倍数。
4. 某个余数出现 `frequency` 次时，应增加 `frequency * (frequency - 1) / 2` 个区间。
5. 函数返回 `long long` 不会让函数内部的 `int * int` 自动变成 `long long`；参与乘法的操作数必须至少有一个是 `long long`。
6. 如果输入可能包含负数，需要把负余数归一化到 `[0, k - 1]`。
7. `unordered_map` 不能用连续下标遍历；范围 `for` 中的 `item.first` 是余数，`item.second` 是该余数出现的次数。

## 对原始代码的整理

[original.cpp](original.cpp) 保留你当前的代码。[solution.cpp](solution.cpp) 保留“先统计各余数频率，再计算组合数”的思路，同时删除不需要保存的数组，改为边输入边累计前缀和；输入长度使用 `int`，前缀和、频率和答案使用 `long long`，并补充负数余数归一化。

## 复习问题

1. 为什么区间和可以表示成两个前缀和之差？
2. 为什么两个前缀和余数相同，就能得到一个合法区间？
3. `remainderCount[0] = 1` 代表什么？如果删除会漏掉哪些区间？
4. 某个余数出现 `5` 次时，为什么能组成 `5 * 4 / 2 = 10` 个区间？
5. 为什么返回类型是 `long long` 仍可能在返回前发生 `int` 溢出？

## 文件

- [solution.cpp](solution.cpp)：哈希统计前缀余数的整理版代码
- [original.cpp](original.cpp)：你当前提交的代码
- [sample.in](sample.in) / [sample.out](sample.out)：基础测试样例
