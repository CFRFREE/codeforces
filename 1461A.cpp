#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 100005
using namespace std;
int T, n, k;
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
        n = read(), k = read();
        for (int i = 1; i <= n; i++)
            if(i%3==1)printf("a");
                else if(i%3==2)printf("b");
                    else printf("c");
        printf("\n");
    }
    return 0;
}