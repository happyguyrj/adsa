#include "../library/list.hpp"

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
        cout << "**********List*************" << endl;
        cout << "\nEnter the choice: \n";
        cout << "\t1. Append at the End of List\n";
        cout << "\t2. Append to the start of List\n";
        cout << "\t3. Print List\n";
        cout << "\t4. Get Length\n";
        cout << "\t5. Check if List is Empty\n";
        cout << "\t6. Get Top Element\n";
        cout << "\t7. Delete an element \n";
        cout << "\t8. Exit\n";
        cout << "\n";

        cout<<"Enter Your Choice: ";
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

            case 8: return 0;

            default: cout<<"\n\n Wrong choice\n";
                    break;
        }
    }
    return 0;
}
