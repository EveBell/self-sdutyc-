#include<iostream>
int main(void){
	using namespace std;
	cout<<"Enter the world's population: ";
	long long x,y;
	cin>>x;
	cout<<"Enter the population of the US: ";
	cin>>y;
	cout <<"The population of the US is "<<y*1.0/x*100<<"% of the world population. ";
	cout<<endl;
	
	return 0;
}
