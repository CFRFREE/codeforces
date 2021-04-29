#include <bits/stdc++.h>
#define P 1000000007
#define INF 2147483647
#define INFF 9223372036854775807
#define int long long
using namespace std;
int a[2005], maxn, pos_min, pos_max;
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
int diff(vector<int>& vec)
{
	int len = vec.size();

	int sum = 0;
	for (int i = 0; i < len; ++i) {
		sum += vec[i];
	}

	vector<vector<int>> dp;
	for (int i = 0; i <= len; i++) {
		vector<int>tmp;
		for (int j = 0; j <= sum / 2; ++j) {
			tmp.push_back(0);
		}
		dp.push_back(tmp);
	}

	for (int i = 1; i <= len; ++i) {
		for (int j = 1; j <= sum / 2; ++j) {
			if (j >= vec[i - 1])dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - vec[i - 1]] + vec[i - 1]);
			else dp[i][j] = dp[i - 1][j];
		}
	}

	return sum - 2 * dp[len][sum / 2];
}

signed main()
{
	vector<int> vec;
	int n = read();
	int pos = 0;
	int mini = INF;
	for (int i = 1; i <= n; i++)
	{
		int x = read();
		a[i] = x;
		vec.push_back(x);
		if (x < mini)
		{
			mini = x;
			pos_min = i;
		}
		if (x > maxn)
		{
			maxn = x;
			pos_max = i;
		}
	}
	if (diff(vec) != 0)
	{
		printf("0\n");
		return 0;
	}
	vec.clear();
	for (int i = 1; i <= n; i++)
		if (a[i] != mini || i != pos_min)
			vec.push_back(a[i]);
	if (diff(vec) != 0)
	{
		printf("1\n%lld\n", pos_min);
		return 0;
	}
	vec.clear();
	for (int i = 1; i <= n; i++)
		if (a[i] != maxn || i != pos_max)
			vec.push_back(a[i]);
	if (diff(vec) != 0)
	{
		printf("1\n%lld\n", pos_max);
		return 0;
	}
	while (1)
	{
		srand(time(NULL));
		int pos_rand = rand() % n;
		vec.clear();
		for (int i = 1; i <= n; i++)
			if (i != pos_rand)vec.push_back(a[i]);
		if (diff(vec) != 0)
		{
			printf("1\n%lld\n", pos_rand);
			return 0;
		}
	}
	return 0;
}