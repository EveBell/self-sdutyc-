#include<iostream>
#include<cctype>
int main(void){
	using namespace std;
	char ch;
	cin.get(ch);
	while(ch!='@'&&isalpha(ch))
	{
		if(islower(ch))
		{ch=toupper(ch);
		}
		else
		ch=tolower(ch);
		cout<<ch;
		cin.get(ch);
	}
	
	return 0;
} 
