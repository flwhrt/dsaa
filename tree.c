#include <stdlib.h>

struct treeNode {
	int val;
	struct treeNode *left;
	struct treeNode *right;
};

struct treeNode *makeEmpty(struct treeNode *tree)
{
	if(tree != NULL) {
		makeEmpty(tree->left);
		makeEmpty(tree->right);
		free(tree);
	}
	return NULL;
}

struct treeNode *find(int x, struct treeNode *tree)
{
	if (tree == NULL)
		return NULL;
	if(x < tree->val)
		return find(x, tree->left);
	else if (x > tree->val)
		return find(x, tree->right);
	else
		return tree;
}

struct treeNode *findMin(struct treeNode *tree)
{
	if (tree == NULL)
		return NULL;
	if (tree->left == NULL)
		return tree;
	else
		return findMin(tree->left);
}
struct treeNode *findMax(struct treeNode *tree)
{
	if(tree != NULL)
		while(tree->right != NULL)
			tree = tree->right;
	return tree;
}

struct treeNode *insert(int x, struct treeNode *tree)
{
	if(tree == NULL) {
		tree = malloc(sizeof(struct treeNode));
		tree->val = x;
		tree->left = tree->right = NULL;
	} else if(x < tree->val)
		tree->left = insert(x, tree->left);
	else if(x > tree->val)
		tree->right = insert(x, tree->right);
	return tree;
}
