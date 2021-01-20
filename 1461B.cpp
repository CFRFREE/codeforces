#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 505
using namespace std;
int T, n, m, sum[N][N];
string st[N];
vector<pair<int,int> > v;
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
void work(int x, int y)
{
    for (int i = 1; i <= n - x + 1; i++)
    {
        if (sum[x + i - 1][y + i - 1] - sum[x + i - 1][y - i] == i * 2 - 1)
            ans++;
        else
            break;
    }
}
int main()
{
    T = read();
    while (T--)
    {
        n = read(), m = read();
        memset(sum, 0, sizeof(sum));
        v.clear();
        ans = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> st[i];
            st[i] = '.' + st[i];
            for (int j = 1; j <= m; j++)
                if (st[i][j] == '*')
                {
                    sum[i][j] = sum[i][j - 1] + 1;
                    v.push_back(make_pair(i, j));
                }
                else
                    sum[i][j] = sum[i][j - 1];
        }
        for (int i = 0; i < v.size(); i++)
            work(v[i].first, v[i].second);
        printf("%lld\n", ans);
    }
    return 0;
}