#include <bits/stdc++.h>
#define P 1000000007
#define INF 2147483647
#define INFF 9223372036854775807
#define LL long long
#define N 1005
using namespace std;
int a[N], vis[N];
vector<int>ans;
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
void work()
{
	int n = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	sort(a + 1, a + n + 1);
	if (a[1] < 0)
	{
		printf("NO\n");
		return;
	}
	printf("YES\n");
	int d = a[1];
	for (int i = 2; i <= n ; i++)
		d = __gcd(d, a[i]);
	printf("%d\n", (a[n] - d) / d + 1 + (a[1] == 0));
	if (a[1] == 0)printf("0 ");
	for (int i = d; i <= a[n]; i += d)
		printf("%d ", i);
	printf("\n");
}
int main()
{
	int T = read();
	while (T--)
		work();
	return 0;
}