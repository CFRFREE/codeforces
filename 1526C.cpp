#include <bits/stdc++.h>
#define P 1000000007
#define INF 2147483647
#define INFF 9223372036854775807
#define int long long
#define N 200005
using namespace std;
int n, a[N], sum[N], cnt, ans;
struct Node
{
	int l, r, f, w, mini;
} tree[N << 2];
struct qwq {
	int id, val;
};
vector<qwq> v;
inline int cmp(qwq a, qwq b)
{
	if (a.val != b.val)return a.val > b.val;
	return a.id > b.id;
}
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
void PushUp(int k)
{
	tree[k].w = min(tree[k << 1].w, tree[k << 1 | 1].w);
}
void PushDown(int k)
{
	if (!tree[k].f)return;
	int x = tree[k].f;
	tree[k].f = 0;
	tree[k << 1].f += x;
	tree[k << 1 | 1].f += x;
	tree[k << 1].w += x;
	tree[k << 1 | 1].w += x;
}
void build(int k, int L, int R)
{
	tree[k].l = L;
	tree[k].r = R;
	if (L == R)
	{
		tree[k].w = sum[++cnt];
		return;
	}
	int mid = (L + R) >> 1;
	build(k << 1, L, mid);
	build(k << 1 | 1, mid + 1, R);
	PushUp(k);
}
void change(int k, int L, int R, int x)
{
	if (tree[k].l >= L && tree[k].r <= R)
	{
		tree[k].f += x;
		tree[k].w += x;
		return;
	}
	PushDown(k);
	int mid = (tree[k].l + tree[k].r) >> 1;
	if (mid >= L)change(k << 1, L, R, x);
	if (mid < R)change(k << 1 | 1, L, R, x);
	PushUp(k);
}

int query_min(int k, int L, int R)
{
	if (tree[k].l >= L && tree[k].r <= R)
		return tree[k].w;
	PushDown(k);
	int mini = INF;
	int mid = (tree[k].l + tree[k].r) >> 1;
	if (mid >= L)mini = min(query_min(k << 1, L, R), mini);
	if (mid < R)mini = min(query_min(k << 1 | 1, L, R), mini);
	return mini;
}
signed main()
{
	n = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	for (int i = 1; i <= n; i++)
	{
		if (a[i] >= 0)
		{
			ans++;
			sum[i] = sum[i - 1] + a[i];
		}
		else
		{
			v.push_back(qwq{i, a[i]});
			sum[i] = sum[i - 1];
		}
	}
	build(1, 1, n);
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++)
	{
		int pos = v[i].id, x = v[i].val;
		//printf("%d %d\n", x, query_min(1, pos, n));
		if (x + query_min(1, pos, n) >= 0)
		{
			ans++;
			change(1, pos, n, x);
			//printf("%d %d\n", x, query_min(1, pos, n));
		}
	}
	printf("%lld\n", ans);
	return 0;
}