// SE G9 23140 OOPL assignment no 2
// Book_Inventory

#include<iostream>
#include<string.h>
using namespace std;
class BookShop
{
	private:
		int *price,*stock;
		char *publisher,*author,*title,*ISBN_no;
		static int valid,invalid;
	public:
		BookShop()
		{
			price=new int;
			stock=new int;
			publisher=new char[20];
			author=new char[20];
			title=new char[20];
			ISBN_no=new char[20];
		}	
		void set();
		void display();
		void preDisplay();
		int update(char ch[]);
		int search(char ch[],int choiceS);
		int buy(char ch[]);
		static void validity()
		{
			cout<<"\n\nThe no of valid transactions are:"<<valid;
			cout<<"\nThe no of invalid transactions are:"<<invalid;
		}
		~BookShop()
		{
			delete price,stock,publisher,author,title,ISBN_no;
		}
};

void BookShop::set()
{ 
	cin.ignore();
	cout<<"\nEnter the title of the book:";
	cin.getline(title,20);
	cout<<endl<<"Enter the name of the author:";
	cin.getline(author,20);
	cout<<"\nEnter the publisher of the book:";
	cin.getline(publisher,20);	
	cout<<"\nEnter the ISBN number of the book:";
	cin.getline(ISBN_no,13);
	cout<<"\nEnter the price of the book:";
	cin>>*price;
	cout<<"\nEnter the available stock of the book:";
	cin>>*stock;
	cout<<endl;
	preDisplay();
	display();
}

void BookShop::preDisplay()
{
	cout<<"ISBN number"<<"\tTitle"<<"\t\t\tAuthor"<<"\t\tPublisher"<<"\t\tPrice"<<"\tStock\n";
}

void BookShop::display()
{
	cout<<"\n"<<ISBN_no<<"\t"<<title<<"\t\t"<<author<<"\t"<<publisher<<"\t\t"<<(*price)<<"\t"<<(*stock)<<"\t\n\n";
}

int BookShop::update(char ch[])
{
	if(strcmp(ch,title)==0)
	{
		int check=0,choiceU;		
		while(choiceU!=7)
		{
		cout<<"\nMENU:\n1.title\n2.author\n3.publisher\n4.ISBN number\n5.price\n6.stock\n7.exit\nEnter what you want to Update: ";
		  	cin>>choiceU; 
		  	switch(choiceU)
		  	{
		  		case 1:	cin.ignore();
			  			cout<<"\nEnter the updated title:";
			  			cin.getline(title,20);
			  			break;
			  	case 2:	cin.ignore();
			  			cout<<"\nEnter the updated name of author:";
			  			cin.getline(author,20);
			  			break;
			  	case 3:	cin.ignore();
			  			cout<<"\nEnter the updated publisher:";
			  			cin.getline(publisher,20);
			  			break;		
			  	case 4:	cin.ignore();
			  			cout<<"\nEnter the updated ISBN number:";
			  			cin.getline(ISBN_no,13);
			  			break;
				case 5:	cout<<"\nEnter the price of the book:";
						cin>>*(price);
						break;
				case 6: cout<<"\nEnter the updated stock:";
						cin>>*(stock);
						break;	
				case 7:	check++;
						break;
				default:cout<<"\nEnter number from 1 to 7";
						break;		
			 }
			 preDisplay();
			 display();			
		}
		
			
		return 1;
	}
	else 
	{
		return 0;
	}
}

int BookShop::search(char ch[],int choiceS)
{
	if(choiceS==1)
	{
		if(strcmp(ch,ISBN_no)==0)
		{
			preDisplay();
			display();
			return 1;
		}
	}	
	if(choiceS==2)
	{
		if(strcmp(ch,author)==0)
		{
			preDisplay();
			display();
			return 1;
		}
	}
	if(choiceS==3)
	{
		if(strcmp(ch,title)==0)
		{
			preDisplay();
			display();
			return 1;
		}
	}
	else 
	{
		return 0;
	}
}

int BookShop::buy(char ch[])
{
	int amount;
	if(strcmp(ch,title)==0)
	{
		cout<<"\nEnter the number of books you want to buy: ";
		cin>>amount;
		if(amount<=(*stock))
		{
			cout<<"\nYour order has been successful ! \n";
			cout<<"The price is: "<<amount*(*price);
			valid++;
			(*stock)-=amount;
			return 1;
		}
		else
		{	
			invalid++;
			cout<<"\ntransaction not possible";
			return 1;
		}
	}
	else 	
	{
		return 0;
	}
}

int BookShop::valid;
int BookShop::invalid;

int main()
{
	int choiceM,choiceS,i=0,n=0;
	char ch[20];
	BookShop *book[50];  
	while(choiceM!=6)
	{
	cout<<"\nMENU:\n1.Add\n2.Update\n3.Search a book\n4.Purchase a book\n5.number of transactions\n6.exit\nEnter your choice: ";
		cin>>choiceM;
		switch(choiceM)
		{
			case 1:	book[i]=new BookShop;
					book[i]->set();
					i++;
					break;	
			case 2:	cin.ignore();
					cout<<endl<<"\nEnter the books title to be updated: ";
					cin.getline(ch,19);
					n=0;
					for(int j=0;j<i;j++)
					{
						n=book[j]->update(ch);
						if(n==1)
						{
							break;
						}
					}	
					if(n==0)
					{
						cout<<"\nThe name of title you entered was wrong";
					}
					break;	
			case 3:	cout<<"\n 1.Search by Book's ISBN number: \n 2.Search by Author name: \n 3.Search by name of Book: \n4.Exit";
					cout<<"\n Enter you choice: ";
					cin>>choiceS;
					while(choiceS!=4)
					{
						cout<<"\n Enter you choice: ";
						cin>>choiceS;
						switch(choiceS)
						{
							case 1:cout<<"\n Enter the ISBN no. of book: ";
									 cin.ignore();
									cin.getline(ch,13);
									n=0;
									for(int j=0;j<i;j++)
									{
										n=book[j]->search(ch,choiceS);
										if(n==1)
										{
											break;
										}
									}
									if(n==0)
									{
										cout<<"\nThe ISBN number you entered wasn't found\n";
									}					
									 break;
							case 2:cout<<"\n Enter the Author name: ";
									 cin.ignore();
									cin.getline(ch,20);
									n=0;
									for(int j=0;j<i;j++)
									{
										n=book[j]->search(ch,choiceS);
										if(n==1)
										{
											break;
										}
									}
									if(n==0)
									{
										cout<<"\nThe name of Author you entered wasn't found\n";
									}					
									 break;
							case 3:cout<<"\nEnter the book's title: ";
									cin.ignore();
									cin.getline(ch,20);
									n=0;
									for(int j=0;j<i;j++)
									{
										n=book[j]->search(ch,choiceS);
										if(n==1)
										{
											break;
										}
									}
									if(n==0)
									{
										cout<<"\nThe name of title you entered wasn't found\n";
									}
							case 4: break;
							default: cout<<"Enter the number from 1 to 4";
									break;
						}		
					}
					break;
			case 4:	cin.ignore();
					cout<<endl<<"\nEnter the books title to be searched: ";
					cin.getline(ch,20);
					n=0;
					for(int j=0;j<i;j++)
					{
						n=book[j]->buy(ch);
						if(n==1)
						{
							break;
						}
					}
					if(n==0)
					{
						cout<<"\nThe name of title you entered was wrong\n";
					}
					break;
			case 5:	BookShop::validity();
					break;
			case 6:	break;
			default: cout<<"\n Enter the value from 1 to 6";
					break;			
		}
	}
	return 0;
}
