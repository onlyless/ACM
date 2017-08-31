#include<iostream>
#include<cstring>
#include<algorithm>
const int maxn = 105;
const int maxm = 10010;
using namespace std;
int f[maxn];
struct node
{
	int from, to, w;
	node() {}
	node(int a, int b, int c) :from(a), to(b), w(c) {}
};
node edge[maxm];
int getfather(int i)
{
	if (f[i] == i)return i;
	else 
		return f[i]=getfather(f[i]);
}
int main()
{
	int N = 0, M = 0;
	while (scanf("%d%d", &N, &M),N) {
		for (int i = 0; i < maxn; i++)
			f[i] = i;
		int te = 0;
		int a, b, c;
		for (int i = 0; i < N; i++) {
			scanf("%d%d%d", &a, &b, &c);
			edge[te++] = node(a, b, c);
		}
		sort(edge, edge + te, [](const node& a, const node& b) {return a.w < b.w; });
		int num = 0, ans = 0;
		for (int i = 0; i < te; i++) {
			int a = getfather(edge[i].from);
			int b = getfather(edge[i].to);
			if (a != b) {
				if (num == M - 1)break;
				f[a] = b;
				num++;
				ans += edge[i].w;
			}
		}
		if (num != M - 1)
			printf("?\n");
		else printf("%d\n", ans);
	}
	return 0;
}