#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 60;
const int maxm = 60*60;
struct node
{
	int x, y;
	node() {}
	node(int a, int b) :x(a), y(b) {}
};
node Node[maxn];
struct edge
{
	int a, b;
	double length;
	edge() {}
	edge(int x, int y) {
		a = x;
		b = y;
	}
};
edge Edge[maxm];
int f[maxn];
int find(int n)
{
	if (f[n] == n)return n;
	else f[n] = find(f[n]);
}
double get(node a, node b)
{
	return sqrt((double)(a.x - b.x)*(a.x - b.x) + (double)(a.y - b.y)*(a.y - b.y));
}
int main()
{
	int N = 0;
	while (scanf("%d", &N), N) {
		int p=0, q=0;
		scanf("%d%d", &p, &q);
		if (p > q)swap(q, p);
		int temp=0;
		for (int i = 1; i <= N; i++) {
			f[i] = i;
			scanf("%d%d", &Node[i].x, &Node[i].y);
		}
		double ans = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = i+1; j <= N; j++) {
				double va = get(Node[i], Node[j]);
				Edge[temp] = edge(i, j);
				Edge[temp++].length = va;
				if ((i == p&&j==q)) {
					Edge[temp-1].length=0;
				}
			}
		}
		ans = get(Node[p], Node[q]);
		sort(Edge, Edge + temp, [](const edge& a, const edge& b) {return a.length < b.length; });
		int num = 0;
		for (int i = 0; i < temp; i++) {
			int a = find(Edge[i].a);
			int b = find(Edge[i].b);
			if (a != b) {
				f[b] = a;
				ans += Edge[i].length;
				num++;
				if (num == N - 1)break;
			}
		}
		printf("%.2lf\n", ans);
	}
	return 0;
}