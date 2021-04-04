#include <bits/stdc++.h>
#define P 1000000007
#define INF 2147483647
#define INFF 9223372036854775807
#define LL long long
#define N 1005
using namespace std;
int a[N][N];
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			int col;
			cin >> col;
			if (col == 1)
			{
				if (a[i][j - 1] == 2 || a[i - 1][j] == 2)
					a[i][j] = 3;
				else
					a[i][j] = 2;

			}
			else if (col == 2)
			{
				if (a[i][j - 1] == 1 || a[i - 1][j] == 1)
					a[i][j] = 3;
				else
					a[i][j] = 1;

			}
			else
			{
				if (a[i - 1][j] == 2 || a[i][j - 1] == 2)
					a[i][j] = 1;
				else
					a[i][j] = 2;
			}
			cout << a[i][j] << " " << i << " " << j << endl;
			cout<<endl;
			cout.flush();
			fflush(stdout);
		}
	return 0;
}