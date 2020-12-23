#include <iostream>
using namespace std;

class Node
{
public:
  int key;
  Node *left, *right;

  Node *newNode(int data);
  Node *insertNode(Node *node, int data);
  Node *in_order_successor(Node *node);
  Node *deleteNode(Node *root, int data);
  void inOrderTraversal(Node *root);
  void preOrderTraversal(Node *root);
  void postOrderTraversal(Node *root);
};

Node *Node::newNode(int data)
{
  Node *temp = (Node *)malloc(sizeof(Node));
  temp->key = data;
  temp->left = temp->right = NULL;
  return temp;
}

Node *Node::insertNode(Node *node, int data)
{
  if (node == NULL)
  {
    return newNode(data);
  }
  if (data < node->key)
  {
    node->left = insertNode(node->left, data);
  }
  else if (data > node->key)
  {
    node->right = insertNode(node->right, data);
  }
}

// The argument '*node' being passed is the 'right' to the root node
Node *Node::in_order_successor(Node *node)
{
  Node *newVal = node;
  while (newVal->left != NULL)
  {
    newVal = newVal->left;
  }
  return newVal;
}

Node *Node::deleteNode(Node *root, int data)
{
  if (root == NULL)
  {
    cout << "This BST is empty!" << endl;
    return root;
  }

  if (data < root->key)
  {
    root->left = deleteNode(root->left, data);
  }
  else if (data > root->key)
  {
    root->right = deleteNode(root->right, data);
  }
  else
  {
    // One Child Node
    if (root->left == NULL)
    {
      Node *temp = root->right;
      free(root);
      return temp;
    }
    else if (root->right == NULL)
    {
      Node *temp = root->left;
      free(root);
      return temp;
    }

    // Two Child Node

    // Choosing In Order Successor
    Node *successor = in_order_successor(root->right);
    root->key = successor->key;
    root->right = deleteNode(root->right, successor->key);
  }
  return root;
}

void Node::inOrderTraversal(Node *root)
{
  if (root != NULL)
  {
    inOrderTraversal(root->left);
    cout << root->key;
    inOrderTraversal(root->right);
  }
}

void Node::preOrderTraversal(Node *root)
{
  cout << root->key;
  preOrderTraversal(root->left);
  preOrderTraversal(root->right);
}

void Node::postOrderTraversal(Node *root)
{
  postOrderTraversal(root->left);
  postOrderTraversal(root->right);
  cout << root->key;
}
