// SE G9 23140 OOPL assignment no 8
//genericProgramming_template
#include<iostream>
using namespace std;

template<class T>
class MatrixOp
{
	private:
		int i,j,k;
		T sum=0,a[3][3]; 
	public:
		void get_data();
		void display();
		MatrixOp<T> operator + (MatrixOp<T> c2)
		{
			MatrixOp temp;
			for(i=0;i<3;i++)
			{
				for(j=0;j<3;j++)
				{
					temp.a[i][j]=a[i][j]+c2.a[i][j];		
				}
			}
			return temp;	
		}
		MatrixOp<T> operator - (MatrixOp<T> c2)
		{
			MatrixOp temp;
			for(i=0;i<3;i++)
			{
				for(j=0;j<3;j++)
				{
					temp.a[i][j]=a[i][j]-c2.a[i][j];		
				}
			}
			return temp;	
		}
		MatrixOp<T> operator * (MatrixOp c2)
		{
			MatrixOp temp;
			for(i=0;i<3;i++)
			{
				for(j=0;j<3;j++)
				{
					temp.a[i][j]=0;
					for(k=0;k<3;k++)
					{
					  temp.sum = temp.sum + a[i][k]*c2.a[k][j];
					}
					temp.a[i][j] = temp.sum;
					temp.sum = 0;		
				}
			}
			return temp;	
		}
};		

template<class T> void MatrixOp<T>::get_data()
{
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			cin>>a[i][j];
		}	
	}
}

template<class T> void MatrixOp<T>::display()
{
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			cout<<a[i][j]<<"\t";
		}
		cout<<endl;		
	}
}

int main()
{	
	int choice,check=0;
	MatrixOp <int> M1,M2,M3;
	MatrixOp <float> N1,N2,N3;
	while(choice!=6)
	{
		cout<<"\n MENU";
		cout<<"\n To input press 1";
		cout<<"\n To display press 2";
		cout<<"\n To add matrices press 3";
		cout<<"\n To subtract matrices press 4";
		cout<<"\n To multiply matrices press 5";
		cout<<"\n To exit press 6";
		cout<<"\n Enter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1: cout<<"\nEnter the datatype you want ( 1 for int, 2 for float): ";
					cin>>check;
					if(check==1)
					{
						cout<<"\nEnter the first matrix: ";
						M1.get_data();
						cout<<"\nEnter the second matrix: ";
						M2.get_data();
					}
					else if(check==2) 
					{
						cout<<"\nEnter the first matrix: ";
						N1.get_data();
						cout<<"\nEnter the second matrix: ";
						N2.get_data();
					}
					break;
			case 2: if(check==1)
					{
						cout<<"\nThe first matrix is : "<<endl;
						M1.display();
						cout<<"\nThe second matrix is : "<<endl;
						M2.display();
					}
					else if(check==2) 
					{
						cout<<"\nThe first matrix is : "<<endl;
						N1.display();
						cout<<"\nThe second matrix is : "<<endl;
						N2.display();
					}
					break;
			case 3: if(check==1)
					{
						M3=M1+M2;
						M3.display();
					}
					else if(check==2) 
					{
						N3=N1+N2;
						N3.display();
					}
					break;
			case 4: if(check==1)
					{
						M3=M1-M2;
						M3.display();
					}
					else if(check==2) 
					{
						N3=N1-N2;
						N3.display();
					}
					break;
			case 5: if(check==1)
					{
						M3=M1*M2;
						M3.display();
					}
					else if(check==2) 
					{
						N3=N1*N2;
						N3.display();
					}
					break;				
			case 6: break;
			default: printf("\n Enter number from 1 to 6: ");
					break;
		}
	}
	return 0;
}
