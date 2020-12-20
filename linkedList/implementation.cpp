#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
};

// Used double pointer here for the 'head_ref' as the 'next' param in class 'Node' is a pointer type.
// So if we want to get the address of the head in the last Node then we will use a pointer to the 'next' pointer
// We can then dereference the double pointer to eventually get the address of the last Node object

// Adds a new item at the start of the Linked List
void push(Node **head_ref, int new_value)
{
  Node *new_node = new Node();
  new_node->data = new_value;
  new_node->next = *head_ref;
  *head_ref = new_node;
}

// Inserts a new item at a specific location in the Linked List
void insertAt(Node *prev_node, int new_value)
{
  if (prev_node == NULL)
  {
    cout << "The previous node seems to be NULL" << endl;
    return;
  }
  Node *new_node = new Node();
  new_node->data = new_value;
  new_node->next = prev_node->next;
  prev_node->next = new_node;
}

// Inserts the new item at the end of the Linked List
void append(Node **head_ref, int new_value)
{
  Node *new_node = new Node();
  new_node->data = new_value;
  new_node->next = NULL;

  Node *last = *head_ref;

  if (*head_ref == NULL)
  {
    *head_ref = new_node;
    return;
  }

  while (last->next != NULL)
  {
    last = last->next;
  }

  last->next = new_node;
}

// Prints all the Linked List items
void printList(Node *node)
{
  while (node != NULL)
  {
    cout << node->data << " ";
    node = node->next;
  }
  cout << "\n";
}
