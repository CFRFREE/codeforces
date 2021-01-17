#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 100005
using namespace std;
vector<int> v;
int T, n, a[N], d[N], cnt;
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
        memset(d, 0, sizeof(d));
        v.clear();
        ans = cnt = 0;
        for (int i = 1; i <= n; i++)
            a[i] = read();
        for (int i = 1; i < n; i++)
        {
            int x = read(), y = read();
            d[x]++, d[y]++;
        }
        for (int i = 1; i <= n; i++)
        {
            ans += a[i];
            for (int j = 1; j < d[i]; j++)
                v.push_back(a[i]);
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        // for (int i = 0; i < v.size(); ++i)
        //     printf("%d ", v[i]);
        // printf("\n");
        printf("%lld ", ans);
        for (int i = 2; i < n; i++)
        {
            ans += v[cnt++];
            printf("%lld ", ans);
        }
        printf("\n");
    }
    return 0;
}