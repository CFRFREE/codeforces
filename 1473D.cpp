#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 100005
using namespace std;
int T, n, m, a[N], st_max[N][21], st_min[N][21];
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
inline int search_max(int x, int y)
{
    if (y == x)
        return a[x - 1];
    int k = log(y - x + 1) / log(2);
    return max(st_max[x][k], st_max[y - (1 << k) + 1][k]);
}
inline int search_min(int x, int y)
{
    if (y == x)
        return a[x - 1];
    int k = log(y - x + 1) / log(2);
    return min(st_min[x][k], st_min[y - (1 << k) + 1][k]);
}
int main()
{
    T = read();
    while (T--)
    {
        n = read(), m = read();
        cin >> st;
        memset(a, 0, sizeof(a));
        memset(st_max, 0, sizeof(st_max));
        memset(st_min, 0, sizeof(st_min));
        for (int i = 2; i <= st.size() + 1; i++)
        {
            if (st[i - 2] == '-')
                a[i] = a[i - 1] - 1;
            else
                a[i] = a[i - 1] + 1;
        }
        n++;
        for (int i = 1; i <= n; i++)
            st_max[i][0] = st_min[i][0] = a[i];
        for (int j = 1; j <= 20; j++)
            for (int i = 1; i + (1 << j) - 1 <= n; i++)
                st_max[i][j] = max(st_max[i][j - 1], st_max[i + (1 << j - 1)][j - 1]);
        for (int j = 1; j <= 20; j++)
            for (int i = 1; i + (1 << j) - 1 <= n; i++)
                st_min[i][j] = min(st_min[i][j - 1], st_min[i + (1 << j - 1)][j - 1]);
        while (m--)
        {
            int L = read(), R = read();
            L++, R++;
            if (R == n)
            {
                int max1 = search_max(1, L - 1), min1 = search_min(1, L - 1);
                printf("%d\n", max1 - min1 + 1);
            }
            else if (L == 2)
            {
                int max2 = search_max(R+1, n), min2 = search_min(R+1, n);
                printf("%d\n", max2 - min2 + 1);
            }
            else
            {
                int max1 = search_max(1, L - 1), min1 = search_min(1, L - 1);
                int max2 = search_max(R+1, n)+a[L-2], min2 = search_min(R+1, n)+a[L-2];
                if(min1<max2||min2<max1)
                    printf("%d\n", max1 + max2 - min1 - min2 + 2);
                else
                	printf("%d\n", max(max1, max2) - min(min1, min2) + 1);
            }
        }
    }
    return 0;
}
