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

// Deletes an element from the Linked List with a specific key
void deleteItem(Node **head_ref, int key)
{
  Node *curr_node = *head_ref, *prev;

  if (*head_ref == NULL)
  {
    cout << "This is an empty linked list" << endl;
    return;
  }

  // Case 1: Deleting the first element of the Linked List
  if (curr_node != NULL && curr_node->data == key)
  {
    *head_ref = curr_node->next;
    free(curr_node);
    return;
  }

  // Case 2: Deleting the node anywhere other than the one at the head_ref
  while (curr_node != NULL && curr_node->data != key)
  {
    prev = curr_node;
    curr_node = curr_node->next;
  }

  // Case 3: If the element is not present in the Linked List
  if (curr_node == NULL)
  {
    cout << "There is no element in the Linked List with the key: " << key << endl;
    return;
  }

  // Set the 'next' of the prev to that of curr_node;
  prev->next = curr_node->next;
  // Freeing up the Node referenced by the 'curr_node' pointer
  free(curr_node);
}

void deleteEntireList(Node **head_ref)
{
  Node *curr_node = *head_ref, *next_node;

  while (curr_node != NULL)
  {
    next_node = curr_node->next;
    free(curr_node);
    curr_node = next_node;
  }

  // Reset the 'head_ref' pointer to NULL
  *head_ref = NULL;
}

int getLength(Node *head_ref)
{
  int count = 0;
  Node *curr_node = head_ref;

  while (curr_node != NULL)
  {
    curr_node = curr_node->next;
    count++;
  }
  return count;
}

int testing()
{
  // Setting the initial head pointer to point to NULL as
  // there are no items present in the Linked List yet
  Node *head = NULL;

  // Insering new items into the Linked List
  append(&head, 11);
  append(&head, 12);
  append(&head, 13);
  append(&head, 14);
  push(&head, 12);
  printList(head);
  cout << "The length of the Linked List is: " << getLength(head) << endl;

  // Inserting new item at a specific location in the Linked List
  insertAt(head, 15);
  printList(head);
  cout << "The length of the Linked List is: " << getLength(head) << endl;

  // Deleting a single item from the Linked List
  // deleteItem(&head, 15);
  deleteItem(&head, 12);
  printList(head);
  cout << "The length of the Linked List is: " << getLength(head) << endl;

  // Delete the entire Linked List
  deleteEntireList(&head);
  printList(head);
  cout << "The length of the Linked List is: " << getLength(head) << endl;

  return 0;
}