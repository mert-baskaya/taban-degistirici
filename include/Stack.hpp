#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
using namespace std;

template <typename Object>
struct Dugum{
  Object item;
  Dugum<Object> *ileri;

  Dugum(const Object& item, Dugum<Object> *ilr=NULL){
    this->item = item;
    ileri = ilr;
  }
};

template <typename Object>
class Stack{
  private:
    Dugum<Object> *topOfStack;
  public:
    Stack(){
      topOfStack = NULL;
    }

    bool isEmpty()const{
      return topOfStack == NULL;
    }

    void push(const Object& item){
      topOfStack = new Dugum<Object>(item, topOfStack);
    }

    void pop(){ //bu fonksiyonun çıkarılan elemanı döndürdüğü de olabiliyor
      // if(isEmpty()) throw HATA;
      Dugum<Object> *tmp = topOfStack;
      topOfStack = topOfStack->ileri;
      delete tmp;
    }

    const Object& top()const{
      // if(isEmpty()) throw HATA;
      return topOfStack->item;
    }

    void makeEmpty(){
      while(!isEmpty())
        pop();
    }

    ~Stack(){
      makeEmpty();
    }
};

#endif
