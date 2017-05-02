#ifndef QUEUE_HPP_
#define QUEUE_HPP_
#include "list.hpp"

namespace cs202
{
  template <class T>
    class queue
    {
      list <T> x;

      public:
        /*
         * Constructs a new queue.
         */
        queue(){}
        /*
         * Pushes t to at the back of the queue.
         */
        void push(const T& t){
          x.append(t);
        };

        T pop(){
          Node<T>* head = x.gethead();
          T p = head->getdata();
          x.remove(p);
          return p;
        }

        T front(){
          Node <T>* head=x.gethead();
          return head->getdata();
        }

        inline int size(){
          return x.length();
        }

        inline bool empty(){
          return x.empty();
        }

        void display(){
            x.print();
        }

        ~queue(){}
    };
}
#endif
