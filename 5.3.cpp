#include<iostream>
int main(void){
	using namespace std;
	int ch,sum=0;
	cin>>ch;
	while(ch){
		sum+=ch;
		cout<<sum<<endl;
		cin>>ch;
	}
	
	return 0;
}
