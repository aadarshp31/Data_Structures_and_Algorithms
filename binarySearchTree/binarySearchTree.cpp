#include <iostream>
using namespace std;

class Node
{
public:
  int key;
  Node *left, *right;

  Node *newNode(int data);
  Node *insertNode(Node *node, int data);
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