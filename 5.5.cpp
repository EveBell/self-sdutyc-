#include<iostream>
int main(void){
	using namespace std;
	char x[12][10]={"Jenuary","Febraray","March",
	"April","May","June","July","August",
	"September","October","November","December"};
	
	int y[12];
	int sum=0;
	for(int i=0;i<12;i++)
	  {cout<<x[i]<<": ";
	   cin>>y[i];
	   sum+=y[i];
	  }

    cout<<sum;
	return 0;
}
