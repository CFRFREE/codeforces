#include<bits/stdc++.h>
#define LL long long
#define N 300005

using namespace std;
int n, m, k, len, tot, answer, cnt[N], a[N], b[N], ans[N];
int maxn = N - 1 , cntcnt[N];
struct Node
{
	int l, r, id;
} ask[N];

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

inline int cmp(Node x, Node y)
{
	if (b[x.l] != b[y.l])
		return b[x.l] < b[y.l];
	else
	{
		if (b[x.l] % 2 == 1)
			return x.r < y.r;
		else return x.r > y.r;
	}
}

void remove(int pos)
{
	cntcnt[cnt[a[pos]]]--;
	cnt[a[pos]]--;
	cntcnt[cnt[a[pos]]]++;
}

void add(int pos)
{
	cntcnt[cnt[a[pos]]]--;
	cnt[a[pos]]++;
	cntcnt[cnt[a[pos]]]++;
	maxn = max(maxn, cnt[a[pos]]);
}

int main()
{
	n = read(), m = read();
	len = sqrt(n);
	tot = n / len;
	if (n % len)tot++;
	for (register int i = 1; i <= n; i++)
	{
		a[i] = read();
		b[i] = (i - 1) / len + 1;
	}
	for (register int i = 1; i <= m; i++)
	{
		ask[i].l = read();
		ask[i].r = read();
		ask[i].id = i;
	}
	sort(ask + 1, ask + m + 1, cmp);
	int curl = 1, curr = 0;
	for (register int i = 1; i <= m; i++)
	{
		int L = ask[i].l, R = ask[i].r;
		while (curl < L)remove(curl++);
		while (curl > L)add(--curl);
		while (curr < R)add(++curr);
		while (curr > R)remove(curr--);
		while (!cntcnt[maxn])
			maxn--;
		if (maxn <= (R - L + 2) / 2)
			ans[ask[i].id] = 1;
		else
			ans[ask[i].id] = 2 * maxn - (R - L + 1);
	}
	for (register int i = 1; i <= m; i++)
		printf("%d\n", ans[i]);
	return 0;
}