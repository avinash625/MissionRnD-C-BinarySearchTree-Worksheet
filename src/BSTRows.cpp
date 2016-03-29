/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};


int hgt(struct node *root)
{
	int ht;
	if (!root)
		return 0;
	else
		ht =  hgt(root->left) > hgt(root->right) ? hgt(root->left) : hgt(root->right);
	return ht + 1;
}
void get_elements(struct node *root, int level, int *arr, int *index)
{
	if (level == 0)
	{
		arr[*index] = root->data;
		(*index)++;
	}
	else
	{
		get_elements(root->right, level - 1, arr, index);
		get_elements(root->left, level - 1, arr, index);
	}
}
int* BSTRighttoLeftRows(struct node* root)
{
	int arr[25] = { 0 }, ht, level, index = 0;
	if (!root)
		return NULL;
	else
	{
		ht = hgt(root);
		for (level = 0; level < ht; level++)
		{
			get_elements(root, level, arr, &index);
		}
	}
	return arr;
}
