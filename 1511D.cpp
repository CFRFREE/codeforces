#include <bits/stdc++.h>
#define P 1000000007
#define INF 2147483647
#define INFF 9223372036854775807
#define LL long long
#define N 100005
using namespace std;
string str;
map<string, int>M;
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
	string st;
	int n = read(), k = read();
	for (int i = 0; i < k; i++)
	{
		st += char(int('a') + i);
		st += char(int('a') + i);
	}
	for (int i = 0; i < k * 2 - 1; i++)
	{
		//cout<<st.substr(i, 2)<<endl;
		M[st.substr(i,2)] = 1;
	}
	char ch = 'a';
	st+='a';
	int p = 0;
	str="aa";
	str[0]=st[k*2-1];
	M[str]=1;
	for (int i = 1; i <= k * 2; i++)
	{
		if (p == 0)
		{
			for (int j = 0; j < k; j++)
			{
				str = "aa";
				str[0] = ch;
				str[1] = char(int('a') + j);
				if (M[str] == 0)
				{
					//cout<<str<<endl;
					M[str] = 1;
					st += str[1];
					ch = str[1];
					p=1;
					goto free;
				}
			}
		}
		else
		{
			for (int j = 0; j <k ; j++)
			{
				str = "aa";
				str[0] = ch;
				str[1] = char(96 + k - j);
				if (M[str] == 0)
				{
					M[str] = 1;
					st += str[1];
					ch = str[1];
					p=0;
					goto free;
				}
			}
		}
		free:;
	}
	int m=st.size();
	for(int i=1;i<=n/m;i++)
		cout<<st;
	for(int i=0;i<n%m;i++)
		cout<<st[i];
	return 0;
}