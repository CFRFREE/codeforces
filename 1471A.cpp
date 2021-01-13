#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 200005
#define int LL
using namespace std;
int T, n, x1, x2, p;
LL mini, maxn;
inline int read()
{
    int X = 0, w = 0;
    char ch = 0;
    while (!isdigit(ch))
    {
        w |= ch == '-';
        ch = getchar();
    }
    while (isdigit(ch))
        X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
    return w ? -X : X;
}
signed main()
{
    T = read();
    while (T--)
    {
        n = read(), p = read();
        x1 = x2 = maxn = mini = 0;
        for (int i = 1; i <= n; i++)
        {
            int x = read();
            x1 += x;
            x2 += x;
            if (x1 % p == 0 || i == n)
            {
                if (i != n)
                    mini += x1 / p;
                else if (x1 % p == 0)
                    mini += x1 / p;
                else
                    mini += x1 / p + 1;

                x1 = 0;
            }
            if (x2 % p != 0 || i == n)
            {
                if (i != n)
                    maxn += x2 / p + 1;
                else if (x2 % p == 0)
                    maxn += x2 / p;
                else
                    maxn += x2 / p + 1;
                x2 = 0;
            }
        }
        printf("%lld %lld\n", mini, maxn);
    }

    return 0;
}