#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 100005
using namespace std;
int T, n, m, max_l[N], max_r[N], min_l[N], min_r[N], a[N];
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
        n = read(), m = read();
        max_l[0] = max_r[0] = 0;
        min_l[0] = min_r[0] = INF;
        cin >> st;
        for (int i = 0; i < n; i++)
            if (st[i] == '-')
                a[i + 1] = a[i] - 1;
            else
                a[i + 1] = a[i] + 1;
        // for(int i = 1; i <= n; i++)
        //     printf("%d ",a[i]);
        for (int i = 1; i <= n; i++)
        {
            max_l[i] = max(max_l[i - 1], a[i]);
            min_l[i] = min(min_l[i - 1], a[i]);
        }
        for (int i = n; i >= 1; i--)
        {
            max_r[i] = max(max_r[i - 1], a[i]);
            min_r[i] = min(min_r[i - 1], a[i]);
        }
        // for (int i = 1; i <= n; i++)
        //     printf("%d %d\n", max_l[i], min_l[i]);
        while (m--)
        {
            int L = read(), R = read();
            L--;
            int max1 = max_l[L], min1 = min_l[L];
            int max2 = max_r[R] + a[L], min2 = min_r[R] + a[L];
            printf("%d\n", max(max1, max2) - min(min1, min2));
        }
    }

    return 0;
}