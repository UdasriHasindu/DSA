#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int treeData;

// create tree node
typedef struct node
{
    treeData data;
    struct node *left;
    struct node *right;

} TreeNode;

// create tree
void CreateTree(TreeNode **root)
{
    *root = NULL;
}

// empty tree
bool isTreeEmpty(TreeNode *root)
{
    return (root == NULL);
}

TreeNode *InsertNode(TreeNode *root, treeData value)
{
    if (root == NULL)
    {
        TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));

        if (newNode == NULL)
        {
            printf("Can't allocate memory, insufficient memory\n");
            exit(1); // Exit on memory allocation failure.
        }

        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;

        return newNode; // Return the new node to be assigned as root or child.
    }

    // already have a root
    // left subtree
    else if (value < root->data)
    {
        root->left = InsertNode(root->left, value);
    }
    // right subtree
    else if (value > root->data)
    {
        root->right = InsertNode(root->right, value);
    }
    else
    {
        printf("Duplicate value inserted, %d is alread in the tree\n", value);
    }

    return root;
}

// preorder traversal (VLR)
void PreOrder(TreeNode *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);

        PreOrder(root->left);  // recursion until there is no left node
        PreOrder(root->right); // recursion until there is no right node
    }
}

// inorder traversal (LVR)
void InOrder(TreeNode *root)
{
    if (root != NULL)
    {
        InOrder(root->left);
        printf("%d ", root->data);
        InOrder(root->right);
    }
}

// postorder traversal (LRV)
void PostOrder(TreeNode *root)
{
    if (root != NULL)
    {
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%d ", root->data);
    }
}

int main()
{

    TreeNode *root;
    CreateTree(&root);

    // Insert nodes
    root = InsertNode(root, 50);
    root = InsertNode(root, 30);
    root = InsertNode(root, 70);
    root = InsertNode(root, 20);
    root = InsertNode(root, 40);
    root = InsertNode(root, 10);
    root = InsertNode(root, 60);
    root = InsertNode(root, 80);
    root = InsertNode(root, 90);
    root = InsertNode(root, 100);

    printf("Tree Traversals\n\n");

    printf("PreOrder: ");
    PreOrder(root);
    printf("\n\n");

    printf("InOrder: ");
    InOrder(root);
    printf("\n\n");

    printf("PostOrder: ");
    PostOrder(root);
    printf("\n\n");

    return 0;
}