#include<iostream>
int main(void){
	using namespace std;
	const int c1=12;
	const double c2=2.2;
	const double c3=0.0254;
	int yingchi;
	double yingcun;
	double wei;
	cin>>yingchi>>yingcun;
	cin>>wei;
	double temp1=(yingchi*c1+yingcun)*c3;
	double temp2=wei/c2;
	cout<<temp2/(temp1*temp1)<<endl;
	
	return 0;
}
