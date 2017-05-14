#include "list.hpp"
#include<iostream>

using namespace std;

int main()
{
    list <int> x;
    list<int> k;
    int i=1;
    int j;
    while(1)
    {
        cout << "1. Append at the End of List\n";
        cout << "2. Append to the start of List\n";
        cout << "3. Print List\n";
        cout << "4. Get Length\n";
        cout << "5. Check if List is Empty\n";
        cout << "6. Get Top Element\n";
        cout << "7. Delete an element \n";
        cout << "8. Exit\n";
        cout << "\n";

        cout<<"Enter Your Choice\n";
        cin>>i;

        switch(i)
        {
            case 1:cout<<"Enter value to be entered: ";
                    cin>>j;
                    x.append(j);
                    break;

            case 2:cout<<"Enter value to be entered: ";
                    cin>>j;
                    x.cons(j);
                    break;

            case 3:x.print();
                    break;

            case 4:cout<<"\nThe Size is ";
                    cout<<x.length()<<"\n";
                    break;

            case 5:if(x.empty()==0)
                      cout<<"Not empty\n";
                   else
                      cout<<"Empty\n";
                   break;

            case 6:cout<<"\nThe top element is ";
                    cout<<x.top()<<"\n";
                   break;

            case 7: cout<<"Enter Value you want to delete: ";
                    cin>>j;
                    x.remove(j);
                    break;

            case 8: break;

            default: cout<<"\n\n Wrong choice\n";
                    break;
        }
    }
    return 0;
}
