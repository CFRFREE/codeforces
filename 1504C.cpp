#include <bits/stdc++.h>
#define P 1000000007
#define INF 2147483647
#define INFF 9223372036854775807
#define LL long long
#define N 200005
using namespace std;
int a[N];
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
		int sum = 0;
		string st, ans1, ans2;
		memset(a,0,sizeof(a));
		cin >> st;
		for (int i = 1; i <= n; i++)
			if (st[i - 1] == '0')
				a[i] = 0;
			else
				a[i] = 1, sum++;
		if (n % 2 || a[1]*a[n] == 0)
			printf("NO\n");
		else
		{
			ans1 = ans2 = '(';
			int sum1 = 1;
			int sum2 = 1;
			int p = 0;
			for (int i = 2; i <= n; i++)
			{
				if (a[i] && a[i + 1])
				{
					ans1 += "()";
					ans2 += "()";
					i = i + 1;
				}
				else if (a[i])
				{
					if (sum1 > 0 && sum2 > 0)
					{
						sum1--;
						sum2--;
						ans1 += ')';
						ans2 += ')';
					}
					else
					{
						sum1++;
						sum2++;
						ans1 += '(';
						ans2 += '(';
					}
				}
				else
				{
					if (sum1 <= 0 && sum2 <= 0)
					{
						p = 1;
						break;
					}
					else if (sum1 == 0)
					{
						sum1++;
						sum2--;
						ans1 += '(';
						ans2 += ')';
					}
					else
					{
						sum1--;
						sum2++;
						ans1 += ')';
						ans2 += '(';
					}
				}
			}
			if (p || sum1 != 0 || sum2 != 0)
				printf("NO\n");
			else
			{
				printf("YES\n");
				cout << ans1 << endl << ans2 << endl;
			}
		}
	}
	return 0;
}