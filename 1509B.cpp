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
		int p = 0;
		int sum1 = 0;
		int sum2 = 0;
		for (int i = 0; i < n; i++)
		{
			if (st[i] == 'T')
				sum1++;
			else
			{
				sum2++;
				if (sum2 > sum1)p = 1;
			}
		}
		sum1 = sum2 = 0;
		for (int i = n - 1; i > 0; i--)
		{
			if (st[i] == 'T')
				sum1++;
			else
			{
				sum2++;
				if (sum2 > sum1)p = 1;
			}
		}
		if (sum2 * 3 != n || p)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}