#include<iostream>
#include<cstring>
#include<string>
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
Trie *root;
void createTrie(string str)
{
	int len = str.size();
	Trie* p = root, *q;
	for (int i = 0; i < len; i++) {
		int id = str[i] - 'a';
		if (p->next[id] == NULL) {
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
string findTrie(string str)
{
	int len = str.size();
	Trie *p = root;
	for (int i = 0; i < len; i++) {
		int id = str[i] - 'a';
		if (p->next[id] != NULL) {
			p = p->next[id];
			if (p->v == 1)
				return string(str.begin(), str.begin()+i+1);
		}
	}
	return str;
}
void release(Trie *p)
{
	if (p == NULL)
		return;
	for (int i = 0; i<maxn; i++)
		if (p->next[i] != NULL)
			release(p->next[i]);
	free(p);
	root = NULL;
	return;
}
int main()
{
	string s[1005];
	int n = 0;
	root = new Trie();
	while (cin >> s[n++]) {
		createTrie(s[n - 1]);
	}
	for (int i = 0; i < n; i++) {
		cout << s[i] <<" "<< findTrie(s[i]) << endl;
	}
	release(root);
	return 0;
}