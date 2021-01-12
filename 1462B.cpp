#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 100005
using namespace std;
int T,n;
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
        n = read();
        cin >> st;
        //cout<<st.substr(0,4)<<endl;
        if (st.substr(0, 4) == "2020" || st.substr(n - 4, 4) == "2020")
            printf("YES\n");
        else
        {
            if (st[0] == '2' && st.substr(n - 3, 3) == "020" ||
                st.substr(0, 2) == "20" && st.substr(n - 2, 4) == "20" ||
                st.substr(0, 3) == "202" && st[n - 1] == '0')
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}