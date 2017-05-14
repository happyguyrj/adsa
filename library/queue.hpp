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

using namespace std;

template <class T>
  class queue
  {
    public:
      /*
       * Constructs a new queue.
       */
      queue();
      /*
       * Pushes t to at the back of the queue.
       */
      void push(const T& t);
      /*
       * Returns the element at the front of the queue.
       * Also removes the front element from the queue.
       */
      T pop();
      /*
       * Returns the element at the front of the queue.
       * Does not remove the front element.
       */
      T front();
      /*
       * Returns the number of elements currently in the queue.
       */
      inline int size();
      /*
       * Returns a boolean indicating whether the queue is empty or not.
       */
      inline bool empty();
      /*
       * Destructor
       * Fress the memory occupied by the queue elements.
       */
      ~queue();
  };

#endif
