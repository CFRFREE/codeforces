#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 100005
using namespace std;
vector<int>v;
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
int ok(LL x)
{
	v.clear();
	LL X = x;
	while (X > 0)
	{
		if (X % 10)
			v.push_back(X % 10);
		X /= 10;
	}
	for (int i = 0; i < v.size(); i++)
		if (x % v[i])return 0;
	return 1;
}

int main()
{
	int T = read();
	while (T--)
	{
		LL x;
		scanf("%lld",&x);
		while(!ok(x))
			x++;
		printf("%lld\n", x);
	}
	return 0;
}