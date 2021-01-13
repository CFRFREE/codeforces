#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 100005
using namespace std;
int a1, a2, a3, a4, a5, c1, c2, c3, T;
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
        c1 = read(), c2 = read(), c3 = read();
        a1 = read(), a2 = read(), a3 = read(), a4 = read(), a5 = read();
        c1 -= a1, c2 -= a2, c3 -= a3;
        if (c1 < 0 || c2 < 0 || c3 < 0)
            printf("NO\n");
        else
        {
            if (a4 - c1 >= 0)
                a4 -= c1;
            else
                a4 = 0;
            if (a5 - c2 >= 0)
                a5 -= c2;
            else
                a5 = 0;
            if (a4 + a5 > c3)
                printf("NO\n");
            else
                printf("YES\n");
        }
    }
    return 0;
}