#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 100005
using namespace std;
int T, n1, n2;
string st1, st2, st, str;
inline int read()
{
	int X = 0, w = 0;
	char ch = 0;
	while (!isdigit(ch))
	{
		w |= ch == '-';
		ch = getchar();
	}
	while (isdigit(ch))
		X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
	return w ? -X : X;
}
int ok(int x)
{
	str = st = "";
	if ((x * n1) % n2 != 0)
		return 0;
	int num = (x * n1) / n2;
	while (num--)
		str += st2;
	for (register int i = 1; i <= x; i++)
		st += st1;
	if (str != st)
		return 0;
	return 1;
}
int main()
{
	T = read();
	while (T--)
	{
		cin >> st1 >> st2;
		n1 = st1.size(), n2 = st2.size();
		int flag = 0;
		if (n1 < n2)
			swap(st1, st2), swap(n1, n2);
		for (register int i = 1; i <= 50; i++)
		{
			if (ok(i))
			{
				cout << st;
				printf("\n");
				flag = 1;
				break;
			}
		}
		if (!flag)
			printf("-1\n");
	}

	return 0;
}