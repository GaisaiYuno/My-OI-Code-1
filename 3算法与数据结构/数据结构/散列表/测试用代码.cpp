#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
	freopen("data.txt","w",stdout);
	srand(time(NULL));
	for(int i=1;i<=20000;i++){
		cout<<"A"<<' '<<rand()%10000<<endl;
	}
	for(int i=1;i<=20000;i++){
		cout<<"B"<<' '<<rand()%10000<<endl;
	}
}
