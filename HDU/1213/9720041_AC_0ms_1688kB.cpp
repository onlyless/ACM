#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;
int pre[1010];
int find(int x)
{
	int i = x, j;
	while (pre[i] != i) {
		i = pre[i];
	}
	int r = x;
	while (i != r) {
		j = pre[r];
		pre[r] = i;
		r = j;
	}
	return i;
}
int main()
{
	int T;
	scanf("%d", &T);
	int num = 0;
	while (T--) {
		memset(pre, 0, sizeof(pre));
		int N = 0, M = 0;
		scanf("%d%d", &N, &M);
		for (int i = 1; i <=N; i++)
			pre[i] = i;
		for (int i = 0; i < M; i++) {
			int a = 0, b = 0;
			scanf("%d%d", &a, &b);
			int x = find(a);
			int y = find(b);
			if(x!=y)
				pre[x] = y;
		}
		int cnt = 0;
		for (int i = 1; i <= 1000; i++) {
			if (pre[i] == i)cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}