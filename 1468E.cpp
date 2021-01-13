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
    int T;
    T = read();
    while (T--)
    {
        int a[4];
        for (int i = 0; i < 4; i++)
            a[i] = read();
        sort(a, a + 4);
        printf("%d\n", a[0] * a[2]);
    }
    return 0;
}