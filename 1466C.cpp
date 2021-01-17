#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 100005
using namespace std;
int T, n, vis[N];
string st;
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
        cin >> st;
        n = st.size();
        int ans = 0;
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i < n; i++)
        {
            int use = 0;
            if (st[i] == st[i - 1] && !vis[i - 1])
                use = 1;
            if (i >= 2 && st[i] == st[i - 2] && !vis[i - 2])
                use = 1;
            if (use)
            {
                vis[i] = 1;
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}