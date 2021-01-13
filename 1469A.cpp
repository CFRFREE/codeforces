#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 100005
using namespace std;
int T;
string st;
stack<int>s;
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
        cin >> st;
        if (st.size() % 2 == 1)
            printf("NO\n");
        else
        {
            if(st[0]==')'||st[st.size()-1]=='(')
                printf("NO\n");
            else
                printf("YES\n");
        }
    }
    return 0;
}