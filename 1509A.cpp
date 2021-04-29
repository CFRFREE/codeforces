#include <bits/stdc++.h>
#define P 1000000007
#define INF 2147483647
#define INFF 9223372036854775807
#define LL long long
#define N 100005
using namespace std;
vector<int>a, b;
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
		a.clear();
		b.clear();
		for (int i = 1; i <= n; i++)
		{
			int x = read();
			if (x & 1)
				a.push_back(x);
			else
				b.push_back(x);
		}
		for (auto x :  a)
			printf("%d ", x);
		for (auto x : b)
			printf("%d ", x);
		printf("\n");
	}
	return 0;
}