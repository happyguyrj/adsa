// Purpose: ADSA lab
// Author: Raul Jain
// Bugs:

/*
 * queue.hpp
 *
 * define your methods in coherence with the following
 * function signatures
 *
 * use the abstraction of linked lists
 * to implement the functionality of queues
 *
 */

#ifndef QUEUE_HPP_
#define QUEUE_HPP_

#include "list.hpp"

using namespace std;

template <class T>
  class queue
  {
    list<T> l;
    public:
      /*
       * Constructs a new queue.
       */
      queue(){}
      /*
       * Pushes t to at the back of the queue.
       */
      void push(const T& t){
        l.append(t);
      }
      /*
       * Returns the element at the front of the queue.
       * Also removes the front element from the queue.
       */
      T pop(){
        Node<T> * head = l.gethead();
        T h = head->getdata();
        l.remove(h);
        return h;
      }
      /*
       * Returns the element at the front of the queue.
       * Does not remove the front element.
       */
      T front(){
        Node<T>* head = l.gethead();
        return head->getdata();
      }
      /*
       * Returns the number of elements currently in the queue.
       */
      inline int size(){
        return l.length();
      }
      /*
       * Returns a boolean indicating whether the queue is empty or not.
       */
      inline bool empty(){
        return l.empty();
      }
      /*
       * Destructor
       * Fress the memory occupied by the queue elements.
       */
      ~queue(){}

      void display() {
        l.print();
      }
  };

#endif
