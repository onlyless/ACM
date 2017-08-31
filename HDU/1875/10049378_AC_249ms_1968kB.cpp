#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn = 1005;
struct node
{
	int x, y;
	node() {}
	node(int a, int b) :x(a), y(b) {}
};
node point[maxn];
struct dist
{
	int start, ends;
	double val;
	dist() {}
	dist(int a, int b) :start(a), ends(b) {}
};
dist edge[maxn*maxn];
int f[maxn];
int find(int n)
{
	if (n == f[n])return n;
	else f[n] = find(f[n]);
}
bool judge(double num)
{
	if (num >= 10&&num <= 1000)
		return true;
	else return false;
}
bool cmp(const dist& a, const dist& b)
{
	return a.val<b.val;
}
int main()
{
	int T = 0;
	scanf("%d", &T);
	while (T--) {
		memset(f, 0, sizeof(f));
		int C = 0;
		scanf("%d", &C);
		int te = 0;
		for (int i = 0; i<C; i++) {
			f[i] = i;
			int x = 0, y = 0;
			scanf("%d%d", &x, &y);
			point[te++] = node(x, y);
		}
		int temp = 0;
		for (int i = 0; i<C; i++) {
			for (int j = i + 1; j<C; j++) {
				double aedge = sqrt((double)(point[i].x - point[j].x)*(point[i].x - point[j].x) + (double)(point[i].y - point[j].y)*(point[i].y - point[j].y));
				if (judge(aedge)) {
					edge[temp] = dist(i, j);
					edge[temp++].val = aedge;
				}
			}
		}
		sort(edge, edge + temp, cmp);
		double ans = 0;
		int num = 0;
		for (int i = 0; i<temp; i++) {
			int a = find(edge[i].start);
			int b = find(edge[i].ends);
			if (a != b) {
				f[b] = a;
				num++;
				ans += edge[i].val;
				if (num == C - 1)break;
			}
		}
		if (num!=C-1 )
			printf("oh!\n");
		else
			printf("%.1lf\n", ans * 100);
	}
	return 0;
}