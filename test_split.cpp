/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream> 

using namespace std; 

void deleteList(Node* head){
  if (head == nullptr){
    return; 
  }
  deleteList(head->next);
  delete head; 
}

int main(int argc, char* argv[])
{
  Node* node6 = new Node(6, nullptr);
  Node* node5 = new Node(5, node6);
  Node* node4 = new Node(4, node5);
  Node* node3 = new Node(3, node4);
  Node* node2 = new Node(2, node3);
  Node* node1 = new Node(1, node2);

  Node* odds1 = nullptr;
  Node* evens1 = nullptr; 

  split(node1, odds1, evens1);

  cout << "Odds1: ";
  for (Node* out = odds1; out != nullptr; out = out->next){
    cout << out->value << " "; 
  }
  cout << endl; 

  cout << "Evens1: ";
  for (Node* out = evens1; out != nullptr; out = out->next){
    cout << out->value << " ";
  }
  cout << endl;  

  Node* test2 = nullptr; 
  Node* odds2 = nullptr; 
  Node* evens2 = nullptr; 
  
  split(test2, odds2, evens2);  

  cout << "Odds2: ";
  for (Node* out2 = odds2; out2 != nullptr; out2 = out2->next){
    cout << out2->value << " "; 
  }
  cout << endl; 

  cout << "Evens2: ";
  for (Node* out2 = evens2; out2 != nullptr; out2 = out2->next){
    cout << out2->value << " ";
  }
  cout << endl;
  deleteList(odds1); 
  deleteList(evens1); 
  
  return 0; 
}
