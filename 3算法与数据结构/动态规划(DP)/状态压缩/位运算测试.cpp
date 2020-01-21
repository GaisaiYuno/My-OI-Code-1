#include<iostream>
using namespace std;
int main(){
	int a,b; 
	while(cin>>a>>b){
		printf("a&b=%d\n",a&b);
		printf("a|b=%d\n",a|b);
		printf("a^b=%d\n",a^b);
		printf("a<<b=%d\n",a<<b);
	}
}
