#include<iostream>
int main(void){
	using namespace std;
	cout<<"What is your first namr?";
	char name1[20];
	cin.get(name1,20).get();
	cout<<"What is your last name? ";
	char name2[20];
	cin.get(name2,20).get();
	cout<<"What letter grade do you deserve? ";
	char grd;
	cin>>grd;
	grd++;
	int x;
	cout<<"What is your age? ";
	cin>>x;
	
	cout<<"Name: "<<name2<<" , "<<name1<<endl;
	cout<<"Grade: "<<grd<<endl;
	cout<<"Age: "<<x<<endl;
	return 0;
} 
