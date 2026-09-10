#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

using namespace std;

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr dat; 

  cout << "Back tests" << endl;
  cout << "Starting size - expected 0: " << dat.size() << endl;

  cout << "Starting empty - expected 1: " << dat.empty() << endl;
  
  //popping empty list
  dat.pop_back(); 

  //push_back on empty list
  dat.push_back("0"); 

  //push_back when tail has space
  dat.push_back("1"); 
  dat.push_back("2");
  dat.push_back("3");
  dat.push_back("4");
  dat.push_back("5");
  dat.push_back("6");
  dat.push_back("7");
  dat.push_back("8");
  dat.push_back("9");

  //first node is full so create new tail node
  dat.push_back("10");

  cout << "Expected: 0 1 2 3 4 5 6 7 8 9 10" << endl;
  cout << "Actual: "; 

  for (size_t i = 0; i < dat.size(); i++){
    cout << dat.get(i) << " ";
  }
  cout << endl; 

  cout << "Front - expected 0: " << dat.front() << endl;
  cout << "back - expected 10: " << dat.back() << endl; 
  cout << "Size - expected 11: " << dat.size() << endl; 

  //pop back 
  dat.pop_back(); 
  cout << "After pop_back - expected 9: " << dat.back() << endl;
  cout << "Size - expected 10: " << dat.size() << endl; 

  //tail contains multiple vals 
  dat.pop_back();
  cout << "After pop_back - expected 8: " << dat.back() << endl;
  cout << "Size - expected 9: " << dat.size() << endl;
  
  while (!dat.empty()){
    dat.pop_back();
  }

  cout << "Ending size - expected 0: " << dat.size() << endl; 
  cout << "Ending empty - expected 1: " << dat.empty() << endl; 

  dat.pop_back(); //pop back when empty again

  cout << endl;
  cout << "Front tests" << endl; 

  ULListStr datFront;
  
  datFront.push_front("0");
  datFront.push_front("1");
  datFront.push_front("2");
  datFront.push_front("3");
  datFront.push_front("4");
  datFront.push_front("5");
  datFront.push_front("6");
  datFront.push_front("7");
  datFront.push_front("8");
  datFront.push_front("9");
  datFront.push_front("10");

  cout << "Expected: 10 9 8 7 6 5 4 3 2 1 0" << endl;
  cout << "Actual:  "; 

  for (size_t i = 0; i < datFront.size(); i++){
    cout << datFront.get(i) << " "; 
  }
  cout << endl; 

  cout << "Front - expected 10: " << datFront.front() << endl; 
  cout << "Back - expected 0: " << datFront.back() << endl; 
  cout << "Size - expected 11: " << datFront.size() << endl; 

  datFront.pop_front(); 

  cout << "After pop_front - expected 9: " << datFront.front() << endl;
  cout << "Size - expected 10: " << datFront.size() << endl; 

  datFront.pop_front(); 

  cout << "After second pop_front - expected 8: " << datFront.front() << endl;
  cout << "Size - expected 9: " << datFront.size() << endl; 

  datFront.set(0, "changed");

  cout << "After set, get(0) expected changed: " << datFront.get(0) << endl; 

  while (!datFront.empty()) {
    datFront.pop_front(); 
  }

  cout << "Ending size - expected 0: " << datFront.size() << endl; 
  cout << "Ending empty - expected 1: " << datFront.empty() << endl; 

  datFront.pop_front(); 
  return 0; 
}
