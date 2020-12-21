#include <iostream>
#include "implementation.cpp"
using namespace std;

void reverseList(Node **head_ref)
{
  Node *prev = NULL, *next = NULL, *curr = *head_ref;

  if (*head_ref = NULL)
  {
    cout << "Empty Linked List!" << endl;
    return;
  }

  while (curr != NULL)
  {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }

  *head_ref = prev;
}

int main()
{
  Node *head = NULL;

  // Insering new items into the Linked List
  append(&head, 11);
  append(&head, 12);
  append(&head, 13);
  append(&head, 14);
  append(&head, 15);
  append(&head, 16);
  append(&head, 17);
  push(&head, 10);

  cout << "The Original Linked List: ";
  printList(head);
  cout << "The length of the Linked List is: " << getLength(head) << endl;

  cout << "The Reversed Linked List: ";
  reverseList(&head);
  printList(head);
  cout << "The length of the Linked List is: " << getLength(head) << endl;

  return 0;
}