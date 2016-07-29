#include "node.h"

using namespace std;

class LinkedList {

public:
  Node* head;

  LinkedList(string);

  void printList();
  void printList(Node*);

  void addNode(string);
  void addNode(string, Node*);

  // Node* find(string);
  // Node* find(string, Node*);

  // void deleteNode(string);
  // void findAndDeleteNode(string, Node*);

  // void insertAfter(string toInsert, string after);

  // Node* findParent(string);
  // Node* findParentHelper(string, Node*);

  // string toString();
  // string toStringHelper(string, Node*);

  // string pop();
  // string popHelper(Node*);

  // int count();
  // int countHelper(Node*);
};
