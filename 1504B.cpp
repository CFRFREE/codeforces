#include <bits/stdc++.h>
#define P 1000000007
#define INF 2147483647
#define INFF 9223372036854775807
#define LL long long
#define N 300005
using namespace std;
int n, sum[N], diff[N], same[N];
string st1, st2;
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
int ok()
{
	int p = 0;
	for (int i = n; i >= 1; i--)
	{
		if (p % 2 == 0)
		{
			i=diff[i];
			if (i % 2 == 1 || sum[i] != i / 2)
				return 0;
			else
			{
				while (diff[i] == i && i >= 1)
					i--;
				sum[i] = i - sum[i];
				i++;
				p++;
			}
		}
		else
		{
			i = same[i];
			if (i % 2 == 1 || sum[i] != i / 2)
				return 0;
			else
			{
				while (same[i] == i && i >= 1)
					i--;
				sum[i] = i - sum[i];
				i++;
				p++;
			}
		}
	}
	return 1;
}
int main()
{
	int T = read();
	while (T--)
	{
		n = read();
		cin >> st1 >> st2;
		st1 = 'a' + st1;
		st2 = 'a' + st2;
		//cout<<st1<<endl<<st2<<endl;
		memset(diff, 0, sizeof(diff));
		memset(sum, 0, sizeof(sum));
		for (int i = 1; i <= n; i++)
			sum[i] = sum[i - 1] + (st1[i] == '1');
		for (int i = 1; i <= n; i++)
			if (st1[i] != st2[i])
				diff[i] = i, same[i] = same[i - 1];
			else
				diff[i] = diff[i - 1], same[i] = i;
		if (ok())
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
