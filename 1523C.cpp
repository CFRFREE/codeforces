#include <bits/stdc++.h>
#define P 1000000007
#define INF 2147483647
#define INFF 9223372036854775807
#define LL long long
#define N 100005
using namespace std;
deque<int>s;
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
	deque<int>S = s;
	while (S.size())
	{
		printf("%d", S.front());
		S.pop_front();
		if (S.size())printf(".");
	}
	printf("\n");
}
int main()
{
	int T = read();
	while (T--)
	{
		int n = read();
		for (int i = 1; i <= n; i++)
		{
			int x = read();
			if (x == 1)
				s.push_back(1);
			else
			{
				while (s.size() && s.back() + 1 != x)
					s.pop_back();
				s.pop_back();
				s.push_back(x);
			}
			work();
		}
		while (s.size())s.pop_back();
	}
	return 0;
}