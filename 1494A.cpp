#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 100005
using namespace std;
int cnt_a,cnt_b,cnt_c,n;
string st1;
stack<int>S;
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
int check(string str)
{
	int cnt=0;
	for(int i = 0; i<n; i++)
		if(st1[i]=='(')
		{
			S.push(1);
			cnt++;
		}
		else
		{
			if(S.empty()||cnt==0)return 0;
			if(S.top()==')')return 0;
			S.pop();
			cnt--;
		}
	if(cnt!=0||!S.empty())return 0;
	return 1;
}
int main()
{
	int T = read();
	while (T--)
	{
		string st;
		cin >> st;
		n = st.size();
		cnt_a = cnt_b = cnt_c = 0;
		for (int i = 0; i < n; i++)
		{
			if (st[i] == 'A')cnt_a++;
			else if (st[i] == 'B')cnt_b++;
			else cnt_c++;
		}
		if (cnt_a > (n / 2) || cnt_b > (n / 2) || cnt_c > n / 2)
			printf("NO\n");
		else
		{
			st1=st;
			//printf("%d %d %d\n", cnt_a,cnt_b,cnt_c);
			if (cnt_a == (n / 2))
			{
				if (st[0] == 'A')
					for (int i = 0; i < n; i++)
						if (st[i] == 'A')st1[i]='(';
							else st1[i] = ')';
				else
					for (int i = 0; i < n; i++)
						if (st[i] == 'A')st1[i] = ')';
							else st1[i] = '(';
			}
			if (cnt_b == (n / 2))
			{
				if (st[0] == 'B')
					for (int i = 0; i < n; i++)
						if (st[i] == 'B')st1[i] = '(';
						else st1[i] = ')';
				else
					for (int i = 0; i < n; i++)
						if (st[i] == 'B')st1[i] = ')';
						else st1[i] = '(';
			}
			if (cnt_c == (n / 2))
			{
				if (st[0] == 'C')
					for (int i = 0; i < n; i++)
						if (st[i] == 'C')st1[i] = '(';
						else st1[i] = ')';
				else
					for (int i = 0; i < n; i++)
						if (st[i] == 'C')st1[i] = ')';
						else st1[i] = '(';
			}
			if(check(st1))printf("YES\n");else printf("NO\n");
		}
	}
	return 0;
}