#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 100005
using namespace std;
int T, flag;
string st;
map<pair<int, int>, int> M;
struct Node
{
    int x, y;
} pos, now;
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
int ok(int x, int y)
{
    now.x = now.y = 0;
    for (int i = 0; i < st.size(); i++)
    {
        if (st[i] == 'L')
        {
            now.x--;
            if (now.x == x && now.y == y)
                now.x++;
        }
        else if (st[i] == 'R')
        {
            now.x++;
            if (now.x == x && now.y == y)
                now.x--;
        }
        else if (st[i] == 'U')
        {
            now.y++;
            if (now.x == x && now.y == y)
                now.y--;
        }
        else
        {
            now.y--;
            if (now.x == x && now.y == y)
                now.y++;
        }
    }
    if(now.x==0 && now.y==0)
        return 1;
    else
        return 0;
}
int main()
{
    T = read();
    while (T--)
    {
        cin >> st;
        M.clear();
        flag = pos.x = pos.y = 0;
        for (int i = 0; i < st.size(); i++)
        {
            if (st[i] == 'L')
                pos.x--;
            else if (st[i] == 'R')
                pos.x++;
            else if (st[i] == 'U')
                pos.y++;
            else
                pos.y--;
            pair<int, int> P(pos.x, pos.y);
            if (M.find(P) == M.end())
                if (ok(P.first, P.second))
                {
                    printf("%d %d\n", P.first, P.second);
                    flag = 1;
                    break;
                }
        }
        if (!flag)
            printf("0 0\n");
    }
    return 0;
}