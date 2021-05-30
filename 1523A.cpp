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
		int n = read(), m = read();
		string st, str;
		cin >> st;
		str = st;
		while (m--)
		{
			int p = 0;
			for (int i = 0; i < n; i++)
			{
				if (st[i] == '0')
				{
					if (i == 0)
					{
						if (st[1] == '1')
						{
							p = 1;
							str[i] = '1';
						}
						else
							str[i] = '0';
					}
					else if (i == n - 1)
					{
						if (st[i - 1] == '1')
						{
							p = 1;
							str[i] = '1';
						}
						else
							str[i] = '0';
					}
					else if (st[i - 1] == '1' && st[i + 1] == '0' || st[i - 1] == '0' && st[i + 1] == '1')
					{
						str[i] = '1';
						p = 1;
					}
					else
						str[i] = '0';
				}
				else
					str[i] = '1';
			}
			if (!p)
			{
				cout << str << endl;
				goto qaq;
			}
			st = str;
		}
		cout << st << endl;
qaq:;
	}
	return 0;
}