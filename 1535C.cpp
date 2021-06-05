#include <bits/stdc++.h>
#define P 1000000007
#define INF 2147483647
#define INFF 9223372036854775807
#define LL long long
#define N 100005
using namespace std;
LL ans;
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
LL cal(string st)
{
	//cout << st << endl;
	LL s = 0;
	int p = 0;
	int len = st.size();
	for (auto ch : st)
		if (ch == '?')
		{
			p = 1;
			break;
		}
	if (!p)return (len + 1) * len / 2;
	for (int i = 0; i < len; i++)
		if (st[i] == '?')
		{
			if (i == 0)
			{
				if (st[i + 1] == '0')st[i] = '1';
				else st[i] = '0';
				if (st[i] == st[i + 1])st[i] = '?';
			}

			else if (i == len - 1)
			{
				if (st[i - 1] == '0')st[i] = '1';
				else st[i] = '0';
				if (st[i] == st[i - 1])st[i] = '?';
			}
			else
			{
				if (st[i - 1] == '0')st[i] = '1';
				else if (st[i - 1] == '1')st[i] = '0';
				if (st[i] == st[i + 1])st[i] = '?';
			}
		}
	for (int i = len - 1; i > 0; i--)
		if (st[i] == '?')
		{
			if (i == 0)
			{
				if (st[i + 1] == '0')st[i] = '1';
				else st[i] = '0';
				if (st[i] == st[i + 1])st[i] = '?';
			}
			else if (i == len - 1)
			{
				if (st[i - 1] == '0')st[i] = '1';
				else st[i] = '0';
				if (st[i] == st[i - 1])st[i] = '?';
			}
			else
			{
				if (st[i - 1] == '0')st[i] = '1';
				else if (st[i - 1] == '1')st[i] = '0';
				if (st[i] == st[i + 1])st[i] = '?';
			}
		}
	for (int i = 0; i < len; i++)
		if (st[i] == '?')
		{
			if (i == 0)
			{
				if (st[i + 1] == '0')st[i] = '1';
				else st[i] = '0';
				if (st[i] == st[i + 1])st[i] = '?';
			}
			else if (i == len - 1)
			{
				if (st[i - 1] == '0')st[i] = '1';
				else st[i] = '0';
				if (st[i] == st[i - 1])st[i] = '?';
			}
			else
			{
				if (st[i - 1] == '0')st[i] = '1';
				else if (st[i - 1] == '1')st[i] = '0';
				if (st[i] == st[i + 1])st[i] = '?';
			}
		}
	p = 0;
	for (auto ch : st)
		if (ch == '?')
			p++;
	if (!p)return len * (len + 1) / 2;
	vector<int>v;
	v.clear();
	for (int i = 0; i < len; i++)
		if (st[i] == '?')v.push_back(i);
	int pos = 0;
	int x = v[0] + 1;
	//printf("%d\n", x);
	s += (x + 1) * x / 2;
	x = len - v[v.size() - 1];
	//printf("%d\n", x);
	s += (x + 1) * x / 2;
	//cout << s << endl;
	for (int i = 1; i < v.size(); i++)
	{
		int x = v[i] - v[i - 1] + 1;
		s += (x + 1) * (x) / 2 - 1;
	}
	//printf("%d\n", s);
	if (v.size() == 1)return (s - 1);
	if (v.size() == 2)return (s - 2);
	return s - p;
}
void work()
{
	string st;
	cin >> st;
	ans = 0;
	int len = st.size();
	int pos = 0;
	for (int i = 1; i < len; i++)
		if (st[i] == st[i - 1] && st[i] != '?')
		{
			ans += cal(st.substr(pos, i - pos));
			pos = i;
		}
	ans += cal(st.substr(pos, len - pos));
	printf("%lld\n", ans);
}
int main()
{
	int T = read();
	while (T--)
		work();
	return 0;
}
