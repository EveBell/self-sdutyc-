#include<iostream>
#include<cstring>
int main(void){
	using namespace std;
	cout<<"Enter your first name: ";
	char fname[20];
	cin.get(fname,20).get();
	cout<<"Enter your last name: ";
	char lname[20];
	cin.get(lname,20).get();
	
	//cout<<lname<<", "<<fname<<endl;
	int x=strlen(lname);
	char name[40];
	strcpy(name,lname);
	name[x]=44;
	name[x+1]=32; 
	strcat(name,fname);
	cout<<name;
	//cout<<x;
    
	
	return 0;
}
