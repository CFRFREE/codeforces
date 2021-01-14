#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 500005
using namespace std;
int q, a[N], cnt, vis[N], now;
multimap<int, int, greater<int> > M;
multimap<int, int>::iterator it;
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
    q = read();
    int L = 0;
    vis[0] = 1;
    while (q--)
    {
        int opt = read();
        if (opt == 1)
        {
            int x = read();
            a[++cnt] = x;
            M.insert(make_pair(x, cnt));
        }
        else if (opt == 2)
        {
            while (vis[now])
                now++;
            vis[now] = 1;
            printf("%d\n", now);
            M.erase(a[now]);
        }
        else
        {
            it = M.begin();
            vis[it->second]=1;
            printf("%d\n", it->second);
            vis[it->second] = 1;
            M.erase(it);
        }
    }
    return 0;
}