#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 100005
using namespace std;
int T,x;
inline int read()
{
    int X = 0, w = 0;
    char ch = 0;
    while (!isdigit(ch))
    {
        w |= ch == '-';
        ch = getchar();
    }
    while (isdigit(ch)) X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
    return w ? -X : X;
}
int main()
{
    T=read();
    while(T--)
    {
        x=read();
        if(x<=9)
            printf("%d\n",x);
        else if(x<=17)
            printf("%d9\n",x-9);
        else if(x<=24)
            printf("%d89\n",x-17);
        else if(x<=30)
            printf("%d789\n",x-24);
        else if(x<=35)
            printf("%d6789\n",x-30);
        else if(x<=39)
            printf("%d56789\n",x-35);
        else if(x<=42)
            printf("%d456789\n",x-39);
        else if(x<=44)
            printf("%d3456789\n",x-42);
        else if(x<=45)
            printf("%d23456789\n",x-44);
        else 
            printf("-1\n");
    }
    return 0;
}