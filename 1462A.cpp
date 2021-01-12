#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 100005
using namespace std;
int T, n, cnt;
deque<int> q;
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
        n = read();
        for (int i = 1; i <= n; i++)
        {
            int x = read();
            q.push_back(x);
        }
        cnt = 0;
        while (!q.empty())
        {
            cnt++;
            if (cnt % 2 == 1)
            {
                printf("%d ", q.front());
                q.pop_front();
            }
            else
            {
                printf("%d ", q.back());
                q.pop_back();
            }
        }
        printf("\n");
    }
    return 0;
}