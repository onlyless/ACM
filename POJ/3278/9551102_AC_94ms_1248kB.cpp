#include<iostream>
#include<cstdio>
#include<stack>
#include<queue>
using namespace std;
int ans[100005], vis[100005];
void bfs(int n, int k)
{
	queue<int> que;
	que.push(n);
	int x;
	while (!que.empty())
	{
		x = que.front();
		que.pop();
		vis[x] = 1;
		if (x == k)
		{
			printf("%d\n",ans[x]);
			break;
		}
		if (x - 1 >= 0 && vis[x - 1] == 0)
		{
			que.push(x - 1);
			ans[x - 1] = ans[x] + 1;
			vis[x - 1] = 1;
		}
		if (x + 1<100005 && vis[x + 1] == 0)
		{
			que.push(x + 1);
			ans[x + 1] = ans[x] + 1;
			vis[x + 1] = 1;
		}
		if (x * 2<100005 && vis[x * 2] == 0)
		{
			que.push(x * 2);
			ans[x * 2] = ans[x] + 1;
			vis[x * 2] = 1;
		}
	}
}
int main()
{
	int n = 0, k = 0;
	scanf("%d%d", &n, &k);
	bfs(n, k);
	return 0;
}