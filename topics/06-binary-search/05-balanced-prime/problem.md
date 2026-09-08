# 05 平衡素数

- 总题号：015
- 日期：2026-09-08
- 类型：二分查找、`lower_bound`、筛法、预处理
- 状态：AI 辅助完成
- 建议复习：2026-09-09
- 原题：[Sunnywhy](https://sunnywhy.com/camp/3415/model/3591?itemId=3066)

## 题意

如果一个素数等于前一个素数与后一个素数的平均值，那么它是平衡素数。对于每个查询值 `N`：

- 如果 `N` 是平衡素数，输出 `Yes`；
- 否则输出 `No`，以及不小于 `N` 的最小平衡素数。

查询次数最多为 `10^5`，查询值满足 `3 <= N <= 10^7`。

## 核心思路

先筛出足够范围内的全部质数。对于三个相邻质数：

```text
primes[i - 1], primes[i], primes[i + 1]
```

如果：

```cpp
primes[i] - primes[i-1] == primes[i+1] - primes[i]
```

那么 `primes[i]` 是平衡素数。按照质数表从左到右收集后，`neighborprimes` 自然保持升序。

对于每个查询，不再从头线性扫描所有平衡素数，而是在有序的 `neighborprimes` 中使用 `lower_bound` 二分查找。

## `lower_bound` 的用法

需要包含头文件：

```cpp
#include<algorithm>
```

调用方式：

```cpp
auto it = lower_bound(
    neighborprimes.begin(),
    neighborprimes.end(),
    N[i]
);
```

`lower_bound` 返回一个迭代器，它指向有序区间中第一个满足下面条件的元素：

```text
元素 >= N[i]
```

这里返回的是迭代器位置，不是平衡素数的值；使用 `*it` 才能取得该位置的元素。

- 如果 `*it == N[i]`，说明查询值本身就是平衡素数；
- 如果 `*it > N[i]`，那么 `*it` 就是不小于查询值的最小平衡素数。

如果不存在不小于目标值的元素，`lower_bound` 会返回 `neighborprimes.end()`。`end()` 指向最后一个元素之后的位置，不能解引用，因此应先判断：

```cpp
it != neighborprimes.end()
```

## 另一种解法：`nextBalancedPrime` 数组

如果愿意使用更多内存，可以预处理数组：

```cpp
nextBalancedPrime[x]
```

它表示“不小于 `x` 的最小平衡素数”。这样每次查询可以直接通过下标得到答案，不再需要二分查找。

设上一个平衡素数为 `lastBalancedPrime`，当前找到的平衡素数为 `primes[i]`。对于下面整个区间：

```text
lastBalancedPrime < x <= primes[i]
```

不小于 `x` 的最小平衡素数都是 `primes[i]`，因此可以一次填充：

```cpp
for(int j = lastBalancedPrime + 1;
    j <= primes[i] && j <= MAX_QUERY;
    j++){
    nextBalancedPrime[j] = primes[i];
}
```

填完后更新：

```cpp
lastBalancedPrime = primes[i];
```

例如相邻的两个平衡素数是 `5` 和 `53`，那么 `6...53` 中每个查询值对应的下一个平衡素数都是 `53`。

查询时直接写：

```cpp
if(nextBalancedPrime[N] == N){
    cout << "Yes";
}
else{
    cout << "No" << " " << nextBalancedPrime[N];
}
```

这种方案把查询从 `O(log B)` 降为 `O(1)`，但需要长度约为 `10^7` 的 `int` 数组，额外占用约 `40 MB`。相比之下，`lower_bound` 只保存实际存在的平衡素数，更节省空间。

该数组能否完整填充，同样依赖质数表范围。必须先找到一个不小于 `MAX_QUERY` 的平衡素数，并且还要筛出它后面的相邻质数，才能确认它确实平衡并把查询范围填满。

## 为什么比线性扫描快

查询次数最多为 `10^5`。如果每次都从第一个平衡素数开始扫描，最坏情况下要重复检查大量已经排除的元素。

- 线性扫描：每次查询 `O(B)`；
- `lower_bound`：每次查询 `O(log B)`。

其中 `B` 是预处理得到的平衡素数数量。预处理完成后，大量查询更适合使用二分查找。

## 为什么质数表要超过查询上界

虽然查询值最大为 `10^7`，但题目要求在查询值不是平衡素数时，输出“不小于它的最小平衡素数”。这个答案可能大于 `10^7`。

同时，判断一个数是否为平衡素数还需要知道它前面和后面的相邻质数。因此，质数表不能只开到最大查询值，必须继续覆盖最大查询值之后的候选平衡素数及其后一个质数。

本题代码使用：

```cpp
vector<int> primes = getPrime(10001000);
```

从而覆盖题目上界之后所需的答案范围。

## 复杂度

- 质数和平衡素数只预处理一次。
- `lower_bound` 解法每个查询为 `O(log B)`，只需保存实际存在的平衡素数。
- `nextBalancedPrime` 解法需要额外进行 `O(MAX_QUERY)` 的区间填充，每个查询为 `O(1)`，但需要 `O(MAX_QUERY)` 额外空间。
- 两种解法都需要保存筛法数组和质数表。

## 主要易错点

1. `lower_bound` 只能用于已经有序的区间；本题的平衡素数按照质数表顺序收集，因此保持升序。
2. `lower_bound` 返回第一个不小于目标值的迭代器。要用 `*it` 取得元素值，不能在 `No` 分支重新输出原查询值。
3. 解引用前要确认 `it != neighborprimes.end()`，否则会访问最后一个元素之后的位置。
4. 最大查询值不是预处理的充分上界。题目要求的下一个平衡素数可能超过 `10^7`，而判断它还需要知道后一个质数。
5. 多次查询时不能每次线性扫描整个平衡素数表，否则在 `T = 10^5` 时容易超时。
6. 使用 `nextBalancedPrime` 时，要把两个相邻平衡素数之间的整个查询区间都映射到后一个平衡素数，并保证数组下标不超过 `MAX_QUERY`。

## 对原始代码的整理

整理版保持质数筛选、平衡素数生成和 `lower_bound` 查询结构不变，只做两处安全性与可读性调整：

1. 在解引用 `it` 前判断它不等于 `neighborprimes.end()`；
2. 将两个互斥的条件改成 `if / else if`。

## 复习问题

1. `lower_bound` 返回的是什么？`*it` 又表示什么？
2. 为什么 `neighborprimes` 可以直接使用二分查找？
3. 为什么只筛到 `10^7` 可能无法回答 `N = 10^7` 附近的查询？
4. 为什么判断最大候选平衡素数时，还需要继续筛出它后面的一个素数？
5. `lower_bound` 和 `nextBalancedPrime` 两种方案分别在时间和空间上有什么取舍？

## 文件

- [solution.cpp](solution.cpp)：整理后的解法
- [solution-next-array.cpp](solution-next-array.cpp)：使用 `nextBalancedPrime` 数组进行 `O(1)` 查询的解法
- [original.cpp](original.cpp)：你的原始提交代码
- [sample.in](sample.in) / [sample.out](sample.out)：补充测试样例
