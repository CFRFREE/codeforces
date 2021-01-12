#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 200005
using namespace std;
int T, n, pos[N], ans[N], dp[N], pos_x[N];
struct Node {
    int x, y, num;
} a[N];
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
int cmp(Node a, Node b)
{
    if (a.x != b.x)
        return a.x < b.x;
    else
        return a.y < b.y;
}
int main()
{
    T = read();
    while (T--)
    {
        n = read();
        memset(dp, 0, sizeof(dp));
        memset(a, 0, sizeof(a));
        memset(ans, 0, sizeof(ans));
        for (int i = 1; i <= n; i++)
        {
            int x = read(), y = read();
            if (x > y)swap(x, y);
            a[i].x = x;
            a[i].y = y;
            a[i].num = i;
        }
        sort(a + 1, a + n + 1, cmp);
        dp[0] = INF;
        for (int i = 1; i <= n; i++)
            if (a[i].y < dp[i - 1])
            {
                dp[i] = a[i].y;
                pos[i] = a[i].num;
                pos_x[i] = a[i].x;
            }
            else
            {
                dp[i] = dp[i - 1];
                pos[i] = pos[i - 1];
                pos_x[i] = pos_x[i - 1];
            }
        for (int i = n; i >= 1; i--)
            if (a[i].y <= dp[i])
                ans[a[i].num] = -1;
            else
            {
                if (a[i].x > pos_x[i])
                    ans[a[i].num] = pos[i];
                else
                {
                    int P = lower_bound(dp + 1, dp + i + 1, a[i].y, greater<int>()) - dp - 1;
                    if(P<i&&P!=0)
                        ans[a[i].num] = a[P].num;
                    else
                        ans[a[i].num] = -1;
                }
            }
        for (int i = 1; i <= n; i++)
            printf("%d ", ans[i]);
        printf("\n");
    }
    return 0;
}