#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 100005
using namespace std;
int T, n, m;
LL sum_r[N], sum_b[N];
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
        LL max_r = 0;
        LL max_b = 0;
        memset(sum_r, 0, sizeof(sum_r));
        memset(sum_b, 0, sizeof(sum_b));
        for (int i = 1; i <= n; i++)
        {
            sum_r[i] = sum_r[i - 1] + read();
            max_r = max(max_r, sum_r[i]);
        }
        m = read();
        for (int i = 1; i <= m; i++)
        {
            sum_b[i] = sum_b[i - 1] + read();
            max_b = max(max_b, sum_b[i]);
        }
        printf("%lld\n", max_r + max_b);
    }
    return 0;
}