#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 200005
using namespace std;
int T, n, vis[N], ans;
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
        for (int i = 1; i <= n; i++)
        {
            int x = read();
            if (vis[x] == 1)
            {
                if (!vis[x + 1])
                {
                    vis[x + 1] = 1;
                    ans++;
                }
            }
            else
            {
                vis[x] = 1;
                ans++;
            }
        }
        printf("%d\n", ans);
        ans = 0;
        memset(vis, 0, sizeof(vis));
    }
    return 0;
}