#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 100005
using namespace std;
int n, U, D, R, L;
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
int check()
{
	if (U + R + D + L == 0)
		return 1;
	if ((U == n || D == n) && L * R == 0)
		return 0;
	if ((R == n || L == n) && U * D == 0)
		return 0;
	if ((U == n && D == n) && (L < 2 || R < 2))
		return 0;
	if ((L == n && R == n) && (U < 2 || D < 2))
		return 0;
	if ((U == n - 1 || D == n - 1) && L + R == 0)
		return 0;
	if ((L == n - 1 || R == n - 1) && U + D == 0)
		return 0;
	if ((U == n - 1 && D == n - 1) && L + R <= 1)
		return 0;
	if ((L == n - 1 && R == n - 1) && U + D <= 1)
		return 0;
	if ((U+D==2*n-1) && (L <= 1 && R <= 1))
		return 0;
	if ((L+R==2*n-1) && (U <= 1 && D <= 1))
		return 0;
	return 1;
}
void work()
{
	for(int i=0;i<=15;i++)
	{
		int u=U,r=R,d=D,l=L;
		if(i&1)
		{
			u--;
			l--;
		}
		if(i&2)
		{
			u--;
			r--;
		}
		if(i&4)
		{
			r--;
			d--;
		}
		if(i&8)
		{
			d--;
			l--;
		}
		if(u>=0&&r>=0&&d>=0&&l>=0&&u<=n-2&&r<=n-2&&l<=n-2&&d<=n-2)
		{
			printf("YES\n");
			return;
		}
	}
	printf("NO\n");
}
int main()
{
	int T = read();
	while (T--)
	{
		n = read(), U = read(), R = read(), D = read(), L = read();
		// if (check())
		// 	printf("YES\n");
		// else
		// 	printf("NO\n");
		work();
	}
	return 0;
}
