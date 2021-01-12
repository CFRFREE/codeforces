#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 200005
using namespace std;
int T, n;
LL ans;
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
        n = read();
        ans = 0;
        vector<LL> cnt(n + 1);
        for (register int i = 1; i <= n; i++)
        {
            int x = read();
            cnt[x]++;
        }
        ans = 0;
        if (n >= 3)
        {
            for (register int i = 1; i <= n; i++)
                ans += cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / 6;
            for (register int i = 1; i <= n - 1; i++)
                ans += cnt[i] * (cnt[i] - 1) * cnt[i + 1] / 2;
            for (register int i = 1; i <= n - 2; i++)
                ans += cnt[i] * cnt[i + 1] * cnt[i + 2];
            for (register int i = 1; i <= n - 2; i++)
                ans += cnt[i] * cnt[i + 2] * (cnt[i + 2] - 1) / 2;
            for (register int i = 1; i <= n - 1; i++)
                ans += cnt[i] * cnt[i + 1] * (cnt[i + 1] - 1) / 2;
            for (register int i = 1; i <= n - 2; i++)
                ans += cnt[i] * (cnt[i] - 1) * cnt[i + 2] / 2;
        }
        printf("%lld\n", ans);
    }
    return 0;
}