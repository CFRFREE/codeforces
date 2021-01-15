#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 1005
using namespace std;
int T, n, k, a[N];
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
        n = read(), k = read();
        for (int i = 1; i <= n; i++)
            a[i] = read();
        sort(a + 1, a + n + 1);
        if (a[1] + a[2] <= k || a[n] <= k)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}