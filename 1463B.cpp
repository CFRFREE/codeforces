#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 100005
#define int LL
using namespace std;
int T,n,a[N],sum_odd,sum_even;
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
signed main()
{
    T = read();
    while (T--)
    {
        n = read();
        sum_odd = sum_even = 0;
        for (int i = 1; i <= n; i++)
            a[i] = read();
        for (int i = 1; i <= n; i++)
            if (i % 2)
                sum_odd += a[i];
            else
                sum_even += a[i];
        if (sum_odd > sum_even)
        {
            for (int i = 1; i <= n; i++)
                if (i % 2)
                    printf("%lld ", a[i]);
                else
                    printf("1 ");
        }
        else
        {
            for (int i = 1; i <= n; i++)
                if (i % 2 == 0)
                    printf("%lld ", a[i]);
                else
                    printf("1 ");
        }
        printf("\n");
    }
    return 0;
}