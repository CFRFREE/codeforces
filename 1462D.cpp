#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 100005
using namespace std;
int T, n, a[N], s;
vector<int> d;
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
int ok(int sum)
{
    int sum_now = 0;
    for (int i = 1; i <= n; i++)
    {
        sum_now += a[i];
        if (sum_now == sum)
            sum_now = 0;
        else if (sum_now > sum)
            return 0;
    }
    return 1;
}
int main()
{
    T = read();
    while (T--)
    {
        n = read();
        memset(a, 0, sizeof(a));
        s = 0;
        d.clear();
        for (int i = 1; i <= n; i++)
        {
            a[i] = read();
            s += a[i];
        }
        int x = 1;
        for (int i = 1; i <= s; i++)
            if (s % i == 0)
                d.push_back(i);
        for (int i = 0; i < d.size(); i++)
            if (ok(d[i]))
            {
                printf("%d\n", n - (s / d[i]));
                break;
            }
    }
    return 0;
}