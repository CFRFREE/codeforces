#include <bits/stdc++.h>
#define P 1000000007
#define INF 2147483647
#define INFF 9223372036854775807
#define LL long long
#define N 100005
using namespace std;
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
		int n = read();
		string st;
		cin >> st;
		string st1 = st;
		string st2 = st;
		int sum1 = 0;
		int sum0 = 0;
		for (auto ch : st)
			if (ch == '0')
				sum0++;
			else
				sum1++;
		if (st[0] == '0' || st[n - 1] == '0' || n % 2 || sum1 % 2)
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		int cnt1 = 0;
		int cnt0 = 0;
		for (int i = 0; i < n; i++)
		{
			if (st[i] == '1')
			{
				cnt1++;
				if (cnt1 <= sum1 / 2)
					st1[i] = st2[i] = '(';
				else
					st1[i] = st2[i] = ')';
			}
			else
			{
				cnt0++;
				if (cnt0 % 2)
				{
					st1[i] = ')';
					st2[i] = '(';
				}
				else
				{
					st2[i] = ')';
					st1[i] = '(';
				}
			}
		}
		cout << st1 << endl << st2 << endl;
	}
	return 0;
}