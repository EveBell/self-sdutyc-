#include<iostream>
#include<string>
int main(void){
	using namespace std;
	string lname;
	string fname;
	string cont;
	cont=", ";
	cout<<"Enter your first name: ";
	cin>>fname;
	cout<<"Enter your last name: ";
	cin>>lname;
	cout<<"Here's the information in a singel string: "<<lname+cont+fname<<endl;
	
	return 0;
}
