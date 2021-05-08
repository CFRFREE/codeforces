#include <bits/stdc++.h>
#define P 1000000007
#define INF 2147483647
#define INFF 9223372036854775807
#define LL long long
#define N 505
using namespace std;
int a[N][N];
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
void work(int x, int y, int col, int cnt)
{
	//printf("%d %d %d %d \n", x, y, col, cnt);
	if (cnt == col)return;
	if (!a[x][y - 1] && y - 1 >= 1)
	{
		a[x][y - 1] = col;
		work(x, y - 1, col, cnt + 1);
	}
	else
	{
		a[x + 1][y] = col;
		work(x + 1, y, col, cnt + 1);
	}
}
int main()
{
	int n = read();
	for (int i = 1; i <= n; i++)
	{
		a[i][i] = read();
		work(i, i, a[i][i], 1);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	return 0;
}