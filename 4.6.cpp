#include<iostream>
int main(void){
	using namespace std;
	struct CandyBar{
		char brand[20];
		double weight;
		int crl;
	};
	
	CandyBar snack[3]={{"Mocha Munch",2.3,350},
	{"A",2.8,320},{"B",4.5,780}
	};
	char x=32;
	for(int i=0;i<3;i++)
	cout<<snack[i].brand<<x<<snack[i].weight<<x<<snack[i].crl<<endl;
	
	return 0;
}
