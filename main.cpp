#include "linked_list.h"

int main() {
  /*
    Create new linked list
    add nodes
    delete nodes
    find nodes
    find node parents
    insert node after another node
    print linked list in order
  */

  LinkedList list = LinkedList("first node");
  list.addNode("second node");
  list.addNode("third node");
  list.addNode("fourth node");
  list.addNode("fifth node");
  list.addNode("sixth node");
  list.addNode("seventh node");
  list.addNode("eighth node");
  list.printList();

  //  cout << endl << "looking for fourth node:" << endl;
  //  cout << "found: " << list.find("fourth node")->data << endl << endl;
  //  cout << endl << "looking for invalid node:" << endl;
  //  if (list.find("slkdjf") == NULL)
  //    cout << "found null" << endl << endl;

  //  cout << "deleting third node..." << endl;
  //  list.deleteNode("third node");
  //  list.printList();
  //
  //  cout << endl << "finding parent of fifth node" << endl;
  //  cout << "found: " << list.findParent("fifth node")->data << endl;
  //
  //  cout << endl << "Inserting 'new node' after 'first node'" << endl << endl;
  //  list.insertAfter("new node", "first node");
  //  list.printList();
  //
  //  cout << endl << "Trying to insert 'new node' after invalid node 'asdf'" << endl;
  //  list.insertAfter("new node", "asdf");
  //
  //  cout << endl << "Insert after last node (AKA append)" << endl;
  //  list.insertAfter("last node", "eighth node");
  //  list.printList();
  //
  //  cout << endl << "Using toString method on list:" << endl;
  //  cout << list.toString() << endl;
  //
  //  cout << endl << "Popping last node" << endl;
  //  cout << list.pop() << endl;
  //
  //  cout << endl << "Popping last node again" << endl;
  //  cout << list.pop() << endl;
  //
  //  cout << endl << "Popping last node again... again" << endl;
  //  cout << list.pop() << endl;
  //
  //  cout << endl << "Calculating list length..." << endl;
  //  cout << list.count() << endl;
  //
  return 0;
}
