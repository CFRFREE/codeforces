#include <bits/stdc++.h>
#define P 1000000007
#define INF 2147483647
#define INFF 9223372036854775807
#define LL long long
#define N 100005
using namespace std;
map<pair<int, int> , int >M;
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
void work()
{
	M.clear();
	int n = read();
	string st;
	cin >> st;
	int sumk = 0, sumd = 0;
	for (int i = 0; i < n; i++)
	{
		if (st[i] == 'D')sumd++;
		else sumk++;
		if (sumk == 0 || sumd == 0)
			printf("%d ", i + 1);
		else
		{
			int x = __gcd(sumk, sumd);
			int a = sumd / x;
			int b = sumk / x;
			pair<int, int> t = make_pair(a, b);
			M[t]++;
			printf("%d ", M[t]);
		}
	}
	printf("\n");
}
int main()
{
	int T = read();
	while (T--)
		work();
	return 0;
}