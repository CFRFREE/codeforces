#include <bits/stdc++.h>
#define P 1000000007
#define INF 2147483647
#define INFF 9223372036854775807
#define LL long long
#define N 100005
using namespace std;
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
void work()
{
	int n = read();
	for (int i = 1; i <= n; i++)a[i] = read();
	sort(a + 1, a + n + 1);
	int mini = INF;
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (a[i] > 0)
		{
			if (a[i] <= mini)
			{
				printf("%d\n", cnt + 1);
				return;
			}
			else
			{
				printf("%d\n", max(cnt, 1));
				return;
			}
		}
		else
		{
			cnt++;
			if (i != 1 && a[i] - a[i - 1] < mini)mini = a[i] - a[i - 1];
		}
	printf("%d\n", cnt);
	return ;

}
int main()
{
	int T = read();
	while (T--)
		work();
	return 0;
}