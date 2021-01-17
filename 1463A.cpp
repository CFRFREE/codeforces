#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 100005
using namespace std;
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
    int T = read();
    while (T--)
    {
        int a = read(), b = read(), c = read();
        if ((a + b + c) % 9)
            printf("NO\n");
        else
        {
            if (min(min(a, b), c) < (a + b + c) / 9)
                printf("NO\n");
            else
                printf("YES\n");
        }
    }
    return 0;
}