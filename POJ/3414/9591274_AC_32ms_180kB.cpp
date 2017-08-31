#include<iostream>
#include<queue>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

int A, B, C;
struct node
{
	int a, b;
	int step;
	vector<int> steps;
	node(int x, int y) :a(x), b(y) {}
};
int ans;
node action(const int& num, node k)
{
	node temp = k;
	switch (num) {
	case 0:temp.a = A; break;
	case 1:temp.b = B; break;
	case 2:if(temp.b!=0)temp.a = 0; break;
	case 3:if(temp.a!=0)temp.b = 0; break;
	case 4:if (temp.a == A||temp.b==0)break;
		   if (temp.b + temp.a>A) {
			   int t = A - temp.a;
			   temp.a = A;
			   temp.b -= t;
		   }else{
			   temp.a += temp.b;
			   temp.b = 0;
		   }
		   break;
	case 5:if (temp.b == B||temp.a==0)break;
		   if (temp.a + temp.b>B) {
			   int t = B - temp.b;
			   temp.b = B;
			   temp.a -= t;
			} else {
			   temp.b += temp.a;
			   temp.a = 0;
		   }
		   break;
	default:break;
	}
	return temp;
}
bool vis[105][105];
vector<int> dfs(int a, int b)
{
	node beg(0, 0);
	memset(vis, 0, sizeof(vis));
	beg.step = 0;
	queue<node> Q;
	vis[0][0] = 1;
	Q.push(beg);
	while (!Q.empty()) {
		node temp = Q.front();
		Q.pop();
		if (temp.a == C || temp.b == C) {
			ans = temp.step;
			return temp.steps;
		}
		for (int i = 0; i < 6; i++) {
			node newnode = action(i, temp);
			if (!vis[newnode.a][newnode.b]) {
				if (newnode.a == temp.a&&newnode.b == temp.b)continue;
				newnode.step++;
				newnode.steps.push_back(i);
				vis[newnode.a][newnode.b] = 1;
				Q.push(newnode);
			}
		}
	}
	printf("impossible\n");
	vector<int> te;
	return te;
}
int main()
{
	vector<int> ive;
	scanf("%d%d%d", &A, &B, &C);
	ive = dfs(A, B);
	if (ive.begin()!=ive.end()) {
		printf("%d\n", ans);
		for (vector<int>::iterator i = ive.begin(); i != ive.end(); ++i) {
			switch (*i)
			{
			case 0:printf("FILL(1)\n"); break;
			case 1:printf("FILL(2)\n"); break;
			case 2:printf("DROP(1)\n"); break;
			case 3:printf("DROP(2)\n"); break;
			case 4:printf("POUR(2,1)\n"); break;
			case 5:printf("POUR(1,2)\n"); break;
			default:
				break;
			}
		}
	}
	return 0;
}