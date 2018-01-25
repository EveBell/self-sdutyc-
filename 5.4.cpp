#include<iostream>
int main(void){
	using namespace std;
	double x1=100;
	int y1=10;
	double sum1=100;
	double x2=100;
	double sum2=100;
	int i;
	for(i=1;sum1>=sum2;i++){
		sum1+=10;
		sum2*=1.05;
	}
	cout<<"i= "<<i<<endl;
	cout<<"sum1="<<sum1<<" sum2="<<sum2<<endl;
	
	return 0;
}
