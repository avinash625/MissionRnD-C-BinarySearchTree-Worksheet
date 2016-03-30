/*
Given a Binary Search Tree and a Node(temp).Find the Closest Distance from the Node to 
any leaf of the Tree.
(Least number of Edges needed to be travelled to go to the Node )

Ex : Consider the below tree .
      2
     / \
,   1   3
         \
         14
For 3 ,Output is 1 . As its closest leaf is 14 and 3 is at a distance of 1 to 14 .

Ex 2: Consider the below tree .
    2
   / \
  1   3
       \
        14
        / \
       9   20
      /      \
     6       25
For 3 ,Output is now 2 . As closest leaf to 3 is 1 and 3 is at a distance of 2 to 1 .
(through root 2 )

For 14 ,O/P : 2
For 2 , O/P : 1

Return -1 ,for Invalid Inputs
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
  struct node * left;
  int data;
  struct node *right;
};
int minimum_height(struct node *root)
{
	if (root->left == NULL && root->right == NULL)
		return 0;
	else if (root->left == NULL)
		return minimum_height(root->right) + 1;
	else if (root->right == NULL)
		return minimum_height(root->left) + 1;
	else
		return minimum_height(root->left) > minimum_height(root->right) ? minimum_height(root->right) + 1 : minimum_height(root->left) + 1;
	return 0;
}
void get_root_node_distance(struct node *root, struct node *temp, int *count)
{
	if (root->data == temp->data)
		return;
	else
	{
		if (root->data > temp->data)
		{
			(*count) = (*count) + 1;
			get_root_node_distance(root->left, temp, count);
		}
		else
		{
			(*count) = (*count) + 1;
			get_root_node_distance(root->right, temp, count);
		}
	}
}
int get_closest_leaf_distance(struct node *root, struct node *temp)
{
	int count = 0;
	int node_to_leaf = 0, root_to_node = 0, root_to_leaf = 0;
	if (!temp)
		return -1;
	if (root->data > temp->data)
		return get_closest_leaf_distance(root->left, temp);
	else
	{
		node_to_leaf = minimum_height(temp);
		root_to_leaf = minimum_height(root);
		get_root_node_distance(root, temp,&count);
		root_to_node = count;
		if (node_to_leaf < (root_to_leaf + root_to_node))
			return node_to_leaf;
		else
			return (root_to_leaf + root_to_node);
	}
}