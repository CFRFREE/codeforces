#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 100005
using namespace std;
int n, id_now, max_now, st[N][22], id[N][22], a[N];
queue<int>q;
vector<int>v;
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
void search(int x, int y)
{
	int k = log(y - x + 1) / log(2);
	if (st[x][k] > st[y - (1 << k) + 1][k])
	{
		max_now = st[x][k];
		id_now = id[x][k];
	}
	else
	{
		max_now = st[y - (1 << k) + 1][k];
		id_now = id[y - (1 << k) + 1][k];
	}
	//return max(st[x][k],st[y-(1<<k)+1][k]);
}
int main()
{
	int T = read();
	while (T--)
	{
		n = read();
		memset(st, 0, sizeof(st));
		memset(id, 0, sizeof(id));
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= n; i++)
		{
			a[i] = st[i][0] = read();
			id[i][0] = i;
		}
		for (int j = 1; j <= 20; j++)
			for (int i = 1; i + (1 << j) - 1 <= n; i++)
			{
				if (st[i][j - 1] > st[i + (1 << j - 1)][j - 1])
				{
					st[i][j] = st[i][j - 1];
					id[i][j] = id[i][j - 1];
				}
				else
				{
					st[i][j] = st[i + (1 << j - 1)][j - 1];
					id[i][j] = id[i + (1 << j - 1)][j - 1];
				}
				//st[i][j]=max(st[i][j-1],st[i+(1<<j-1)][j-1]);
			}
		int pos = n;
		while (pos != 0)
		{
			search(1, pos);
			//printf("%d %d\n", max_now,id_now);
			for (int i = id_now; i <= pos; i++)
				v.push_back(a[i]);
			pos = id_now - 1;
		}
		for (int i = 0; i < v.size(); i++)
			printf("%d ", v[i]);
		v.clear();
		printf("\n");
	}
	return 0;
}