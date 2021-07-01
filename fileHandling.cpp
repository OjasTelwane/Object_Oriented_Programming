// SE G9 23140 OOPL assignment no 9
// File Operations
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
#define SIZE 80

int main()
{
	int i;
	char line[SIZE];
	ofstream fout;
	fout.open("country");
	fout<<"United States of America\n";
	fout<<"United Kingdom\n";
	fout<<"South Korea\n";
	fout<<"India\n";
	fout.close();
	
	fout.open("capital");
	fout<<"Washington D.C.\n";
	fout<<"London\n";
	fout<<"Seoul\n";
	fout<<"New Delhi\n";
	fout.close();
	
	ifstream fin1,fin2;
	fin1.open("country");
	fin2.open("capital"); 
	cout<<"Country\t\t\t\tCapital\n\n";
	for(i=0;i<=10;i++)
	{
		if(fin1.eof()!=0)
		{
			cout<<"Exit from country\n";
			exit(1);
		}
		fin1.getline(line,SIZE);
		cout<<setw(25)<<std::left<<line<<"\t";
		if(fin2.eof()!=0)
		{
			cout<<"Exit from capital\n";
			exit(1);
		}
		fin2.getline(line,SIZE);
		cout<<line<<"\n";
	}
	return 0;
}
