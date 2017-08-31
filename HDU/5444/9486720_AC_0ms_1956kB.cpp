#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

struct Tree
{
	int v;
	Tree *left, *right;
	Tree() :v(0), left(NULL), right(NULL) {}
};
Tree* newTree() { return new Tree(); }
void addTree(int key, Tree* root)
{
	if (key > root->v) {
		if (!root->right) {
			root->right = newTree();
			root = root->right;
			root->v = key;
			return;
		}
		else
			addTree(key, root->right);
	}
	else {
		if (!root->left) {
			root->left = newTree();
			root = root->left;
			root->v = key;
			return;
		}
		else
			addTree(key, root->left);
	}
}
void find(int key, Tree* root)
{
	if (root == NULL)return;
	if (root->v == key) {
		puts("");
		return;
	}
	else if(root->v>key){
		putchar('E');
		find(key, root->left);
	}
	else {
		putchar('W');
		find(key, root->right);
	}
}
void DeleteBiTree(Tree* u)
{
	if (u != NULL) {
		DeleteBiTree(u->left);
		DeleteBiTree(u->right);
		delete u;
		u = NULL;
	}
}
/*void print(Tree* root)
{
	if (root == NULL) return;
	printf("%d", root->v);
	print(root->left);
	print(root->right);
}*/
int main()
{
	int N;
	scanf("%d", &N);
	while (N--) {
		Tree *root = new Tree;
		int n = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int val = 0;
			scanf("%d", &val);
			if (i == 0) {
				root->v = val; 
				continue;
			}
			addTree(val,root);
		}
		//print(root);
		int s = 0;
		scanf("%d", &s);
		for (int i = 0; i < s; ++i) {
			int val = 0;
			scanf("%d", &val);
			find(val, root);
			//printf("\n");
		}
		//DeleteBiTree(root);
	}
	return 0;
}