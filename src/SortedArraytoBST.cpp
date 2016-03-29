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
struct node *insert(struct node *root,int *arr, int start, int end)
{
	struct node *temp;
	int middle = (start + end) / 2;
	if (start > end)
		return NULL;
	if (start == end)
	{
		temp = (struct node *)malloc(sizeof(struct node));
		temp->data = arr[middle];
		temp->left = temp->right = NULL;
	}
	else
	{
		temp = (struct node*)malloc(sizeof(struct node));
		temp->data = arr[middle];
		temp->left = insert(temp, arr, start, middle - 1);
		temp->right = insert(temp, arr, middle + 1, end);
	}
	return temp;
}
struct node * convert_array_to_bst(int *arr, int len){
	struct node *root = NULL;
	if (arr == NULL)
		return NULL;
	else
	{
		root = insert(root,arr, 0, len - 1);
	}
	return root;
}