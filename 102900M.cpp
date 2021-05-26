#include <bits/stdc++.h>
#define P 1000000007
#define INF 2147483647
#define INFF 9223372036854775807
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
	while (isdigit(ch)) X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
	return w ? -X : X;
}
inline void add(int x, int y)
{
	to[++cnt] = y;
	next[cnt] = from[x];
	from[x] = cnt;
}
int main()
{
	int T = read();
	while (T--)
	{
		int n = read(), m = read();
		for (int i = 1; i <= n; i++)
		{
			string st;
			cin >> st;
			if (st.find('/') != st.npos)
				printf("YES\n");
			else
			{
				if (!M[st])M[st] = ++cnt;
				add(0, M[st]);
				del[M[st]]
			}
		}
		for (int i = 1; i <= m; i++)
		{
			string st;
			cin >> st;
			if (st.find('/') != st.npos)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}