#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 200005
using namespace std;
int pos,Left[N],Right[N],ans;
string st1,st2;
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
	int n = read(), m = read();
	cin >> st1 >> st2;
	int pos=0;
	for (int i = 0; i < m;i++)
	{
		char ch=st2[i];
		while(st1[pos]!=ch&&pos<n)
			pos++;
		Left[i]=pos;
		pos++;
	}
	pos=n-1;
	for(int i=m-1;i>=0;i--)
	{
		char ch=st2[i];
		while(st1[pos]!=ch&&pos>0)
			pos--;
		Right[i]=pos;
		pos--;
	}
/*	for(int i = 0; i<m ; i++)
		printf("%d ", Left[i]);
	printf("\n");
	for(int i = 0; i<m ; i++)
		printf("%d ", Right[i]);*/
	for(int i = 0; i<m-1 ; i++)
		ans=max(ans,Right[i+1]-Left[i]);
	printf("%d\n", ans);
	return 0;
}