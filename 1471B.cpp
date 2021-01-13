#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 100005
using namespace std;
int T, n, a[N], b[N], p;
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
        n = read(), p = read();
        LL sum = 0;
        int pos = 0;
        for (int i = 1; i <= n; i++)
        {
            a[i] = read();
            sum += a[i];
            if (a[i] % p != 0&& pos==0)
                pos = i;
        }
        if (pos != 0)
            for (int i = 1; i < pos; i++)
                sum += a[i];
        else
        {
            int mini = INF;
            for (int i = 1; i <= n; i++)
            {
                int s = 0;
                b[i] = a[i];
                while (b[i] % p == 0)
                {
                    s++;
                    b[i] /= p;
                }
                if (s < mini)
                {
                    mini = s;
                    pos = i;
                }
            }
            sum *= (mini+1);
            for (int i = 1; i <= pos-1; i++)
                sum += a[i];
        }
        printf("%lld\n", sum);
    }
    return 0;
}