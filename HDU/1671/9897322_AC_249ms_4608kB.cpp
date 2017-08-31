#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn = 10;
struct Trie
{
	Trie *next[maxn];
	int v;
	Trie()
	{
		v = 0;
		memset(next, NULL, sizeof(next));
	}
};
Trie *root;
void createTrie(char *str)
{
	int len = strlen(str);
	Trie *p = root, *q;
	len--;
	for (int i = 0; i<len; i++)
	{
		int id = str[i] - '0';
		if (p->next[id] == NULL)
		{
			p->next[id] = new Trie();
			p = p->next[id];
		}
		else
		{
			p = p->next[id];
		}
	}
}
bool findTrie(char *str)
{
	int len = strlen(str);
	Trie *p = root;
	for (int i = 0; i<len; i++)
	{
		int id = str[i] - '0';
		if (p->next[id] != NULL)
		{
			p = p->next[id];
			if (i + 1 == len/*&&p->next[str[i + 1] - '0'] != NULL*/)
				return 1;
		}
		else return 0;
	}
	return 0;
}
void release(Trie *p)
{
	if (p == NULL)
		return;
	for (int i = 0; i<maxn; i++)
		if (p->next[i] != NULL)
			release(p->next[i]);
	delete p;
	root = NULL;
	return;
}
int main()
{
	int T = 0;
	scanf("%d", &T);
	while (T--) {
		int n = 0;
		scanf("%d", &n);
		root = new Trie();
		int te = 0,ju=0;
		char num[10005][10];
		for (int i = 0; i < n; i++) {
			scanf("%s", num[te]);
			createTrie(num[te]);
			te++;
		}
		for (int i = 0; i < n; i++) {
			if (findTrie(num[i]))
				ju = 1;
		}
		if (ju)printf("NO\n");
		else printf("YES\n");
		release(root);
	}
	return 0;
}