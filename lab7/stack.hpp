#ifndef STACK_HPP_
#define STACK_HPP_
#include "list.hpp"

namespace cs202

{
  template<typename T>
    class stack
    {
      list <T> x;
      public:
        /*
         * Constructs a new stack.
         */
        stack(){}
        /*
         * Pushes t to on the top of the stack.
         */
        void push(const T& t){
          x.cons(t);
        }

        T pop(){
          Node<T> * head=x.gethead();
          T p=head->getdata();
          x.remove(p);
          return p;
        }

        T top(){
            Node <T>* head=x.gethead();
            return head->getdata();
        }

        void display(){
          x.print();
        }

        int size(){
          int p=x.length();
          return p;
        }

        inline bool empty(){
          return x.empty();
        }

        ~stack(){}
    };
}

#endif
