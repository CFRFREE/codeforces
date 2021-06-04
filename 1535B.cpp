#include <bits/stdc++.h>
#define P 1000000007
#define INF 2147483647
#define INFF 9223372036854775807
#define LL long long
#define N 100005
using namespace std;
vector<int>ji, ou, a;
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
	int T = read();
	while (T--)
	{
		LL ans = 0;
		ji.clear();
		ou.clear();
		a.clear();
		int n = read();
		for (int i = 1; i <= n; i++)
		{
			int x = read();
			if (x % 2)ji.push_back(x);
			else ou.push_back(x);
		}
		sort(ji.begin(), ji.end());
		sort(ou.begin(), ou.end());
		for (auto x : ou)
			a.push_back(x);
		for (auto x : ji)
			a.push_back(x);
		for (int i = 0; i < n - 1; i++)
			for (int j = i + 1; j < n; j++)
			{
				//printf("%d %d %d\n", i, j, __gcd(a[i], 2 * a[j]));
				if (__gcd(a[i], 2 * a[j]) > 1)ans++;
			}
		printf("%d\n", ans);
	}
	return 0;
}