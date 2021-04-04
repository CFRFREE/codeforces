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
		string st;
		cin >> st;
		int n = st.size();
		int p = 0;
		string str;
		for (int i = 0; i < n ; i++)
			if (st[i] != 'a')p = 1;
		if (!p)
			printf("NO\n");
		else
		{
			printf("YES\n");
			for (int i = 0; i < st.size(); i++)
				if (st[i] != 'a')
				{
					if (i > n / 2 - 1)
						st = 'a' + st;
					else
						st.insert(n - i, "a");
					break;
				}
			cout << st << endl;
		}
	}
	return 0;
}