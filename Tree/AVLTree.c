#include <stdio.h>
#include <stdlib.h>

typedef struct _AVLTreeNode
{
	int data;
	int height;
	struct _AVLTreeNode* left;
	struct _AVLTreeNode* right;
} AVLTreeNode;

AVLTreeNode* createAVLTree(int data);					// Create and return new AVL Tree Node
AVLTreeNode* AVLInsert(AVLTreeNode* tree, int data);	// Insertion new AVL Tree Node without rebalancing.
AVLTreeNode* AVLDelete(AVLTreeNode* tree, int data);	// Deletion a AVL Tree Node which has the data
AVLTreeNode* AVLRebalance(AVLTreeNode* tree);			// Rebalance a current AVL tree (traversal and rebalance)
AVLTreeNode* AVLRebalanceProcedure(AVLTreeNode* tree);	// Rebalance a current AVL tree (procedure)
AVLTreeNode* leftRotation(AVLTreeNode* tree);			// Left-rotation the tree
AVLTreeNode* rightRotation(AVLTreeNode* tree);			// Right-rotation the tree
int getHeight(AVLTreeNode* tree);						// Get the height of target tree node.
int getHeightDelta(AVLTreeNode* tree);					// Get delta of height of subtree.
void setHeight(AVLTreeNode* tree);						// Update the height of tree node.
void preorderTraversal(AVLTreeNode* tree);				// Preorder traversal of a AVL Tree

int main()
{
	AVLTreeNode* root = NULL;
	int data, cnt = 0;
	char dummy;

	printf("Insert node to AVL tree:\n");

	while(cnt < 50)
	{
		gets(&dummy);
		if(dummy == 0)
		{
			break;
		}
		data = atoi(&dummy);
		root = AVLInsert(root, data);
		cnt++;
	}

	root = AVLRebalance(root);

	printf("Preorder traversal of the constructed AVL tree is\n");
	preorderTraversal(root);
	printf("\n");

	printf("Preorder traversal after delegation of ");
	scanf("%d", &data);
	root = AVLDelete(root, data);
	preorderTraversal(root);
	printf("\n");

	return 0;
}

// Create and return new AVL Tree Node
AVLTreeNode* createAVLTree(int data)
{
	AVLTreeNode* newNode = (AVLTreeNode*)malloc(sizeof(AVLTreeNode));
	newNode->data = data;
	newNode->height = 0;
	newNode->left = NULL;
	newNode->right = NULL;
}

// Insertion new AVL Tree Node likely binary-search trees.
AVLTreeNode* AVLInsert(AVLTreeNode* tree, int data)
{
	if (tree == NULL)
	{
		tree = createAVLTree(data);
		return tree;
	}

	if (data < tree->data)
	{
		tree->left = AVLInsert(tree->left, data);
	}
	else
	{
		tree->right = AVLInsert(tree->right, data);
	}

	setHeight(tree);

	return tree;
}

// Deletion a AVL Tree Node which has the data
AVLTreeNode* AVLDelete(AVLTreeNode* tree, int data)
{
	if (tree == NULL) return NULL;
	
	if (data == tree->data)
	{
		AVLTreeNode* temp, * cur;
		// If it is leaf tree, just free and return NULL.
		if (tree->left == NULL && tree->right == NULL)
		{
			free(tree);
			return NULL;
		}
		// select a subtree which height is more than other.
		if (getHeightDelta(tree) > 0) // left subtree(find maximum value)
		{
			temp = NULL;
			cur = tree->left;
			while (cur->right != NULL) // find biggest value in left subtree.
			{
				temp = cur;
				cur = cur->right;
			}
			
			if (temp != NULL)
			{
				temp->right = cur->left;
				cur->left = tree->left;
			}
			cur->right = tree->right;
			temp = tree;
			tree = cur;
			free(temp);
		}
		else // right subtree(find minimum value)
		{
			temp = NULL;
			cur = tree->right;
			while (cur->left != NULL) // find smallest value in left subtree.
			{
				temp = cur;
				cur = cur->left;
			}

			if (temp != NULL)
			{
				temp->left = cur->right;
				cur->right = tree->right;
			}
			cur->left = tree->left;
			temp = tree;
			tree = cur;
			free(temp);
		}
	}
	else if (data < tree->data) // binary-search to find target value (data < root)
	{
		tree->left = AVLDelete(tree->left, data);
	}
	else // binary-search to find target value (data >= root)
	{
		tree->right = AVLDelete(tree->right, data);
	}

	setHeight(tree);
	tree = AVLRebalanceProcedure(tree);

	return tree;
}

// Rebalance a current AVL tree (traversal and rebalance)
AVLTreeNode* AVLRebalance(AVLTreeNode* tree)
{
	if (tree == NULL) return NULL;

	tree->left = AVLRebalance(tree->left);
	tree->right = AVLRebalance(tree->right);
	tree = AVLRebalanceProcedure(tree);
}

// Rebalance a current AVL tree (procedure)
AVLTreeNode* AVLRebalanceProcedure(AVLTreeNode* tree)
{
	int delta = getHeightDelta(tree);

	if (delta > 1 && getHeightDelta(tree->left) < 0) // left rotation
	{
		tree->left = leftRotation(tree->left);
	}
	if (delta > 1) // right rotation
	{
		tree = rightRotation(tree);
	}
	if (delta < -1 && getHeightDelta(tree->right) > 0) // right rotation
	{
		tree->right = rightRotation(tree->right);
	}
	if (delta < -1) // leftRotation
	{
		tree = leftRotation(tree);
	}

	return tree;
}

// Left-rotation the tree
AVLTreeNode* leftRotation(AVLTreeNode* tree)
{
	AVLTreeNode* temp = tree;

	tree = tree->right;
	temp->right = tree->left;
	setHeight(temp);
	tree->left = temp;
	setHeight(tree);

	return tree;
}

// Right-rotation the tree
AVLTreeNode* rightRotation(AVLTreeNode* tree)
{
	AVLTreeNode* temp = tree;

	tree = tree->left;
	temp->left = tree->right;
	setHeight(temp);
	tree->right = temp;
	setHeight(tree);

	return tree;
}

// Get the height of target tree node.
int getHeight(AVLTreeNode* tree)
{
	if (tree == NULL)
		return -1;
	return tree->height;
}

// Get delta of height of subtree.
// "delta > 0" means that left subtree is deeper than right.
int getHeightDelta(AVLTreeNode* tree)
{
	int delta = getHeight(tree->left) - getHeight(tree->right);
	return delta;
}

// Update the height of tree node.
void setHeight(AVLTreeNode* tree)
{
	int left = getHeight(tree->left);
	int right = getHeight(tree->right);
	tree->height = (left > right ? left : right) + 1;
}

// Preorder traversal of a AVL Tree
void preorderTraversal(AVLTreeNode* tree)
{
	if (tree == NULL) return;
	printf("%d ", tree->data);
	preorderTraversal(tree->left);
	preorderTraversal(tree->right);
}