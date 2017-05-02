#ifndef LIST_HPP
#define LIST_HPP 1

#include<iostream>

using namespace std;
namespace cs202
{
  template<class T>
    class Node
    {
        T data;
        Node<T> * next;
    public:
        Node(){}            //Default Constructor
        T getdata();        //getting data
        void setdata(const T &r);   //changing data
        void setnext( Node*next);    //set next
        Node * getnext();
        bool find(T val);       //get next
    };

  template<class T>
  T Node<T>::getdata()
  {
      return data;
  }

  template<class T>
  void Node<T>::setdata(const T & r)
  {
      data=r;
  }

  template<class T>
  void Node<T> ::setnext(Node * next)
  {
      this->next=next;
  }

  template<class T>
    bool list<T>::find(T val)
    {
        Node<T> *tmp=first;
        while ( tmp!= NULL )

        {
            if(val==tmp->data) {return true;}
            tmp = tmp->link;
        }
        return false;

    }

  template<class T>
  Node<T>* Node<T>::getnext()
  {
      return next;
  }

  template<class T>
      class list
      {
        Node<T> * head;
        int len;

        public:
          list()
          {
              head=NULL;
              len=0;
          }

          Node<T>* gethead(){
                return head;
            }

         list( const list<T> &x);
        ~list(){}

          void append(const T& value);
          int top();
          void print();
          int length();

          bool empty()
          {
              return !len;
          }

          void cons(const T& value);
          // Removes the first occurrence of the value from list.

          void remove(const T & x);
          // Appends the given list x at the end of the current list.
           //function overloading

          void append(const list<T>& x);
      };

      template<class T>
      list<T>::list( const list<T> &x)
        {
            Node <T>*ptr,*ptr1,*ptr2;
            int i=0;
            head=x.head;
            len=0;
            ptr=head;
            if(head==NULL)
                {
                    len=0;
                }
            else
                while(ptr!=NULL)
                {
                    ptr2=new Node<T>();
                    len++;
                    int r=ptr->getdata();
                    ptr2->setdata(r);
                    ptr=ptr->getnext();
                    if(i==0)
                    {
                        head=ptr1=ptr2;
                        i++;
                    }
                    else
                    {
                        ptr1->setnext(ptr2);
                        ptr1=ptr1->getnext();
                    }
                }

            ptr1->setnext(ptr);
        }

      template<class T>
      void list<T>::append(const T& value)
      {
          Node<T> * ptr,*ptr1;
          ptr=new Node<T>();
          ptr->setdata(value);
          ptr->setnext(NULL);
          ptr1=head;
          if(ptr1==NULL)
              head=ptr;
          else
          {
              while(ptr1->getnext()!=NULL)
              {
                  ptr1=ptr1->getnext();
              }
              ptr1->setnext(ptr);
          }
          len++;
      }

      template<class T>
      int list<T>:: top()
      {
          return head->getdata();
      }

      template<class T>
      void list<T>:: print()
      {
          Node <T>* ptr;
          ptr=head;
          while(ptr->getnext()!=NULL)
          {
              std::cout<<ptr->getdata()<<" -> ";
              ptr=ptr->getnext();
          }
          std::cout<<ptr->getdata()<<"\n";
      }

    template<class T>
    int list<T>:: length()
    {
        return len;
    }

    template<class T>
    void list<T>:: cons(const T& value)
    {
        Node<T> * ptr;
        ptr=new Node<T>();
        ptr->setdata(value);
        ptr->setnext(head);
        head=ptr;
        len++;
    }

    template<class T>
    void list<T>::remove(const T & x)
    {
        Node<T> * ptr,*ptr1;
        ptr=head;
        if(head->getdata()==x)
        {
            head=head->getnext();
            delete(ptr);
            len--;
        }
        else
        {
            while(ptr->getdata()!=x)
            {
                ptr1=ptr;
                ptr=ptr->getnext();
            }
            ptr1->setnext(ptr->getnext());
            delete ptr;
            len--;
        }
    }

    template<class T>
    void list<T>::append(const list<T>& x)
    {
        Node <T>*ptr;
        list<int> y(x);
        ptr=head;
        if(ptr==NULL)
            {
                head=ptr=y.head;
                len=y.len;
            }
        else
        {
            while(ptr->getnext()!=NULL)
            ptr=ptr->getnext();
            ptr->setnext(y.head);
            len=len+y.len;
        }
    }
}

#endif
