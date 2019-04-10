#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"


typedef struct TreeNode
{
	void* ptr;
	char data;
	struct TreeNode* left_child;
	struct TreeNode* right_child;
} TreeNode, *pTreeNode;


int TraversalOfTree(pTreeNode tree_node)
{
	if (tree_node == NULL)
		return -1;
	printf("%c__", tree_node->data);
	TraversalOfTree(tree_node->left_child);
	TraversalOfTree(tree_node->right_child);
}

int CalculateHeight(pTreeNode tree_node)
{
	if (tree_node == NULL)
		return 0;
	int left_child_tree_height = CalculateHeight(tree_node->left_child);
	int right_child_tree_height = CalculateHeight(tree_node->right_child);
	return left_child_tree_height > right_child_tree_height ? left_child_tree_height + 1 : right_child_tree_height + 1;
}

int CalculateLeaves(pTreeNode tree_node,int *p)
{
	if (tree_node == NULL)
		return 0 ;
	if (tree_node->left_child == NULL && tree_node->right_child == NULL)
	{
		(*p)++;
	}
	CalculateLeaves(tree_node->left_child,p);
	CalculateLeaves(tree_node->right_child,p);
	return 0;
}

int func(pTreeNode root)
{
	int i = 0;
	CalculateLeaves(root, &i);
	return i;

}





int main()
{
	
	TreeNode tree_node_A = { NULL,'A',NULL,NULL };
	TreeNode tree_node_B = { NULL,'B',NULL,NULL };
	TreeNode tree_node_C = { NULL,'C',NULL,NULL };
	TreeNode tree_node_D = { NULL,'D',NULL,NULL };
	TreeNode tree_node_E = { NULL,'E',NULL,NULL };
	TreeNode tree_node_F = { NULL,'F',NULL,NULL };
	TreeNode tree_node_G = { NULL,'G',NULL,NULL };
	TreeNode tree_node_H = { NULL,'H',NULL,NULL };

	tree_node_A.left_child = &tree_node_B;
	tree_node_A.right_child = &tree_node_F;

	tree_node_B.left_child = NULL;
	tree_node_B.right_child = &tree_node_C;

	tree_node_C.left_child = &tree_node_D;
	tree_node_C.right_child = &tree_node_E;

	tree_node_D.left_child = NULL;
	tree_node_D.right_child = NULL;

	tree_node_E.left_child = NULL;
	tree_node_E.right_child = NULL;

	tree_node_F.left_child = NULL;
	tree_node_F.right_child = &tree_node_G;

	tree_node_G.left_child = &tree_node_H;
	tree_node_G.right_child = NULL;

	tree_node_H.left_child = NULL;
	tree_node_H.right_child = NULL;

	/*pLinkStackMan link_stack_manager = (pLinkStackMan)Init_LinkStack();
	Push_LinkStack(link_stack_manager, (DataType)&tree_node_A);
	Push_LinkStack(link_stack_manager, (DataType)&tree_node_B);
	Push_LinkStack(link_stack_manager, (DataType)&tree_node_C);
	Push_LinkStack(link_stack_manager, (DataType)&tree_node_D);
	Push_LinkStack(link_stack_manager, (DataType)&tree_node_E);
	Push_LinkStack(link_stack_manager, (DataType)&tree_node_F);
	Push_LinkStack(link_stack_manager, (DataType)&tree_node_G);
	Push_LinkStack(link_stack_manager, (DataType)&tree_node_H);*/

	

	TraversalOfTree(&tree_node_A);
	printf("-----------------------------\n");

	printf("%d---\n",CalculateHeight(&tree_node_A));
	printf("%d---\n",func(&tree_node_A));
	printf("%d---\n",func(&tree_node_A));
	printf("%d---\n",func(&tree_node_A));
	system("Pause");
	return 0;
}













