#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<stack>
using namespace std;
int n;
int ans;
struct Group
{
	char A[10][10];
	int x;
};

void dfs(Group g,int k)
{
	if (k == 0) {
		ans++;
		return;
	}
	for (int i = g.x + 1; i <= n - k; ++i) {
		for (int j = 0; j < n; ++j) {
			if (g.A[i][j] == '#') {
				Group temp ;
				temp = g;
				temp.x = i;
				for (int t = i + 1; t < n; t++)
					temp.A[t][j] = '.';
				dfs(temp, k - 1);
			}
		}
	}
}
int main()
{
	int  k;
	while (scanf("%d%d", &n, &k),n!=-1||k!=-1) {
		Group g;
		g.x = -1;
		ans = 0;
		for (int i = 0; i < n; i++)
			scanf("%s", g.A[i]);
		dfs(g, k);
		printf("%d\n", ans);
	}
	return 0;
}