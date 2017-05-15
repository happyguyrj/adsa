// Purpose: ADSA lab
// Author: Raul Jain
// Bugs:

/*
 * stack.hpp
 *
 * define your methods in coherence with the following
 * function signatures
 *
 * use the abstraction of linked lists
 * to implement the functionality of stacks
 *
 */

#ifndef STACK_HPP_
#define STACK_HPP_

#include "list.hpp"

using namespace std;

template<typename T>
  class stack
  {
    list<T> s;

    public:
      /*
       * Constructs a new stack.
       */
      stack(){}
      /*
       * Pushes t to on the top of the stack.
       */
      void push(const T& t){
        s.cons(t);
      }
      /*
       * Returns the element at the top of the stack.
       * Also removes the top element from the stack.
       */
      T pop(){
        Node<T> * head = s.gethead();
        T h = head->getdata();
        s.remove(h);
        return h;
      }
      /*
       * Returns the element at the top of the stack.
       * Does not remove the top element.
       */
      T top(){
        Node<T> * head = s.gethead();
        return head->getdata();
      }
      /*
       * Returns the number of elements currently in the stack.
       */
      int size(){
        return s.length();
      }
      /*
       * Returns a boolean indicating whether the stack is empty or not.
       */
      inline bool empty(){
        return s.empty();
      }
      /*
       * Destructor
       * Fress the memory occupied by the stack elements.
       */
      ~stack(){}

      void display(){
        s.print();
      }
  };


#endif
