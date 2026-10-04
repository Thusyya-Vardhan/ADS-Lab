#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Create a new node
Node *init(int key)
{
    Node *temp = malloc(sizeof(Node));

    temp->data = key;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Insert a node
Node *insert(Node *root, int key)
{

    if (root == NULL)
        return init(key);

    if (key <= root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}

// Search for a node
Node *search(Node *root, int key)
{

    if (root == NULL)
        return NULL;

    if (key == root->data)
        return root;

    if (key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}

// Find minimum node in a subtree
Node *findSuccessor(Node *root)
{

    if (root->left == NULL)
        return root;

    return findSuccessor(root->left);
}

// Delete a node
Node *deleteNode(Node *root, int key)
{

    // Node doesn't exist
    if (root == NULL)
        return NULL;

    // Search left subtree
    if (key < root->data)
    {

        root->left = deleteNode(root->left, key);
    }

    // Search right subtree
    else if (key > root->data)
    {

        root->right = deleteNode(root->right, key);
    }

    // Found the node
    else
    {

        // CASE 1: Leaf node
        if (root->left == NULL && root->right == NULL)
        {

            free(root);
            return NULL;
        }

        // CASE 2: Only right child
        if (root->left == NULL)
        {

            Node *temp = root->right;
            free(root);
            return temp;
        }

        // CASE 2: Only left child
        if (root->right == NULL)
        {

            Node *temp = root->left;
            free(root);
            return temp;
        }

        // CASE 3: Two children

        Node *temp = findSuccessor(root->right);

        // Copy successor's value
        root->data = temp->data;

        // Delete the original successor
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main()
{
    Node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 35);
    inorder(root);
    Node* temp = search(root,40);
    if(temp != NULL){
        printf("\nKey found\n");
    }else{
        printf("\nKey Not Found\n");
    }

    root = deleteNode(root,30);
    inorder(root);

    return 0;
}