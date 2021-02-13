#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 100005
using namespace std;
int n, k, q, a[N], b[N], sum[N];
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
	n = read(), q = read(), k = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	for (int i = 2; i <= n - 1; i++)
		b[i] = a[i + 1] - a[i - 1] - 2;
	// for(int i = 1; i<= n; i++)
	// 	printf("%d ", b[i]);
	for (int i = 2; i <= n-1; i++)
		sum[i] = sum[i - 1] + b[i];
	while(q--)
	{
		int l=read(),r=read();
		if(l==r)
			printf("%d\n", k-1);
		else
			printf("%d\n", sum[r-1]-sum[l]+a[l+1]-3+k-a[r-1]);
	}
	return 0;
}