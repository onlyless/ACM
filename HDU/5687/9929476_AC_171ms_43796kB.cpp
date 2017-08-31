#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
const int maxn = 26;
struct Trie
{
	Trie *next[maxn];
	int v;
	Trie() {
		v = 0;
		memset(next, NULL, sizeof(next));
	}
};
Trie* root;
void insertTrie(string str)
{
	int len = str.size();
	Trie *p = root;
	for (int i = 0; i < len; i++) {
		int id = str[i] - 'a';
		if (!p->next[id]) {
			p->next[id] = new Trie();
			p->next[id]->v = 1;
			p = p->next[id];
		}
		else {
			p->next[id]->v++;
			p = p->next[id];
		}
	}
}
void release(Trie *p)
{
	if (p == NULL)
		return;
	for (int i = 0; i<maxn; i++)
		if (p->next[i])
			release(p->next[i]);
	p = NULL;
	delete p;
	return;
}
void deleteTrie(string str)
{
	int len = str.size();
	Trie *p = root, *pre;
	int i = 0;
	for (i = 0; i < len; i++) {
		int id = str[i] - 'a';
		if (p->next[id]) {
			pre = p;
			p = p->next[id];
		}
		else break;
	}
	if (str[i] == '\0') {
		int num = p->v;
		Trie *q = root;
		release(p);
		pre->next[str[len - 1] - 'a'] = NULL;
		for (int i = 0; i < len - 1; i++) {
			q = q->next[str[i] - 'a'];
			q->v -= num;
		}
	}
}
void searchTrie(string str)
{
	int len = str.size();
	Trie *p = root;
	for (int i = 0; i < len; i++) {
		int id = str[i] - 'a';
		if (!p->next[id]) {
			printf("No\n");
			return;
		}
		p = p->next[id];
	}
	if (p->v < 1)
		printf("No\n");
	else printf("Yes\n");
	return;
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	root = new Trie();
	while (n--) {
		char s1[10];
		char s2[35];
		scanf("%s%s", s1, s2);
		switch (s1[0])
		{
		case 'i':insertTrie(s2); break;
		case 's':searchTrie(s2); break;
		case 'd':deleteTrie(s2); break;
		default:
			break;
		}
	}
	release(root);
	return 0;
}
