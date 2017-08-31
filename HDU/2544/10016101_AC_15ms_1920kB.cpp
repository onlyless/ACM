#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 105;
const int inf = 0x3f3f3f3f;
int m, n;
int M[maxn][maxn];
void dijkstra()
{
	int d[maxn], vis[maxn];
	for (int i = 1; i <= n; i++)  vis[i] = 0, d[i] = inf;
	d[1] = 0;
	while(1){
		int temp = inf;
		int u = -1;
		for (int i = 1; i <= n; i++){
			if (temp > d[i] && vis[i] != 2) {
				temp = d[i];
				u = i;
			}
		}
		if (u == -1)break;
		vis[u] = 2;
		for (int j = 1; j <= n; j++){
			if (vis[j] != 2 && M[u][j] != inf) {
				if (d[j] > d[u] + M[u][j]) {
					d[j] = d[u] + M[u][j];
					vis[j] = 1;
				}
			}
		}
	}
	printf("%d\n", d[n]);
	return ;
}
int main()
{
	while (scanf("%d%d", &n, &m), n + m) {
		memset(M, inf, sizeof(M));
		int ju = 0;
		for (int i = 0; i < m; i++) {
			int a = 0, b = 0, c = 0;
			scanf("%d%d%d", &a, &b, &c);
			M[a][b] = c;
			M[b][a] = c;
		}
		dijkstra();
	}
	return 0;
}