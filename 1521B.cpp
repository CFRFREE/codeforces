#include <bits/stdc++.h>
#define P 1000000007
#define INF 2147483647
#define INFF 9223372036854775807
#define LL long long
#define N 200005
using namespace std;
vector<int>ans1, ans2, ans3, ans4;
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
		int mini = INF;
		int pos = 0;
		for (int i = 1; i <= n; i++)
		{
			a[i] = read();
			if (a[i] < mini)
			{
				mini = a[i];
				pos = i;
			}
		}
		printf("%d\n", n - 1);
		for (int i = pos - 1; i >= 1; i--)
			printf("%d %d %d %d\n", pos, i, mini, mini + pos - i);
		for (int i = pos + 1; i <= n; i++)
			printf("%d %d %d %d\n", pos, i, mini, mini + i - pos);
	}
	return 0;
}