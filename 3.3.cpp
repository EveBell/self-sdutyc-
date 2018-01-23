#include<iostream>
int main(void){
	using namespace std;
	const int c=60;
	double x,y,z;
	cout<<"Enter a latitude in degrees, minutes, and seconds:"<<endl;
	cout<<"First, enter the degrees: ";
	cin>>x;
	cout<<"Next, enter the minutes of arc: ";
	cin>>y;
	cout<<"Finally, enter the seconds of arc: ";
	cin>>z;
	cout<<x<<" degrees, "<<y<<" minutes, "<<z<<" seconds = ";
	cout<<x+y/c+z/(c*c)<<" degrees";
	
	return 0;
}
