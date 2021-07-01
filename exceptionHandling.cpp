// SE G9 23140 OOPL assignment no 7
// exception Handling
#include<iostream>
using namespace std;

class Exception
{
	private:
		double num1,num2;
		int x;
	public:
		void get_data()
		{
			cout<<"\nEnter the first number: ";
			cin>>num1;
			cout<<"\nEnter the second number: ";
			cin>>num2;
		}
		void display()
		{
			cout<<"\nFirst number is: "<<num1<<"\nSecond number is: "<<num2<<endl;
		}
		double calDivision()
		{
			try
			{
				if(num1!=0 && num2!=0)
				{
					cout<<"\nThe result of division is: "<<num1/num2<<endl;
				}
				else
				{
					throw(x);
				}
			}
			catch(int x)
			{
				cout<<"\n Exception caught : DIVIDE BY ZERO\n";
			}
		}
};		

int main()
{	
	int choice;
	Exception e;
	while(choice!=4)
	{
		cout<<"\n MENU";
		cout<<"\n To input press 1";
		cout<<"\n To display press 2";
		cout<<"\n To divide press 3";
		cout<<"\n To exit press 4";
		cout<<"\n Enter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1: e.get_data();
					break;
			case 2: e.display();
					break;
			case 3: e.calDivision();
					break;
			case 4: break;
			default: printf("\n Enter number from 1 to 4: ");
					break;
		}
	}
	return 0;
}
