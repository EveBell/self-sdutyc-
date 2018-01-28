#include<iostream>
int main(void){
	using namespace std;
	cout<<"Please enter one of the following chioces:"<<endl;
	cout<<"c) carnivore"<<"        "<<"p) pianist"<<endl;
	cout<<"t) tree"<<"             "<<"g) game"<<endl;
	char ch;
	cout<<"Please enter a c, p, t, or g: ";
	aa:cin>>ch;
	
	switch(ch){
		case 'c': cout<<"A maple is a carnivore."; break;
		case 't': cout<<"A maple is a tree."; break;
		case 'p': cout<<"A maple is a pianist."; break;
		case 'g': cout<<"A maple is a game."; break;
		default :cout<<"Please enter a c, p, t, or g: ";goto aa;
	}
	
	return 0;
}
