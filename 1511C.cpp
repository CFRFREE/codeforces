#include <bits/stdc++.h>
#define P 1000000007
#define INF 2147483647
#define INFF 9223372036854775807
#define LL long long
#define N 1005
using namespace std;
int Rank[N], pos[N], m;
vector<int>col;
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
	int n = read(), q = read();
	for (int i = 1; i <= n; i++)
	{
		int x = read();
		if (!pos[x])
		{
			pos[x] = i;
			col.push_back(x);
		}
	}
	while (q--)
	{
		int x = read();
		printf("%d ", pos[x]);
		for (int i = 0; i < col.size() ; i++)
		{
			if (pos[col[i]] < pos[x])
				pos[col[i]]++;
		}
		pos[x]=1;
	}
	return 0;
}