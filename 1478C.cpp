#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 200005
using namespace std;
int n;
LL a[N];
set<LL>S;
inline LL read()
{
	LL X = 0, w = 0;
	char ch = 0;
	while (!isdigit(ch))
	{
		w |= ch == '-';
		ch = getchar();
	}
	while (isdigit(ch)) X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
	return w ? -X : X;
}
int cmp(LL x, LL y)
{
	return x > y;
}
int ok()
{
	n = read();
	n *= 2;
	for (int i = 1; i <= n; i++)
		a[i] = read();
	for (int i = 1; i <= n; i++)
		if (a[i] % 2 == 1)
			return 0;
	sort(a + 1, a + n + 1, cmp);

	n /= 2;
	for (int i = 1; i <= n; i++)
		if (a[i*2] != a[i * 2 - 1])
			return 0;
	for (int i = 1; i <= n; i++)
		a[i] = (a[i << 1]) >> 1;
	S.clear();
	LL sum = 0;
	for (int i = 1; i <= n; i++)
	{
		LL x = (a[i] - sum) / (n - i + 1);
		if ((a[i] - sum) % (n - i + 1))
			return 0;
		sum += x;
		if (S.find(x) != S.end() || x <= 0)
			return 0;
		S.insert(x);
	}
	return 1;
}
int main()
{
	int T = read();
	while (T--)
	{
		if (ok())
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}