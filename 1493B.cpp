#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 100005
using namespace std;
int h,m,no[10],tran[10];
string st,st1,st2;
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
int work(int H,int M)
{
	int x=H,y=M;
	if(no[x%10]||no[x/10]||no[y%10]||no[y/10])
		return 0;
	x=tran[M%10]*10+tran[M/10];
	y=tran[H%10]*10+tran[H/10];
	if(x<h&&y<m)
		return 1;
	return 0;
}
int main()
{
	int T=read();
	no[3]=no[4]=no[6]=no[7]=no[9]=1;
	tran[0]=0;
	tran[1]=1;
	tran[2]=5;
	tran[5]=2;
	tran[8]=8;

	while(T--)
	{
		h=read(),m=read();
		cin>>st;
		st1=st.substr(0,2);
		st2=st.substr(3,2);
		int H=int(st1[0]-48)*10+int(st1[1]-48);
		int M=int(st2[0]-48)*10+int(st2[1]-48);
		while(!work(H,M))
		{
			if(M+1>=m)
			{
				M=0;
				H++;
			}
			else
			{
				M++;
			}
			H%=h;
		}
		if(H<10)
			printf("0");
		printf("%d:", H);
		if(M<10)
			printf("0");
		printf("%d\n", M);		
	}
	return 0;
}
