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
	int T=read();
	while(T--)
	{
		string st;
		cin>>st;
		int n=st.size();
		for(int i = 0; i < n ; i++)
		{
			if(i%2)
			{
				if(st[i]!='z')
					st[i]='z';
				else st[i]='y';
			}else
			{
				if(st[i]!='a')
					st[i]='a';
				else
					st[i]='b';
			}
		}
		cout<<st<<endl;
	}
	return 0;
}