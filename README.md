# C++ Problem Review

一个以复习为目的的 C++ 做题仓库。每道题保留核心思路、易错点、复杂度和可运行代码。

## 目录结构

每个知识点类别有独立编号，题目再在类别内部从 `01` 开始编号：

```text
topics/
├─ 01-sorting/
│  └─ 01-base-number-sorting/
├─ 02-string/
│  └─ 01-reading-paper/
└─ 03-two-pointers/
   ├─ 01-subarray-sum-length/
   └─ 02-set-difference-iii/
```

## 复习索引

| 总题号 | 分类 | 类内题号 | 题目 | 知识点 | 首次完成 | 状态 | 下次复习 |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 001 | [01 排序](topics/01-sorting/README.md) | 01 | [不同进制数排序](topics/01-sorting/01-base-number-sorting/problem.md) | 进制转换、稳定排序 | 2026-09-04 | AI 辅助完成 | 2026-09-05 |
| 002 | [02 字符串](topics/02-string/README.md) | 01 | [读论文](topics/02-string/01-reading-paper/problem.md) | 连续字符压缩、哈希计数 | 2026-09-04 | AI 辅助完成 | 2026-09-05 |
| 003 | [03 双指针](topics/03-two-pointers/README.md) | 01 | [和为 x 的最短与最长连续子数组](topics/03-two-pointers/01-subarray-sum-length/problem.md) | 同向双指针、滑动窗口 | 2026-09-05 | AI 辅助完成 | 2026-09-06 |
| 004 | [03 双指针](topics/03-two-pointers/README.md) | 02 | [集合求差 III](topics/03-two-pointers/02-set-difference-iii/problem.md) | 相向扫描、集合差集 | 2026-09-05 | AI 辅助完成 | 2026-09-06 |

## 状态说明

- 不会
- 看提示完成
- AI 辅助完成
- 待复习
- 独立完成
- 已熟练

## 推荐复习节奏

完成一道题后，在第 1、7、30 天重新独立实现。复习后更新索引，并把反复出现的问题记录到 [mistakes.md](mistakes.md)。
