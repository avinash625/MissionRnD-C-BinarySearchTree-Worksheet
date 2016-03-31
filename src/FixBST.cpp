/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

  5
 / \
2   3
 \
  30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

         9
        / \
       4   1
      /     \
    20      30
Nodes 1 and 20 need to be fixed here .

*/
#include <stdio.h>
#include <stdlib.h>
struct node{
	struct node * left;
	int data;
	struct node *right;
};
struct node *misplaced1 = NULL, *misplaced2 = NULL, *prev = NULL,*parent = NULL,*child = NULL;
void init(void)
{
	child = parent = misplaced1 = misplaced2 = prev = NULL;
}
void swap(struct node *first, struct node *second)
{
	int number = first->data;
	first->data = second->data;
	second->data = number;
}
void modified_inorder(struct node *root)
{
	if (!root)
		return;
	else
	{
		modified_inorder(root->left);
		if (prev == NULL)
			prev = root;
		else if (root->data < prev->data)
		{
			if (misplaced1 == NULL)
				misplaced1 = prev;
			else if (misplaced2 == NULL)
			{
				misplaced2 = root;
				swap(misplaced1, root);
			}
		}
		prev = root;
		modified_inorder(root->right);
	}
}
void get_parent(struct node *root)
{
	if (!root)
		return;
	if (root->data == misplaced1->data)
		return;
	if (root->left && root->left->data == misplaced1->data)
		parent = root;
	else if (root->right && root->right->data == misplaced1->data)
		parent = root;
	else
	{
		get_parent(root->left);
		get_parent(root->right);
	}
}
void get_child(struct node *root)
{
	if (misplaced1->left == NULL && misplaced1->right == NULL)
		return;
	if (misplaced1->right == NULL)
		child = misplaced1->left;
	else
		child = misplaced1->right;
}
void fix_bst(struct node *root){
	init();
	if (!root)
		return;
	else
	{
		modified_inorder(root);
		if (misplaced2 == NULL)
		{
			get_parent(root);
			if (parent == NULL)
			{
				swap(misplaced1, misplaced1->right); return;
			}
			get_child(root);
			if (child == NULL)
			{
				swap(misplaced1, parent); return;
			}
			else
			{
				if (parent->data > misplaced1->data)
					swap(parent, misplaced1);
			}
		}
	}
}