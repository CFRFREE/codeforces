#include <bits/stdc++.h>
#define INF 2147483647
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
	int T;
	T = read();
	while (T--)
	{
		int n = read(), is_odd = 0, is_even = 0;
		for (int i = 1; i <= n; i++)
		{
			int x = read();
			if (x % 2 == 1)is_odd++;
			else is_even++;
		}
		if (is_odd == 0 && is_even % 2 == 1)
			printf("NO\n");
		else 
		{
			if ((is_even * 2 + is_odd) % 2 == 1)
				printf("NO\n");
			else if (is_odd % 2 == 0)
				printf("YES\n");
		}
	}
	return 0;
}