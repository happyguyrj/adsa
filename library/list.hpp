// Purpose: ADSA lab
// Author: Raul Jain
// Bugs:

/*
 * queue.hpp
 *
 * functionality of a singly linked-list
 *
 * define your methods in coherence with the following
 * function signatures
 *
 *
 */

#ifndef LIST_HPP
#define LIST_HPP 1

#include "iostream"

using namespace std;

template<class T>
  class Node
  {
    T data;
    Node<T> *next;

  public:
    Node(){}                  //Default constructor
    T getdata();              //getting data
    void setdata(const T &r); //changing data
    void setnext(Node*next); //set next
    Node* getnext();
  };

template<class T>
  T Node<T>::getdata(){
    return data;
  }

template<class T>
  void Node<T>::setdata(const T &r){
    data = r;
  }

template<class T>
  void Node<T>::setnext(Node* next){
    this->next = next;
  }

template<class T>
  Node<T>* Node<T>::getnext(){
    return next;
  }

template<class T>
  class list
  {

    Node<T> * head;
    int len;

    public:
      /*
       * Primary contructor.
       * Should construct an empty list.
       * Size of the created list should be zero.
       */
      list(){
        head=NULL;
        len = 0;
      }
      /*
       * Seondary constructor.
       * Creates a new list which is a copy of the provided list.
       */
      list(const list<T> & x);
      /*
       * Destructor.
       * Frees all the memory acquired by the list.
       */
      ~list();
      /*
       * adds value at the end of the list.
       */
      void append(const T& value);
      /*
       * Returns the length of the list.
       */
      inline int length();
      /*
       * Returns a boolean indicating whether the list is empty.
       */
      inline bool empty();
      /*
       * Adds a value to the front of the list.
       */
      void cons(const T& value);
      /*
       * Removes the first occurence of the value from list.
       */
      void remove(const T & x);
      /*
       * Appends the given list x at the end of the current list.
       */
      void append(const list<T>& x);

      int top();
      Node<T>* gethead();
      void print();
      bool find(T value);
  };

template<class T>
  list<T>::list(const list<T> &x){
    Node <T> *ptr1, *ptr2, *ptr3;
    int i = 0;

    head = x.head;
    ptr1 = head;

    if (head == NULL) {
      len = 0;
    }
    else{
      while (ptr1 != NULL) {
        ptr3 = new Node<T>();
        len++;

        int d = ptr1 -> getdata();
        ptr3->setdata(d);
        ptr1 = ptr1->getnext();

        if(i=0){
          head = ptr2 = ptr3;
          i++;
        }
        else{
          ptr2->setnext(ptr3);
          ptr2=ptr2->getnext();
        }
      }
      ptr2->setnext(ptr1);
    }
  }

template<class T>
  list<T>::~list(){}

template<class T>
  void list<T>::append(const T& value){
    Node<T> *ptr1, *ptr2;

    ptr1 = new Node<T>();
    ptr1->setdata(value);
    ptr1->setnext(NULL);

    ptr2 = head;

    if(ptr2 == NULL){
      head = ptr1;
    }
    else{
      while (ptr2->getnext() != NULL) {
        ptr2 = ptr2->getnext();
      }
      ptr2->setnext(ptr1);
    }
    len++;
  }

template<class T>
  int list<T>::length(){
    return len;
  }

template<class T>
  bool list<T>::empty(){
    return (len == 0);
  }

template<class T>
  void list<T>::cons(const T& value){
    Node<T> *ptr;
    ptr = new Node<T>();

    ptr->setdata(value);
    ptr->setnext(head);
    head = ptr;
    len++;
  }

template<class T>
  void list<T>::remove(const T& x){
    Node<T> *ptr1, *ptr2;
    ptr1 = head;

    if (head->getdata() == x) {
      head = head->getnext();
      delete(ptr1);
      len--;
    }
    else{
      while (ptr1->getdata() != x) {
        ptr2 = ptr1;
        ptr1 = ptr1->getnext();
      }
      ptr2->setnext(ptr1->getnext());
      delete ptr1;
      len--;
    }
  }

template<class T>
  void list<T>::append(const list<T>& x){
    Node<T>* ptr;
    list<int> y(x);
    ptr = head;

    if(ptr == NULL){
      head = ptr = y.head;
      len = y.len;
    }
    else{
      while (ptr->getnext() != NULL) {
        ptr = ptr->getnext();
      }
      ptr->setnext(y.head);
      len = len + y.len;
    }
  }

template<class T>
int list<T>:: top(){
    return head->getdata();
  }

template<class T>
  Node<T>* list<T>::gethead(){
    return head;
  }

template<class T>
  void list<T>::print(){
    Node<T>* ptr;
    ptr = head;
    while (ptr->getnext() != NULL) {
      cout << ptr->getdata() << " -";
      ptr = ptr->getnext();
    }
    cout << ptr->getdata() << endl;
  }

template<class T>
  bool list<T>::find(T value){
    Node<T> *temp = head;
    while (temp != NULL) {
      if (value == temp->data) {
        return true;
      }
      temp = temp->next;
    }
    return false;
  }


#endif
