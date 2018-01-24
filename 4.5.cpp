#include<iostream>
int main(void){
	using namespace std;
	struct CandyBar{
		char brand[20];
		double weight;
		int crl;
	};
	
	CandyBar snack={"Mocha Munch",2.3,350};
	char x=32;
	cout<<snack.brand<<x<<snack.weight<<x<<snack.crl;
	
	return 0;
}
