#include<iostream>
int main(void){
	using namespace std;
	struct William{
		char name[30];
		double size;
		double weight;
	}x;
	
	char y=32;
	cin>>x.name>>x.size>>x.weight;
	cout<<x.name<<y<<x.size<<y<<x.weight;
	
	return 0;
}
