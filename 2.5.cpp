#include<iostream>
double f(int n);
int main(void){
	using namespace std;
	int cel;
	cout<<"Please enter a Celsiud value:";
	cin>>cel;
	double m=f(cel);
	cout<<cel<<" degrees Celsius is "<<m<<" degrees Fahrenheit.";
	
	return 0;
}
double f(int n){
	double m=1.8*n+32.0;
	return m;
}
