#include <bits/stdc++.h>
#define P 998244353
#define INF 2147483647
#define INFF 9223372036854775807
#define int unsigned long long
#define N 1000005
using namespace std;
int s[N], cnt[N];
int ans;
vector<int>gift[N];
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
int qpow(int x, int k)
{
	int tep = 1;
	while (k)
	{
		if (k % 2)tep =  (1ll * tep * x) % P;
		x = (1ll * x * x) % P;
		k >>= 1;
	}
	return tep % P;
}
int niyuan(int x)
{
	return qpow(x, P - 2) % P;
}
signed main()
{
	int n = read();
	for (int i = 1; i <= n; i++)
	{
		s[i] = read(); //每个人礼物的数量
		for (int j = 1; j <= s[i]; j++)
		{
			int x = read();
			gift[i].push_back(x);
			cnt[x]++;//礼物x的需要的人数
		}
	}
	for (int i = 1; i <= n; i++)
	{
		int tep = 0;
		for (int j = 0; j < s[i]; j++)
			tep = (tep + cnt[gift[i][j]] * niyuan(n) % P) % P;
		ans = (ans + (tep % P) * (niyuan(s[i]) % P)) % P;
	}
	ans = (ans % P) * (niyuan(n) % P) % P;
	printf("%I64d\n", ans);
	return 0;
}