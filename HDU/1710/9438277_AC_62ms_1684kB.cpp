#include<iostream>
#include<cstdio>
#include<string>
#include<cstdlib>
using namespace std;
int N;
void build(int n, int *s1, int* s2, int* s)
{
	if (n <= 0)return;
	int p = 0;
	for (int i = 0; i < n; ++i)
		if (s2[i] == s1[0])
			p = i;
	build(p, s1 + 1, s2, s);
	build(n - p - 1, s1 + p + 1, s2 + p + 1,s + p);
	s[n - 1] = s1[0];
}
int main()
{
	int s1[1000], s2[1000], s[1000];
	while (scanf("%d", &N)!=EOF) {
		for (int i = 0; i < N; ++i) {
			scanf("%d", &s1[i]);
		}
		for (int i = 0; i < N; ++i) {
			scanf("%d", &s2[i]);
		}
		int n = N;
		build(n, s1, s2, s);
		s[n] = '\0';
		int t = 0;
		for (int i = 0; i < N; ++i) {
			if (!t)
				t = 1;
			else
				printf(" ");
			printf("%d", s[i]);
		}
		printf("\n");
	}
	return 0;
}