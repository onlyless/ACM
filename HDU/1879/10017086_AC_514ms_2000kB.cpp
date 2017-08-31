#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 15000;
int f[maxn];
struct node
{
	int front, back, val;
	node() {}
	node(int a, int b, int c) :front(a), back(b), val(c) {}
};
node edge[maxn];
int find(int n)
{
	if (f[n] == n)return n;
	else f[n] = find(f[n]);
}
int main()
{
	int T = 0;
	while (scanf("%d", &T), T) {
		int te = 0;
		for (int i = 0; i < maxn; i++)
			f[i] = i;
		for (int i = 0; i < (T*(T-1))/2; i++) {
			int a = 0, b = 0, c = 0, d = 0;
			scanf("%d%d%d%d", &a, &b, &c, &d);
			if (d)c = 0;
			edge[te++] = node(a, b, c);
		}
		sort(edge, edge + te, [](const node& a, const node& b) {return a.val < b.val; });
		int num = 0;
		int ans = 0;
		for (int i = 0; i < te; i++) {
			int a = find(edge[i].front);
			int b = find(edge[i].back);
			if (a != b) {
				f[a] = b;
				num++;
				ans += edge[i].val;
				if (num == T - 1)break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}