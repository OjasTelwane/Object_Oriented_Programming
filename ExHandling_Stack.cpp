// SE G9 23140 OOPL assignment no 7 Extra
// exception Handling Stack
#include<iostream>
using namespace std;
#define MAX 3

class Stack
{
	private:
		int top;
		int arr[MAX];
	public:
	Stack()
	{
		top=-1;
	}
		int push_data(int data)
		{
			top++;
			try
			{
				if(top<MAX)
				{
					arr[top]=data;					
				}
				else
				{
					throw (top);				
				}
			}
			catch(int top)
			{
				cout<<"\n ERROR:STACK POINTER HAS REACHED TOP OF STACK, PUSH OPERATION CANNOT BE DONE";
				return 1;
			}
			return 0;	
		}
		int pop_data()
		{
			--top;
			try
			{
				if(top<0)
				{
					throw (top);
					
				}
				
				cout<<arr[top];
			}
			catch(int top)
			{
				cout<<"\n ERROR:STACK POINTER HAS REACHED BASE, POP OPERATION CANNOT BE DONE";
				return 1;
			}
			return 0;
		}
};

int main()
{	
	int choice,data,flag;
	char check;
	Stack st;
	while(choice!=3)
	{
		cout<<"\n MENU";
		cout<<"\n To Push data into Stack press 1";
		cout<<"\n To Pop data from Stack press 2";
		cout<<"\n To exit press 3";
		cout<<"\n Enter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1: check='y';
					while(check=='y')
					{
						flag=0;
						cout<<"\n Enter the data you want to push: ";
						cin>>data;
						flag=st.push_data(data);
						if(flag==0)
						{
							cout<<"\n Push operation successful Successful ";
							cout<<"\n do you want to push data again (y/n): ";
							cin>>check;
						}
						else
						{
							break;
						}
					}	        
					break;
			case 2: check='y';
        			while(check=='y')
					{
						flag=0;
						cout<<"\nPopping first element from stack: ";
						flag=st.pop_data();
						if(flag==0)
						{
							cout<<"\n Pop operation successful Successful ";
							cout<<"\n do you want to pop data again (y/n): ";
							cin>>check;
						}
						else
						{
							break;
						}	
					}	        
            		break;
			case 3: break;
			default:printf("\n Enter number from 1 to 3: ");
					break;
		}
	}
	return 0;
}
