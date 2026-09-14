# 06 大小数

- 总题号：039
- 日期：2026-09-14
- 类型：二分查找、`lower_bound`、`upper_bound`、区间计数
- 状态：AI 辅助完成
- 建议复习：2026-09-15
- 原题：[Sunnywhy](https://sunnywhy.com/camp/3415/model/3591?itemId=3532)

## 题意

给定数组 `a`、`b` 和闭区间 `[L, R]`，统计有多少对下标 `(i, j)` 满足：

```text
L <= a[i] + b[j] <= R
```

每个 `a[i]` 都可以与每个 `b[j]` 配对。

## 固定一个 `a[i]`

如果直接枚举所有 `(i, j)`，需要检查 `N * M` 对元素，时间复杂度为 `O(NM)`。

固定当前值 `a[i]`，原条件为：

```text
L <= a[i] + b[j] <= R
```

同时减去 `a[i]`：

```text
L - a[i] <= b[j] <= R - a[i]
```

问题就变成：在数组 `b` 中统计有多少个元素落在闭区间：

```text
[L - a[i], R - a[i]]
```

将 `b` 排序后，可以用两次标准库二分完成区间计数。数组 `a` 只需要逐个枚举，不需要排序。

## `lower_bound` 和 `upper_bound`

```cpp
lower_bound(first, last, target)
```

返回有序区间中第一个满足 `value >= target` 的位置。

```cpp
upper_bound(first, last, target)
```

返回有序区间中第一个满足 `value > target` 的位置。

对于闭区间 `[low, high]`：

```cpp
auto left = lower_bound(b.begin(), b.end(), low);
auto right = upper_bound(b.begin(), b.end(), high);
```

`left` 指向第一个合法元素，`right` 指向最后一个合法元素之后的位置，因此合法范围是左闭右开的：

```text
[left, right)
```

合法元素数量就是：

```cpp
right - left
```

如果没有合法元素，两个迭代器会指向相同位置，差自动为 `0`，不需要额外设置 `M`、`-1` 等无解标记。

## 四种开闭区间模板

假设有序数组为 `values`，要统计不同开闭区间内的元素数量：

| 要统计的数值范围 | 左迭代器 | 右迭代器 | 合法条件 |
| --- | --- | --- | --- |
| `[L, R]` | `lower_bound(L)` | `upper_bound(R)` | `L <= x <= R` |
| `(L, R]` | `upper_bound(L)` | `upper_bound(R)` | `L < x <= R` |
| `[L, R)` | `lower_bound(L)` | `lower_bound(R)` | `L <= x < R` |
| `(L, R)` | `upper_bound(L)` | `lower_bound(R)` | `L < x < R` |

每一种情况都使用：

```cpp
数量 = 右迭代器 - 左迭代器;
```

记忆方法：

- 左端点包含 `L`，使用 `lower_bound(L)`；排除 `L`，使用 `upper_bound(L)`；
- 右端点包含 `R`，要让结束位置越过所有 `R`，使用 `upper_bound(R)`；排除 `R`，使用 `lower_bound(R)`。

## 为什么不能用 `lower_bound(R)` 统计闭区间

如果 `R` 本身在数组中出现，`lower_bound(R)` 会指向第一个等于 `R` 的元素。把它作为右端点时，所有等于 `R` 的元素都会被排除。

闭区间 `[L, R]` 要包含 `R`，所以右端必须使用：

```cpp
upper_bound(R)
```

它指向第一个严格大于 `R` 的位置，所有等于 `R` 的元素都位于它之前。

## 示例

```text
a = [1, 4]
b = [2, 3, 7]
[L, R] = [4, 7]
```

固定 `a[i] = 1`：

```text
3 <= b[j] <= 6
```

只有 `b[j] = 3`，贡献 `1` 组。

固定 `a[i] = 4`：

```text
0 <= b[j] <= 3
```

`b[j] = 2、3`，贡献 `2` 组。最终答案为 `3`。

## `auto` 和迭代器

`lower_bound`、`upper_bound` 返回的是迭代器，不是元素值或普通整数下标。使用 `auto` 可以让编译器自动推导迭代器类型：

```cpp
auto left = lower_bound(...);
```

如需取得下标，可以写：

```cpp
int index = left - b.begin();
```

本题只需要数量，所以直接计算 `right - left` 即可。

## 类型选择

答案最多可能达到 `N * M`，应使用 `long long`：

```cpp
long long answer = 0;
```

如果元素或区间端点的范围较大，`L - a[i]`、`R - a[i]` 也可能超过 `int`，因此整理版把数组元素和区间端点统一设为 `long long`。

## 复杂度

- 排序 `b`：`O(M log M)`；
- 对每个 `a[i]` 进行两次二分：`O(N log M)`；
- 总时间复杂度：`O(M log M + N log M)`；
- 额外空间复杂度：除输入数组外为 `O(1)`。

## 主要易错点

1. 固定 `a[i]` 后，要先把和的范围转换为 `b[j]` 的范围 `[L-a[i], R-a[i]]`。
2. `lower_bound` 找第一个 `>= target`；`upper_bound` 找第一个 `> target`。
3. 统计闭区间 `[L, R]` 时，左边用 `lower_bound(L)`，右边用 `upper_bound(R)`。
4. 两个迭代器的合法区间为 `[left, right)`，数量直接是 `right - left`。
5. 只有被二分查找的数组 `b` 必须排序，枚举的数组 `a` 不需要排序。
6. 答案可能达到 `N * M`，应使用 `long long`。
7. 手写二分时，左右答案必须对每个 `a[i]` 重新初始化，并处理找不到合法位置的情况；标准库二分可以避免这些状态错误。

## 对原始代码的整理

[original.cpp](original.cpp) 保留你使用 `lower_bound` 和 `upper_bound` 的当前代码。[solution.cpp](solution.cpp) 删除了不必要的 `sort(a)`，保留只排序 `b` 的做法，并使用 `long long` 保存数组值、范围和最终答案，避免中间减法或总数溢出。

## 复习问题

1. 固定 `a[i]` 后，为什么要在 `b` 中查找 `[L-a[i], R-a[i]]`？
2. `lower_bound(target)` 与 `upper_bound(target)` 的区别是什么？
3. 为什么闭区间的右侧必须使用 `upper_bound(R)`？
4. 如果没有合法元素，为什么 `right - left` 会自动得到 `0`？
5. `(L, R)` 为什么对应 `upper_bound(L)` 和 `lower_bound(R)`？

## 文件

- [solution.cpp](solution.cpp)：标准库二分区间计数的整理版代码
- [original.cpp](original.cpp)：你当前提交的代码
- [sample.in](sample.in) / [sample.out](sample.out)：基础区间计数样例
