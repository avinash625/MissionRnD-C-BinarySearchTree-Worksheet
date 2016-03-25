/*
Given a Sorted Array of integers .Create a new Balanced Binary Search Tree from the Array
and return the head of the new BST .

Ex : Input : [1,6,10]
Output : A new BST which structure is as follows 
  6
 / \
1  10

A BST is said to be balanced ,when it satisifes the following property 

Every node's Difference of Left subtree height and right-subtree height is not more than 1 .

Below Tree is Not a Balanced BST ,as 1's left subtree has height of 0 ,but 
right subtree height is 2 
(Diff >1)

  1
   \
    3
   / \
  10  5

Note : Return head of newly created BST
Note : Return Null for invalid Inputs
Note : Donot create a new BST .
*/
#include <stdlib.h>
struct node{
	struct node * left;
	int data;
	struct node *right;
};

struct node * insert(struct node *root, int data)
{
	if (!root)
	{
		root = (struct node *)malloc(sizeof(struct node));
		root->data = data;
		root->left = NULL;
		root->right = NULL;
	}
	else
	{
		if (data > root->data)
			root = insert(root->right, data);
		else
			root = insert(root->left, data);
	}
	return root;
}
struct node * convert_array_to_bst(int *arr, int len){

	int root_value;
	struct node *temp = NULL, *root = NULL;
	int i, data;
	root_value = len / 2;
	root = insert(root, arr[root_value]);
	for (i = 0; i < root_value; i++)
	{
		root = insert(root, arr[i]);
	}
	for (i = root_value + 1; i < len; i++)
		root = insert(root, arr[i]);
	return root;
}