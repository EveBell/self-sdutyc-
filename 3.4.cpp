#include<iostream>
int main(void){
	using namespace std;
	const int day_h =24;
	const int hour_m =60;
	const int min_s =60;
	cout<<"Enter the number of seconds: ";
	long long x;
	cin>>x;
	cout<<x<<" seconds = "<<x/(min_s*hour_m*day_h)<<" days, "<<(x%(min_s*hour_m*day_h))/(min_s*hour_m)<<" hours, ";
	cout<<((x%(min_s*hour_m*day_h))%(min_s*hour_m))/min_s<<" minutes, ";
	cout<<((x%(min_s*hour_m*day_h))%(min_s*hour_m))%min_s<<" seconds"<<endl;
	
	return 0;
}
