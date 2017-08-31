#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int maxn = 26;
string s[50010];
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
int flag;
void createTrie(string str)
{
	int len = str.size();
	Trie* p = root, *q;
	for (int i = 0; i < len; i++) {
		int id = str[i] - 'a';
		if (p->next[id] == NULL) {
			q = new Trie();
			p->next[id] = q;
			p = p->next[id];
		}
		else {
			p = p->next[id];
		}
	}
	p->v = -1;
}
bool findTrie2(string str)
{
	bool ok = 1;
	int len = str.size();
	Trie *p = root;
	for (int i = 0; i < len; i++) {
		int id = str[i] - 'a';
		if (p->next[id] != NULL) {
			p = p->next[id];
			if (p->v == -1) {
				if(i+1==len)
				return true;
			}
		}
		else return false;
	}
	return false;
}
bool findTrie1(string str)
{
	int len = str.size();
	Trie *p = root;
	for (int i = 0; i < len; i++) {
		int id = str[i] - 'a';
		if (p->next[id] != NULL) {
			p = p->next[id];
			if (p->v == -1) {
				string temp(str.begin() + i + 1, str.end());
				if (findTrie2(temp))return true;
			}
		}
		else return false;
	}
	return false;
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
	int n = 0;
	root = new Trie();
	while (cin >> s[n++]) {
		createTrie(s[n - 1]);
	}
	for (int i = 0; i < n; i++) {
		if (findTrie1(s[i])) {
			cout << s[i] << endl;
		}
	}
	release(root);
	return 0;
}