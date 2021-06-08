#include <bits/stdc++.h>
#define P 1000000007
#define INF 2147483647
#define INFF 9223372036854775807
#define LL long long
#define N 100005
using namespace std;
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
int work1()
{
	string str;
	for (char ch = 'a'; ch <= 'z'; ch++)
	{
		str = ch;
		//cout << str << endl;
		if (M.find(str) == M.end())
		{
			cout << str << endl;
			return 1;
		}
	}
	return 0;
}
int work2()
{
	string str;
	for (char ch1 = 'a'; ch1 <= 'z'; ch1++)
		for (char ch2 = 'a'; ch2 <= 'z'; ch2++)
		{
			str = "";
			str += ch1, str += ch2;
			//cout << str << endl;
			if (M.find(str) == M.end())
			{
				cout << str << endl;
				return 1;
			}
		}
	return 0;
}
int work3()
{
	string str;
	for (char ch1 = 'a'; ch1 <= 'z'; ch1++)
		for (char ch2 = 'a'; ch2 <= 'z'; ch2++)
			for (char ch3 = 'a'; ch3 <= 'z'; ch3++)
			{
				str = "";
				str += ch1, str += ch2, str += ch3;
				if (M.find(str) == M.end())
				{
					cout << str << endl;
					return 1;
				}
			}
	return 0;
}
int work4()
{
	string str;
	for (char ch1 = 'a'; ch1 <= 'z'; ch1++)
		for (char ch2 = 'a'; ch2 <= 'z'; ch2++)
			for (char ch3 = 'a'; ch3 <= 'z'; ch3++)
				for (char ch4 = 'a'; ch4 <= 'z'; ch4++)
				{
					str = "";
					str += ch1, str += ch2, str += ch3, str += ch4;
					if (M.find(str) == M.end())
					{
						cout << str << endl;
						return 1;
					}
				}
	return 0;
}
int work5()
{
	string str;
	for (char ch1 = 'a'; ch1 <= 'z'; ch1++)
		for (char ch2 = 'a'; ch2 <= 'z'; ch2++)
			for (char ch3 = 'a'; ch3 <= 'z'; ch3++)
				for (char ch4 = 'a'; ch4 <= 'z'; ch4++)
					for (char ch5 = 'a'; ch5 <= 'z'; ch5++)
					{
						str = "";
						str += ch1, str += ch2, str += ch3, str += ch4, str += ch5;
						if (M.find(str) == M.end())
						{
							cout << str << endl;
							return 1;
						}
					}
	return 0;
}
int work6()
{
	string str;
	for (char ch1 = 'a'; ch1 <= 'z'; ch1++)
		for (char ch2 = 'a'; ch2 <= 'z'; ch2++)
			for (char ch3 = 'a'; ch3 <= 'z'; ch3++)
				for (char ch4 = 'a'; ch4 <= 'z'; ch4++)
					for (char ch5 = 'a'; ch5 <= 'z'; ch5++)
						for (char ch6 = 'a'; ch6 <= 'z'; ch6++)
						{
							str = "";
							str += ch1, str += ch2, str += ch3, str += ch4, str += ch5, str += ch6;
							if (M.find(str) == M.end())
							{
								cout << str << endl;
								return 1;
							}
						}
	return 0;
}
void work()
{
	int n = read();
	M.clear();
	string st;
	cin >> st;
	for (int len = 1; len <= n; len++)
		for (int i = 0; i + len <= n; i++)
		{
			string str = st.substr(i, len);
			if (M.find(str) == M.end())
				M[str] = 1;
		}
	if (work1())return;
	else if (work2())return;
	else if (work3())return;
	else if (work4())return;
	else if (work5())return;
	else work6();
}
int main()
{
	int T = read();
	while (T--)
		work();
	return 0;
}