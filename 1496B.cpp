#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 100005
using namespace std;
int mex, maxn, k, n;
set<int>s;
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
void work(int begin)
{
	for (int i = begin; i <= INF; i++)
		if (s.find(i) == s.end())
		{
			mex = i;
			return;
		}
}
void qaq()
{
	if(maxn==n-1)
	{
		printf("%d\n", s.size()+k);
		return;
	}
	while (k--)
	{
		int x = (mex + maxn + 1) / 2;
		if (s.find(x) != s.end())
		{
			printf("%d\n", s.size());
			return;
		}
		s.insert(x);
		if (x > maxn)maxn = x;
		if (x == mex)
			work(mex + 1);
	}
	printf("%d\n", s.size());
	return;
}
int main()
{
	int T = read();
	while (T--)
	{
		n = read(), k = read();
		s.clear();
		maxn = 0;
		for (int i = 1; i <= n; i++)
		{
			int x = read();
			if (x > maxn)
				maxn = x;
			s.insert(x);
		}
		work(0);
		//printf("%d %d\n", mex,maxn);
		qaq();
	}
	return 0;
}