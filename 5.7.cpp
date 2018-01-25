#include<iostream>
struct car{
		char name[20];
		int year;
	}x[100];
int main(void){
	using namespace std;
	
	cout<<"How many cars do you wish to catalog? ";
	int num;
	cin>>num;
	
//	car *ps= new car [num]; 
	for(int i=1;i<=num;i++){
		cout<<"Car #"<<i<<":"<<endl;
		cout<<"Please enter the make: ";
		cin.get(x[i].name,20).get();
		//cin.get(ps->name,20);
		//cout<<endl;
		cout<<"Please enter the year made: ";
		cin>>x[i].year;
		//cin>>ps->year;
		cout<<endl;
	}
	
	cout<<"Here is your collection: "<<endl;
	for(int i=1;i<=num;i++){
		cout<<x[i].year<<" "<<x[i].name<<endl;
	}
	
	//delete [] ps;
}
