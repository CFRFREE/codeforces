#include <bits/stdc++.h>
#define INF 2147483647
#define LL long long
#define N 100005
using namespace std;
string st1, st2, st3;
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		cin >> st2;
		st1="1";
		st3.clear();
		if (st2[0] == '1')
			st3+='2';
		else
			st3+='1';
		for (int i = 1; i < n; i++)
		{
			//cout<<i<<" "<<st2[i]<<" "<<st3[i]<<endl;
			if (st2[i] == '0' && st3[i - 1] == '0')
			{
				st1 += '1';
				st3 += '1';
			}
			if (st2[i] == '0' && st3[i - 1] == '1')
			{
				st1 += '0';
				st3 += '0';
			}
			if (st2[i] == '1' && st3[i - 1] == '0')
			{
				st1 += '1';
				st3 += '2';
			}
			if (st2[i] == '1' && st3[i - 1] == '1')
			{
				st1 += '1';
				st3 += '2';
			}
			if (st2[i] == '0' && st3[i - 1] == '2')
			{
				st1 += '1';
				st3 += '1';
			}
			if (st2[i] == '1' && st3[i - 1] == '2')
			{
				st1 += '0';
				st3 += '1';
			}
		}
		cout << st1 << endl;
	}
	return 0;
}
