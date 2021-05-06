#include <bits/stdc++.h>
#define P 1000000007
#define INF 2147483647
#define INFF 9223372036854775807
#define int long long
#define N 205
using namespace std;
int a[N][N];
set<int >s;
vector<int> tot;
map<int, int>M;
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
signed main()
{
	int T = read();
	while (T--)
	{
		int n = read(), m = read();
		s.clear();
		tot.clear();
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				a[i][j] = read();
				tot.push_back(a[i][j]);
			}
		}
		sort(tot.begin(), tot.end());
		for (int i = 0; i < m; i++)
			M[tot[i]]++;
		for (int j = 1; j <= m; j++)
			if (M[a[1][j]])
				M[a[1][j]]--;
			else
				s.insert(j);
		for (int i = 2; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
				if (M[a[i][j]] && s.size())
				{
					int x = *s.begin();
					s.erase(x);
					swap(a[i][j], a[i][x]);
					M[a[i][j]]--;
				}
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
				printf("%lld ", a[i][j]);
			printf("\n");
		}
	}
	return 0;
}