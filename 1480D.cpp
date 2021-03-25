#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 100005
using namespace std;
int a[N];
vector<int>ans1, ans2, id1, id2;
queue<int>q[N];
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
	int n = read();
	for (int i = 1; i <= n; i++)
	{
		a[i] = read();
		q[a[i]].push(i);
	}
	ans1.push_back(0);
	id1.push_back(0);
	ans2.push_back(0);
	id2.push_back(0);
	for (int i = 1; i <= n; i++)
	{
		int x = ans1.back();
		int y = ans2.back();
		int z = a[i];
		if (x == z)
		{
			ans2.push_back(z);
			id2.push_back(i);
		}
		else if (y == z)
		{
			ans1.push_back(z);
			id1.push_back(i);
		}
		else
		{
			while (q[x].top() != id1.back())
				q[x].pop();
			int next1 = q[x].top();
			while (q[y].top() != id1.back())
				q[y].pop();
			int next2 = q[y].top();
			if (next1 < next2)
			{
				ans1.push_back(z);
				id1.push_back(i);
			}
			else
			{
				ans2.push_back(z);
				id2.push_back(i);
			}
		}
	}
	int n1 = unique(ans1.begin(), ans1.end()) - ans1.begin();
	int n2 = unique(ans2.begin(), ans2.end()) - ans2.begin();
	printf("%d\n", n1 + n2 - 2);
	return 0;
}