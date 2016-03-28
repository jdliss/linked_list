#include "node.h"


class LinkedList
{
public:
  LinkedList();
  void printList();
  void printListHelper(Node*);

  void addNode(string);
  void addNodeHelper(string, Node*);

  Node* find(string);
  Node* findNodeHelper(string, Node*);

  void deleteNode(string);
  void findAndDeleteNode(string, Node*);

  void insertAfter(string toInsert, string after);

  Node* findParent(string);
  Node* findParentHelper(string, Node*);

  Node head;
};
