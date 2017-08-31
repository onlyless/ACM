#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int pre[100005];
int cnt[100005];
int find(int num)
{
	int i = num;
	while (i != pre[i]) {
		i = pre[i];
	}
	return i;
}
int main()
{
	int a = 0, b = 0;
	while (1) {
		memset(pre, 0, sizeof(pre));
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1; i <= 100000; i++)
			pre[i] = i;
		int ju = 0;
		while (1) {
			scanf("%d%d", &a, &b);
			if (a == -1 && b == -1)goto hh;
			if (a == 0 && b == 0)break;
			if (find(b) == find(a))ju = 1;
			pre[find(b)] = find(a);
		}
		for (int i = 1; i <= 100000; i++) {
			cnt[find(i)]++;
		}
		int op = 0;
		for (int i = 1; i <= 100000; i++)
			if (cnt[i] > 1)
				op++;
		if (ju||op>1)printf("No\n");
		else printf("Yes\n");
	}
hh:
	return 0;
}