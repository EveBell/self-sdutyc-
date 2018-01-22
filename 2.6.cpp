#include<iostream>
long f(double n);
int main(void){
	using namespace std;
	double n;
	cout<<"Enter the number of light years:";
	cin >> n;
	long m = f(n);
	cout <<n<<" light years = "<<m<<" astronmical units."<<endl;
	
	return 0;
}
long f(double n){
	long m;
	m=n*63240;
	return m;
}
