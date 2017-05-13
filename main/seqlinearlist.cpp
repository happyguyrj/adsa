#include "../library/seqlinearlist.hpp"

using namespace std;

int main(){
  int max,len,i,num = 0,val,x,location;

	cout << "Enter maximum number of numbers: ";
	cin >>max;

	cout << "\nEnter input size: " <<endl;
	cin >> len;

	LinearList<int> A(max);

  cout <<"\nEnter the elements";
	for(i=0;i<len;i++)
	{
		cout <<"\n\tEnter the Number " << i <<": " << endl;
		cin >>  num;
		A.insert(i-1,num);
	}

  while (1) {
    cout << "\nEnter the choice: \n";
    cout << "\t1.Display \n";
    cout << "\t2.Insert \n";
    cout << "\t3.Delete \n";
    cout << "\t4.Maximum size \n";
    cout << "\t5.Current length \n";
    cout << "\t6. Find position of an element\n";
    cout << "\t7.Check whether the list is empty \n";
    cout << "\t8.Exit\n\n";
		cout << "\n";
    cout << "Enter your choice: ";

		cin >> val;

    switch(val)
		{
			case 1:
					A.display();
					break;

			case 2:
					cout << "Enter Element to be inserted: ";
					cin >> x;

					cout << "Enter location at which element is to be inserted: ";
					cin >> location;

					A.insert(location,x);
					break;

			case 3:
					cout << "Delete the element from location: ";
					cin >> location;

					A.deleteElement(location,x);
					break;

			case 4:
					cout <<" \n\nMaximum Size = "<< A.maxSize() << "\n" <<endl;
					break;

			case 5:
					cout << "\n\n Actual Size = "<< A.length() << "\n" <<endl;
					break;

      case 6:
          cout << "Enter value: ";
          cin >> x;

          if(location=A.search(x))
            cout<<" \n\n "<< x << " It is at location  " << location <<"\n"<<endl;
          else
            cout<<" \n\n "<< x << " It is not in the list"<<"\n"<<endl;

          break;

      case 7:
          if(A.isEmpty())
            cout<<"It is an Empty list"<<endl;
          else
            cout<<"\n\nList contains elements"<<"\n"<<endl;
            break;

      case 8:
          return 0;

      default:
          cout << "\n\nEnter right choice\n" <<endl;
          return 0;
          break;
  }
}
  return 0;
}
