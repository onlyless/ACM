#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
int A[5][5];
struct Node
{
	int x, y, step;
	Node(int a, int b, int c) :x(a), y(b), step(c) {}
};
int num = 0;
int way[4][2] = { 1,0,0,1,-1,0,0,-1 };
bool BFS(int a, int b, bool ak[5][5]);
void BFS(int a, int b)
{
	Node temp(a, b, 0);
	queue<Node> Q;
	Q.push(temp);
	printf("(0, 0)\n");
	bool vis[5][5];
	vis[0][0] = 1;
	while (!Q.empty()) {
		temp = Q.front();
		Q.pop();
		int x = temp.x, y = temp.y;
		if (x == 4 && y == 4) break;
		for (int i = 0; i < 4; i++) {
			int newx = x + way[i][0], newy = y + way[i][1];
			if (newx < 5 && newy < 5 && newx >= 0 && newy >= 0 && vis[newx][newy] != 1 && A[newx][newy] != 1) {
				Q.push(Node(newx, newy, temp.step+1));
				vis[newx][newy] = 1;
				bool ak[5][5];
				for (int i = 0; i < 5; i++)
					for (int j = 0; j < 5; j++)
						ak[i][j] = vis[i][j];
				if (BFS(newx, newy, ak)) {
					printf("(%d, %d)\n", newx, newy);
					break;
				}
			}
		}
	}
}
bool BFS(int a, int b,bool ak[5][5])
{
	Node temp(a, b, 0);
	queue<Node> Q;
	Q.push(temp);
	while (!Q.empty()) {
		temp = Q.front();
		Q.pop();
		int x = temp.x, y = temp.y;
		if (x == 4 && y == 4) return true;
		for (int i = 0; i < 4; i++) {
			int newx = x + way[i][0], newy = y + way[i][1];
			if (newx < 5 && newy < 5 && newx >= 0 && newy >= 0 && ak[newx][newy] != 1 && A[newx][newy] != 1) {
				Q.push(Node(newx, newy, temp.step+1));
				ak[newx][newy] = 1;
			}
		}
	}
	return false;
}
int main()
{
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			scanf("%d", &A[i][j]);
	BFS(0, 0);
	return 0;
}