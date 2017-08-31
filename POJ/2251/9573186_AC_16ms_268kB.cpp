#include<iostream>
#include<cstdio>
#include<queue>
#include<string>
#include<cstring>
using namespace std;
char A[31][31][31];
struct node
{
	int x, y, z;
	int step;
	node() {}
	node(int a, int b, int c) :x(a), y(b), z(c) {}
};
int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
int L, R, C;

int ans;
bool vis[31][31][31];
void bfs(node a)
{
	memset(vis, 0, sizeof(vis));
	queue<node> Q;
	Q.push(a);
	vis[a.x][a.y][a.z] = 1;
	while (!Q.empty()) {
		node temp;
		temp = Q.front();
		Q.pop();
		int x = temp.x, y = temp.y, z = temp.z;
		if (A[x][y][z]=='E') {
			printf("Escaped in %d minute(s).\n", temp.step);
			return;
		}
		for (int i = 0; i<6; i++) {
			int newx = x + dx[i], newy = y + dy[i], newz = z + dz[i];
			if (newx<L&&newy<R&&newz<C&&newx >= 0 && newy >= 0 && newz >= 0 && !vis[newx][newy][newz] && A[newx][newy][newz] != '#') {
				node newnode(newx, newy, newz);
				newnode.step = temp.step + 1;;
				vis[newx][newy][newz] = 1;
				Q.push(newnode);
			}
		}
	}
	printf("Trapped!\n");
}
int main()
{
	while (scanf("%d%d%d", &L, &R, &C), L+R+C) {
		node a;
		ans = 0;
		int kb1 = 1,kb2=1;
		for (int i = 0; i<L; i++)
			for (int j = 0; j<R; j++) {
				scanf("%s", A[i][j]);
				if(kb1)
					for (int k = 0; k<C; k++) {
					if (A[i][j][k] == 'S') {
						a.x = i;
						a.y = j;
						a.z = k;
						a.step = 0;
						kb1 = 0;
					}
				}
			}
		bfs(a);
	}
	return 0;
}