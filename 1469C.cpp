#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 200005
using namespace std;
int T, n, k, a[N], dp[N], pos;
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
int main()
{
    T = read();
    while (T--)
    {
        int maxn = 0;
        n = read(), k = read();
        memset(a, 0, sizeof(a));
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++)
        {
            a[i] = read();
            if (a[i] > maxn)
            {
                maxn = a[i];
                pos = i;
            }
        }
        dp[pos] = maxn;
        for (int i = pos - 1; i >= 1; i--)
        {
            if (dp[i + 1] + 1 - k - a[i] > k - 1)
            {
                printf("NO\n");
                goto free;
            }
            else
                dp[i] = max(dp[i + 1] + 1 - k, 0);
        }
        for (int i = pos + 1; i <= n; i++)
            if (dp[i - 1] + 1 - k - a[i] > k - 1)
            {
                printf("NO\n");
                goto free;
            }
            else
                dp[i] = max(dp[i - 1] + 1 - k, 0);
        printf("YES\n");
        free:;
    }
    return 0;
}
