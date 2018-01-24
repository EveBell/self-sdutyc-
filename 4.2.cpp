#include<iostream>
#include<string>
#include<cstring>
int main(void){
	using namespace std;
	const int Arsize =20;
	string name;
	string dessert;
	
	cout << "Enter your name:\n";
	cin>>name;
	cout<<"Enter your favourate dessert:\n";
	cin>>dessert;
	cout<<"I have some delicious "<<dessert;
	cout<<" for you, "<<name<<".\n";
	return 0;
	
}
