#include <bits/stdc++.h>
#define INF 2147483647
#define INFF 9223372036854775807
#define LL long long
#define N 10005
using namespace std;
int cnt[N];
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
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1; i <= n; i++)
		{
			int x = read();
			cnt[x]++;
		}
		for (int i = 0; i <= 100; i++)
			if (cnt[i])
			{
				printf("%d ", i);
				cnt[i]--;
			}
		for (int i = 0; i <= 100; i++)
			if (cnt[i])
			{
				while (cnt[i])
				{
					printf("%d ", i);
					cnt[i]--;
				}
			}
		printf("\n");
	}
	return 0;
}