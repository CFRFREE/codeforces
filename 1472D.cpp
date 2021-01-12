#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 100005
using namespace std;
LL T, n, cnt, score1, score2;
vector<int>odd, even;
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
	T = read();
	while (T--)
	{
		n = read();
		odd.clear();
		even.clear();
		score1 = 0;
		score2 = 0;
		cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			int x = read();
			if (x % 2 == 0)
				even.push_back(x);
			else
				odd.push_back(x);
		}
		sort(even.begin(), even.end());
		sort(odd.begin(), odd.end());
		while (cnt != n)
		{
			cnt++;
			if (cnt % 2 == 1)
			{
				if (even.empty())
					odd.pop_back();
				else if (odd.empty())
				{
					score1 += even.back();
					even.pop_back();
				}
				else if (even.back() > odd.back())
				{
					score1 += even.back();
					even.pop_back();
				}
				else
					odd.pop_back();
			}
			else
			{
				if (odd.empty())
					even.pop_back();
				else if (even.empty())
				{
					score2 += odd.back();
					odd.pop_back();
				}
				else if (even.back() < odd.back())
				{
					score2 += odd.back();
					odd.pop_back();
				}
				else
					even.pop_back();
			}
		}
		if (score1 > score2)
			printf("Alice\n");
		else if (score1 < score2)
			printf("Bob\n");
		else
			printf("Tie\n");
	}
	return 0;
}
