#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

using namespace std; 

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
//push front - check if head node exists and if array has free space shift everything one 
//one to the right, and then add new value at zero, set to head, connect head->next to old head
//if no space, create a new node and connect it to the old head as new head

//push back - check if tail node exists and if array has free space add new val at the end 
//if no space, create new node add val and connect to old tail 

//pop front - check if list is empty - if empty return 
//else find value of current head node, store it for deleting later, then move everything 
//one to the left 

//front 
const string& ULListStr::front() const {
  return head_->val[head_->first]; 
}

//back 
const string& ULListStr::back() const {
  return tail_->val[tail_->last - 1]; 
}

void ULListStr::push_front(const string& val){
  if (size_ == 0){
    Item* newNode = new Item(); 
    //create a new node using the back of last node
    newNode->first = ARRSIZE - 1; //where to store first value of new node
    newNode->last = ARRSIZE; 
    newNode->val[newNode->first] = val; 

    //both bc list is empty and new node 
    head_ = newNode; 
    tail_ = newNode; 
  }
  else if(head_->first > 0){
    head_->first--;
    head_->val[head_->first] = val; 
  }
  else {
    //create a new node and attach it
    Item* newNode = new Item();
    newNode->first = ARRSIZE - 1;
    newNode->last = ARRSIZE; 
    newNode->val[newNode->first] = val; 

    newNode->next = head_; //attaches current head to newNode
    head_->prev = newNode;
    head_ = newNode; 
  }
  size_++; //because size changes by one by adding an element
}

void ULListStr::push_back(const string& val){
  if (size_ == 0){
    Item* newNode = new Item(); 

    newNode->first = 0;
    newNode->last = 1; 
    newNode->val[0] = val; 

    head_ = newNode; 
    tail_ = newNode;
  }
  else if (tail_->last < ARRSIZE){ //arrsize is size of arr so if tail has space its index will be less than size
    //tail has room after last value
    tail_->val[tail_->last] = val; 
    tail_->last++; 
  }

  else {
    Item* newNode = new Item(); 
    newNode->first = 0; 
    newNode->last = 1;
    newNode->val[0] = val; 

    //connect old tail to new node 
    newNode->prev = tail_; 
    tail_->next = newNode; 
    tail_ = newNode;  
  }
  size_++; 
}

void ULListStr::pop_front(){
  if (size_ == 0){
    return; 
  } else if (head_->last - head_->first > 1){ //if more than one val
      head_->first++; //move head's first one to the right
  } else {
      Item* temp = head_; 
      head_ = head_->next; 

      if (head_ == NULL){
        tail_ = NULL; 
      } else {
        head_->prev = NULL; 
      }
      delete temp; 
    }
  size_--; 
}

void ULListStr::pop_back(){
  if (size_ == 0){
    return;
  } else if (tail_->last - tail_->first > 1){
    tail_->last--; //move index back one 
  } else {
    Item* temp = tail_; 

    tail_ = tail_->prev; 

    if (tail_ == NULL){
      head_ = NULL; 
    } else {
      tail_->next = NULL;
    }
    delete temp; 
  }
  size_--; 
}

string* ULListStr::getValAtLoc(size_t loc) const {
  if (loc >= size_){
    return NULL; 
  }

  Item* curr = head_; 

  while (curr != NULL){
    size_t nodeSize = curr->last - curr->first; 

    if (loc < nodeSize){
      return &(curr->val[curr->first + loc]); //return current value's array's element at loc
    }

    loc = loc - nodeSize;
    curr = curr->next; //to continue thru loop 
  }
  return NULL; 
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
