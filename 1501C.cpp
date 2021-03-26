#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 2000005
using namespace std;
int a[N],cnt;
pair<int,int>M[5000005];
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
	int n = read();
	for (register int i = 1; i <= n; i++)
		a[i] = read();
	for (register int i = 1; i <= n - 1; i++)
		for (register int j = i + 1; j <= n; j++)
		{
			int x = a[i] + a[j];
			if (M[x].first)
			{
				int ans3 = M[x].first;
				int ans4 = M[x].second;
				if (ans4 != i && ans4 != j && ans3 != i && ans3 != j)
				{
					printf("YES\n%d %d %d %d\n", i, j, M[x].first, M[x].second);
					return 0;
				}
			}
			else
				M[x] = make_pair(i, j);
		}
	printf("NO\n");
	return 0;
}