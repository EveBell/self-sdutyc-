#include<iostream>
int main(void){
	using namespace std;
	int i,j;
	cin>>i>>j;
	
	int sum=0;
	for(int k=i;k<=j;k++){
		sum+=k;
	}
	
	cout<<sum;
	
	return 0;
} 
