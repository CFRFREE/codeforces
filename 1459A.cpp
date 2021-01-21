#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 100005
using namespace std;
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
		int r = 0;
		int b = 0;
		string st1, st2;
		cin >> st1 >> st2;
		for (int i = 0; i < n; i++)
			if (st1[i] > st2[i])r++;
			else if (st1[i] < st2[i])b++;
		if (r > b)printf("RED\n");
		else if (r < b)printf("BLUE\n");
		else printf("EQUAL\n");

	}
	return 0;
}