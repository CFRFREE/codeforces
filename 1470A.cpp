#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 300005
using namespace std;
int T, n, m, a[N], v[N];
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
int cmp(int x, int y)
{
    return x > y;
}
int main()
{
    T = read();
    while (T--)
    {
        n = read(), m = read();
        for (int i = 1; i <= n; i++)
            a[i] = read();
        sort(a + 1, a + n + 1, cmp);
        for (int i = 1; i <= m; i++)
            v[i] = read();
        int pos = 1;
        LL ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (v[a[i]] > v[pos])
            {
                ans += v[pos];
                pos++;
            }
            else
                ans += v[a[i]];
        }
        printf("%lld\n", ans);
    }
    return 0;
}