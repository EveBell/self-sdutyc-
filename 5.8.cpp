#include<iostream>
#include<cstring>
int main(void){
	using namespace std;
	cout<<"Enter words (to stop, type the word done):"<<endl;
	char x[20];
	int cnt =0;
	cin.get(x,20).get();
	while((strcmp(x,"done"))!=0){
		cin.get(x,20).get();
		cnt++;
		x=NULL;
	}
	cout<<cnt;
	
	return 0;
}
