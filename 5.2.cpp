#include<iostream>
#include<array>
const int Arsize = 100;
int main(void){
	using namespace std;
	array<long double,Arsize> ai;
	int i;
	a[0]=a[1]=1;
	
	for(i=2;i<=Arsize;i++)
	   a[i]=a[i-1]*i;
	   
	cout<<Arsize<<"! = "<<a[i]<<endl;
	
	return 0;
	
	
}
