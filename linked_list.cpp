#include "linked_list.h"

LinkedList::LinkedList()
{
  this->head.data = "";
  this->head.childPtr = nullptr;
}

void LinkedList::printList()
{
  if (this->head.data != "")
  {
    cout << this->head.data << endl;
    if (this->head.childPtr)
      printListHelper(this->head.childPtr);
  }
  else
    cout << "Empty List" << endl;
}

void LinkedList::printListHelper(Node* current)
{
  cout << current->data << endl;
  if (current->childPtr)
    printListHelper(current->childPtr);
}


void LinkedList::addNode(string data)
{
  if (this->head.data == "")
    this->head.data = data;

  else
  {
    addNodeHelper(data, &this->head);
  }
}

void LinkedList::addNodeHelper(string data, Node *current)
{
  if (current->childPtr)
    addNodeHelper(data, current->childPtr);
  else
  {
    current->childPtr = new Node;
    current->childPtr->data = data;
    current->childPtr->childPtr = nullptr;
  }
}

Node* LinkedList::find(string data)
{
  if (this->head.data == data)
    return &(this->head);

  else
    return findNodeHelper(data, this->head.childPtr);
}

Node* LinkedList::findNodeHelper(string data, Node* current)
{
  if (current->data == data)
    return current;
  else if (current->childPtr)
    return findNodeHelper(data, current->childPtr);
  else
    return nullptr;
}

void LinkedList::deleteNode(string data)
{
  if (this->head.data == data)
  {
    this->head.data = this->head.childPtr->data;
    this->head.childPtr = this->head.childPtr->childPtr;
  }
  else
  {
    findAndDeleteNode(data, &this->head);
  }
}

void LinkedList::findAndDeleteNode(string data, Node* current)
{
  if (current->childPtr->data == data)
  {
    Node* child = current->childPtr;
    current->childPtr = child->childPtr;
  }
  else
  {
    findAndDeleteNode(data, current->childPtr);
  }
}

Node* LinkedList::findParent(string data)
{
  if (this->head.data == data)
    return nullptr;
  else
    return findParentHelper(data, &this->head);
}

Node* LinkedList::findParentHelper(string data, Node* current)
{
  if (current->childPtr && current->childPtr->data == data)
    return current;
  else
    return findParentHelper(data, current->childPtr);
}

void LinkedList::insertAfter(string toInsert, string afterData)
{
  Node* toInsertNode = new Node;

  Node* priorNode = find(afterData);
  if (priorNode)
  {
    toInsertNode->data = toInsert;
    toInsertNode->childPtr = priorNode->childPtr;
    priorNode->childPtr = toInsertNode;
  }
  else
    cout << "Could not find node to insert afterData: '" <<
            afterData << "' did not match any node data." << endl;
}
