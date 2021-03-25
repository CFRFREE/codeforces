#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 200005
using namespace std;
int a[N],ans[N];
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
		for (int i = 1; i <= n; i++)
			a[i] = read();
		int mini=INF;
		for (int i = n; i >= 1; i--)
		{
 			mini=min(mini,i-a[i]+1);
 			if(mini<=i)ans[i]=1;
 			else ans[i]=0;        
		}
		for(int i = 1; i<= n; i++)
			printf("%d ", ans[i]);
		printf("\n");
	}
	return 0;
}