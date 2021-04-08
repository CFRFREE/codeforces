#include <bits/stdc++.h>
#define P 1000000007
#define INF 2147483647
#define INFF 9223372036854775807
#define LL long long
#define N 200005
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
		vector <int> v;
		v.clear();
		for (int i = 0; i < n; i++)
			if (st[i] == '1')v.push_back(i);
		if (st[0] == '0' || st[n - 1] == '0' || v.size() % 2)
			printf("NO\n");
		else
		{
			string ans1 = st, ans2 = st;
			for (int i = 0; i < v.size() / 2; i++)
				ans1[v[i]] = ans2[v[i]] = '(';
			for (int i = v.size() / 2; i < v.size(); i++)
				ans1[v[i]] = ans2[v[i]] = ')';
			int sum1 = 0;
			int sum2 = 0;
			for (int i = 0; i < n; i++)
				if (st[i] == '0')
				{
					if (sum1 <= 0)
					{
						sum1++;
						sum2--;
						ans1[i] = '(';
						ans2[i] = ')';
					}
					else
					{
						sum1--;
						sum2++;
						ans1[i] = ')';
						ans2[i] = '(';
					}
				}
				else
				{
					if (ans1[i] == '(')
						sum1++;
					else sum1--;
					if (ans2[i] == '(')
						sum2++;
					else sum2--;
				}
			printf("YES\n");
			cout << ans1 << endl << ans2 << endl;
		}
	}
	return 0;
}