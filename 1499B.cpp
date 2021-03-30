#include <bits/stdc++.h>
#define P 1000000007
#define INF 2147483647
#define INFF 9223372036854775807
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
int ok(string st)
{
	if (st.size() <= 3)return 1;
	while (st.size() && st[0] == '0')
		st.erase(0, 1);
	while (st.size() && st[st.size() - 1] == '1')
		st.erase(st.size() - 1, 1);
	if (st.size() <= 3)return 1;
	int n = st.size();
	int pos0 = 0, pos1 = n;
	for (int i = 1; i < n; i++)
		if (st[i] == st[i - 1] && st[i] == '0')
			pos0 = i;
	for (int i = n - 1; i >= 1; i--)
		if (st[i] == st[i - 1] && st[i] == '1')
			pos1 = i;	
	if (pos0 >= pos1)
		return 0;
	return 1;
}
int main()
{
	int T = read();
	while (T--)
	{
		string st;
		cin >> st;
		if (ok(st))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}