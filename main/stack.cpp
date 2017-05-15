#include<iostream>
#include "../library/stack.hpp"

using namespace std;

int main()
  {
    stack<int> s;

    int i,j;
    i=1;

    while(1)
    {
        cout << "**********Stack*************" << endl;
        cout << "\nChoose the function to be performed \n";
        cout << "\t1. Push\n";
        cout << "\t2. Pop\n";
        cout << "\t3. Size\n";
        cout << "\t4. Get Top\n";
        cout << "\t5. Display\n";
        cout << "\t6. Is Stack Empty\n";
        cout << "\t7. Exit\n";
        cout<<"\nEnter your choice: ";
        cin>>i;

        switch(i)
        {
            case 1: cout<<"\nEnter The element to be pushed into stack: ";
                    cin>>j;
                    s.push(j);
                    break;

            case 2: s.pop();
                    cout<<"\nElement Popped";
                    break;

            case 3: cout<<"\nThe Size is ";
                    cout<<s.size()<<"\n";
                    break;

            case 4: cout<<"\nThe top element is: ";
                    cout<<s.top()<<"\n";
                    break;

            case 5: s.display();
                    break;

            case 6:if(s.empty()==1)
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
