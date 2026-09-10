#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 101;

int a[MAXN][MAXN];
int memo[MAXN][MAXN];

int F(int i, int j, int n)
{
   if (i == n)
   {
       return a[i][j];
   }

   // 已经计算过，直接返回
   if (memo[i][j] != -1)
   {
       return memo[i][j];
   }

   memo[i][j] =
       a[i][j] +
       max(F(i + 1, j, n),
           F(i + 1, j + 1, n));

   return memo[i][j];
}

int main()
{
   int n;
   cin >> n;

   for (int i = 1; i <= n; i++)
   {
       for (int j = 1; j <= i; j++)
       {
           cin >> a[i][j];
       }
   }

   memset(memo, -1, sizeof(memo));

   cout << F(1, 1, n) << '\n';

   return 0;
}
