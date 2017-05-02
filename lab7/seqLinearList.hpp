#ifndef SEQLINEARLIST_HPP
#define SEQLINEARLIST_HPP
#include <iostream>
#include <string.h>
using namespace std;

namespace cs202{
template<class Item>
class LinearList{
	private:
		int MaxSize;
		Item *element;    // 1D dynamic array
        int len;
	public:
		/* Default constructor.
		 * Should create an empty list that not contain any elements*/
		LinearList();

		/* This constructor should create a list containing MaxSize elements. You can intialize the elements with any values.*/
		LinearList(const int& MaxListSize);

		/* Destructor.
		 * Must free all the memory contained by the list */
		~LinearList();

		/* Indexing operator.
     		 * It should behave the same way array indexing does. i.e,
     		 * LinearList L;
     		 * L[0] should refer to the first element;
     		 * L[1] to the second element and so on.
     		 * */
		Item& operator[](const int& i); //return i'th element of list

		/* Returns true if the list is empty, false otherwise.
     		 * */
		bool isEmpty();

		/* Returns the actual length (number of elements) in the list.
     		 * */
		int  length();

		/* Returns the maximum size of the list.
     		 * */
		int  maxSize();

		/* Returns the k-th element of the list.
		 * */
		Item  returnListElement(const int k);

		/* Set x to the k-th element and
		 * return true if k-th element is present otherwise return false.
		 * */
		bool find(const int k, Item& x);

		/* Search for x and
		 * return the position if found, else return 0.
		 * */
		int  search(Item& x);

		/* Set x to the k-th element and delete that k-th element.
		 * */
		void  deleteElement(const int  k, Item& x);

		/* Insert x after k-th element.
		 * */
		void  insert(const int  k, Item& x);


		void display(){
			cout << "Element are: ";
			for(int i=0; i< len; i++)
			cout << element[i] << " -";
			cout << endl;
		}
};

template<class Item>
    LinearList<Item>::LinearList(){
	element = new Item[50];
	MaxSize = 50;
	len = 0;
}

template<class Item>
    LinearList<Item>::LinearList(const int& MaxListSize){
    MaxSize = MaxListSize;
	element = new Item[MaxListSize];
	for(int i=0; i<MaxListSize; i++)
		element[i] = 0;
		len = 0;
}

template<class Item>
    LinearList<Item>::~LinearList(){
	delete element;
}

template<class Item>
    Item& LinearList<Item>::operator[](const int& i){
	if( i > MaxSize ) {
               cout << "Index out of bounds" <<endl;
               // return first element.
               return element[0];
         }
         return element[i];
}

template<class Item>
    bool LinearList<Item>::isEmpty(){
	return (len == 0);
}

template<class Item>
    int LinearList<Item>::length(){
	return len;
}

template<class Item>
    int LinearList<Item>::maxSize(){
	return MaxSize;
}

template<class Item>
Item LinearList<Item>::returnListElement(const int k){
	return element[k];
}

template<class Item>
    bool LinearList<Item>::find(const int k, Item& x){
	if(k < MaxSize){
		x==element[k-1];
		return true;
		}
	else {
		cout << "Index out of bound" <<endl;
		return false;
	}

}

template<class Item>
    int LinearList<Item>::search(Item& x){
	for(int i=0;i<MaxSize;i++){
		if(element[i] == x)
		return i;
	}

}

template<class Item>
    void LinearList<Item>::deleteElement(const int  k, Item& x){
	x = element[k];
	for(int i=k+1;i<len;i++)
		element[i-1] = element[i];
	len--;
}

template<class Item>
    void LinearList<Item>::insert(const int  k, Item& x){
	for(int i=k+1; i<MaxSize; i++)
		element[i+1] = element[i];
	element[k+1] = x;
	len++;
}
}

#endif
