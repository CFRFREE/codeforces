#include <bits/stdc++.h>
#define P 1000000007
#define INF 2147483647
#define INFF 9223372036854775807
#define LL long long
#define N 100005
using namespace std;
int now, sum, a, b, hw, fz;
inline int read()
{
	int X = 0, w = 0;
	char ch = 0;
	while (!isdigit(ch))
	{
		w |= ch == '-';
		ch = getchar();
	}
	while (isdigit(ch))
		X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
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
		sum = 0;
		for (int i = 0; i < n; i++)
			if (st[i] == '0')
				sum++;
		if (sum % 2 == 0 || sum == 1)
			printf("BOB\n");
		else
			printf("ALICE\n");
	}
	return 0;
}