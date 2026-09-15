# 05 数论

整理最大公约数、素数、筛法、质因数分解等整数相关算法。

| 类内题号 | 题目 | 核心知识点 |
| --- | --- | --- |
| 01 | [质因子分解](01-prime-factorization/problem.md) | 埃氏筛、试除法、剩余质因子 |
| 02 | [约数个数](02-divisor-count/problem.md) | 质因数指数、约数个数公式、根号优化 |
| 03 | [约数和](03-divisor-sum/problem.md) | 质因数指数、幂次和、乘法原理 |
| 04 | [熊熊的零尾谜题](04-trailing-zeros-factorial-quotient/problem.md) | 阶乘质因数计数、末尾零、区间乘积 |
| 05 | [最大公约数](05-greatest-common-divisor/problem.md) | 辗转相除法、递归、终止条件 |

## 常用模板

| 模板 | 核心写法 | 入口 |
| --- | --- | --- |
| 组合数 `C(n,m)` | `total = total * (n - m + i) / i` | [combination.cpp](templates/combination.cpp) |
| 快速幂 | 底数每轮平方；指数为奇数时将当前底数乘入答案 | [fast-power.cpp](templates/fast-power.cpp) |

原始版本与完整说明见 [数论常用模板](templates/README.md)。
