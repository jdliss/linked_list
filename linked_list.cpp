#include <sstream>
#include <vector>
#include "linked_list.h"

LinkedList::LinkedList() {
  this->head->data = "";
  this->head->childPtr = NULL;
}

void LinkedList::printList() {
  if (this->head->data != "") {
    printList(this->head);
  } else {
    cout << "Empty List" << endl;
  }
}

void LinkedList::printList(Node* current) {
  cout << current->data << endl;
  if (current->childPtr) printList(current->childPtr);
}

void LinkedList::addNode(string data) {
  if (this->head->data == "") {
    this->head->data = data;
  } else {
    addNode(data, this->head);
  }
}

void LinkedList::addNode(string data, Node *current) {
  if (current->childPtr) {
    addNode(data, current->childPtr);
  } else {
    current->childPtr = new Node;
    current->childPtr->data = data;
    current->childPtr->childPtr = nullptr;
  }
}

 Node* LinkedList::find(string data) {
   if (this->head->data == data){
     return this->head;
   } else {
     return find(data, this->head->childPtr);
   }
 }
 
 Node* LinkedList::find(string data, Node* current) {
   if (current->data == data) {
     return current;
   } else if (current->childPtr) {
     return find(data, current->childPtr);
   } else {
     return NULL;
   }
 }
 
 void LinkedList::deleteNode(string data) {
   if (this->head->data == data) {
     this->head->data = this->head->childPtr->data;
     this->head->childPtr = this->head->childPtr->childPtr;
   } else {
     findAndDeleteNode(data, this->head);
   }
 }
 
 void LinkedList::findAndDeleteNode(string data, Node* current) {
   if (current->childPtr->data == data) {
     Node* child = current->childPtr;
     current->childPtr = child->childPtr;
   } else {
     findAndDeleteNode(data, current->childPtr);
   }
 }
 
 Node* LinkedList::findParent(string data) {
   if (this->head->data == data)
     return NULL;
   else
     return findParentHelper(data, this->head);
 }
 
 Node* LinkedList::findParentHelper(string data, Node* current) {
   if (current->childPtr && current->childPtr->data == data)
     return current;
   else
     return findParentHelper(data, current->childPtr);
 }
 
 void LinkedList::insertAfter(string toInsert, string afterData) {
   Node* toInsertNode = new Node;
   Node* priorNode = find(afterData);

   if (priorNode) {
     toInsertNode->data = toInsert;
     toInsertNode->childPtr = priorNode->childPtr;
     priorNode->childPtr = toInsertNode;
   } else {
     cout << "Could not find node to insert afterData: '"
          << afterData << "' did not match any node data." << endl;
   }
 }
 
 string LinkedList::toString() {
   string list = "";
   string result;
 
   if (this->head->data != "" && !(this->head->childPtr)) {
     return this->head->data;
   } else if (this->head->data != "") {
     result = toStringHelper(list, this->head);
     return result.substr(0, result.size()-1);
   } else {
     string empty = "Empty list";
     return empty;
   }
 }
 
 string LinkedList::toStringHelper(string list, Node* current) {
   list += current->data + ", ";
 
   if (current->childPtr)
     return toStringHelper(list, current->childPtr);
   else
     return list.substr(0, list.size()-1);
 }
 
 string LinkedList::pop() {
   if (this->head->data != "") {
     if (this->head->childPtr) {
       return popHelper(this->head);
     } else
       return this->head->data;
   } else {
     return "Empty list";
   }
 }
 
 string LinkedList::popHelper(Node* current) {
   if (current->childPtr->childPtr)
     return popHelper(current->childPtr);
   else {
     string toReturn = current->childPtr->data;
     current->childPtr = NULL;
     return toReturn;
   }
 }
 
 int LinkedList::count() {
   int count = 0;
   if (this->head->data == "")
     return count;
   else if (this->head->childPtr)
     return 1 + countHelper(this->head->childPtr);
   else
     return count + 1;
 }
 
 int LinkedList::countHelper(Node* current) {
   if (current->childPtr)
     return 1 + countHelper(current->childPtr);
   else
     return 1;
 }
