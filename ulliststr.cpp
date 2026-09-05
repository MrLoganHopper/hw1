#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

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


 /**
   * Adds a new value to the back of the list
   *   - MUST RUN in O(1)
   */
  void ULListStr::push_back(const std::string& val){


     if(tail_ == nullptr){
      ULListStr::Item* newItem = new ULListStr::Item();

      head_ = newItem;
      tail_ = newItem;


      newItem->val[4] = val;
      newItem->first = 4;
      newItem->last = 5;
    } else if(tail_->last == ARRSIZE){
      ULListStr::Item* a = new ULListStr::Item(); // fill with actual dynamic allocaiton
      a->val[0] = val;
      a->first = 0;
      a->last = 1;
      a->prev = tail_;
      tail_->next = a;
      tail_ = a;
      

    }else{
      tail_->val[tail_->last] = val;
      tail_->last++;
    }
 
      size_++;


  }

  /**
   * Removes a value from the back of the list
   *   - MUST RUN in O(1)
   */
  void ULListStr::pop_back(){

    ULListStr::Item* tmp = tail_;

    if(tail_ == nullptr){

      return;


    }else if(tail_->last == tail_->first + 1){

      if(tail_->prev != nullptr){
        tail_ = tail_->prev;
        tail_->next = nullptr;
      } else{
        tail_ = nullptr;
        head_ = nullptr;
      }

      delete tmp;


    }
    
    else{
      tail_->last--;
      
    }

    size_--;



  }
  
  /**
   * Adds a new value to the front of the list.
   * If there is room before the 'first' value in
   * the head node add it there, otherwise, 
   * allocate a new head node.
   *   - MUST RUN in O(1)
   */
  void ULListStr::push_front(const std::string& val){
    if(head_ == nullptr){
      ULListStr::Item* newItem = new ULListStr::Item();

      head_ = newItem;
      tail_ = newItem;


      newItem->val[4] = val;
      newItem->first = 4;
      newItem->last = 5;


    } else if(head_->first == 0){
      ULListStr::Item* a = new ULListStr::Item();
      a->next = head_;
      a->prev = nullptr;
      head_->prev = a;
      head_ = a;
      head_->val[ARRSIZE - 1] = val;
      head_->first = ARRSIZE - 1;
      head_->last = ARRSIZE;


    } else{

      head_->val[head_->first - 1] = val;
      head_->first = head_->first -1;

    }


    size_++;


  }

  /**
   * Removes a value from the front of the list
   *   - MUST RUN in O(1)
   */
  void ULListStr::pop_front(){
    if(head_ == nullptr){
      return;
    }


    head_->first++;
    size_--;


    if(head_->first == head_->last){
      ULListStr::Item* temp = head_;
      if(temp->next != nullptr){
        head_ = temp->next;
        head_->prev = nullptr;
      } else{
        head_ = nullptr;
        tail_ = nullptr;
      }
      delete temp;

    }



  }

std::string* ULListStr::getValAtLoc(size_t loc) const {
  if(loc >= size_){
    return nullptr;
  }

  ULListStr::Item* curr = head_;

  while(curr != nullptr){
    size_t count = curr->last - curr->first;
    if(loc < count){

      return &curr->val[curr->first + loc];
    }

    curr = curr->next;
    loc = loc - count;
  }
  return NULL;


 
}

std::string const & ULListStr::front() const {
    return head_->val[head_->first];
}

std::string const & ULListStr::back() const {
    return tail_->val[tail_->last - 1];
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
