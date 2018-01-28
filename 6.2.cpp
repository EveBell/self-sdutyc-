#include<iostream>
const int N=10;
int main(void){
	using namespace std;
	double arr[N];
	int cnt=0;
	double sum=0;
	for(int i=0;i<N;i++){
		if(!(cin>>arr[i]))
			{break;}
		else   {
			cnt++;
			sum+=arr[i];
		}
//			cin.clear();
//			while(cin.get()!='\n')
//			  continue;
//			cout<<"Please enter a number: ";
		
	}
	double pre;
	cout<<"pre=:"<<sum/cnt<<endl;
	//cout<<"num = :"<<cnt<<endl;
	int cnt1=0;
	for(int i=0;i<cnt;i++){
		if(arr[i]>=pre)
		 {cnt1++;}
	//	cout<<arr[i]<<" ";
	}
	cout<<cnt1<<endl;
	return 0;
	
	
	
}
