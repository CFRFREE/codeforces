#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 100005
using namespace std;
int T, n, a[N], vis[N], ans;
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
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; i++)
            a[i] = read();
        for (int i = 1; i <= n - 1; i++)
            for (int j = i + 1; j <= n; j++)
                if (!vis[a[j] - a[i]])
                {
                    ans++;
                    vis[a[j] - a[i]] = 1;
                }
        printf("%d\n", ans);
    }
    return 0;
}