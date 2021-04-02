#include <bits/stdc++.h>
#define P 1000000007
#define INF 2147483647
#define INFF 9223372036854775807
#define LL long long
#define N 100005
using namespace std;
int a[N];
string st;
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
int ok()
{
	int n=st.size();
	if(n<=2)
		return 1;
	for(int i = 3; i<= n - 1; i++)
		if(a[i]!=a[i-1]+a[i-2])return 0;
	return 1;
}
int main()
{
	cin>>st;
	for(int i = 0; i< st.size() ; i++)
		a[i+1]=int(st[i])-65;

	if(ok())
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}