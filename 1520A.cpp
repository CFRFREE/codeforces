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
		map<char, int>M;
		M.clear();
		st += '1';
		for (int i = 0; i < n; i++)
		{
			if (M[st[i]])p = 1;
			M[st[i]] = 1;
			while (st[i + 1] == st[i])i++;
		}
		if (!p)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}