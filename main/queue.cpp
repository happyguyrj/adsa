#include<iostream>
#include "../library/queue.hpp"

using namespace std;

int main()
  {
    queue<int> q;

    int i,j;
    i=1;

    while(1)
    {
        cout << "**********Queue*************" << endl;
        cout << "\nChoose the function to be performed \n";
        cout << "\t1. Enqueue\n";
        cout << "\t2. Dequeue\n";
        cout << "\t3. Size\n";
        cout << "\t4. First element\n";
        cout << "\t5. Display\n";
        cout << "\t6. Is queue Empty\n";
        cout << "\t7. Exit\n";
        cout<<"\nEnter your choice: ";
        cin>>i;

        switch(i)
        {
            case 1: cout<<"\nEnter The element to be pushed into stack: ";
                    cin>>j;
                    q.push(j);
                    break;

            case 2: q.pop();
                    cout<<"\nElement Popped";
                    break;

            case 3: cout<<"\nThe Size is ";
                    cout<<q.size()<<"\n";
                    break;

            case 4: cout<<"\nThe top element is: ";
                    cout<<q.front()<<"\n";
                    break;

            case 5: q.display();
                    break;

            case 6:if(q.empty()==1)
                    cout<<"\nEmpty\n";
                    else
                        cout<<"\nNot Empty\n";
                    break;

            case 7:return 0;

            default:cout<<"\nWrong Choice\n";
                    break;
        }
    }
    return 0;
}
