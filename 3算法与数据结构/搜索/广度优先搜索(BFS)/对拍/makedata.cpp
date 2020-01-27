#include<iostream>
#include<stdlib.h>
#include<ctime>
using namespace std;
int main(){
	srand((unsigned)time(NULL));
	freopen("testdata.txt","w",stdout);
	int t=rand()%10; 
	for(int k=1;k<=t;k++){
		int size=rand()%20+1;
		for(int i=1;i<=size;i++){
		    cout<<rand()%2;
	    }
	    cout<<endl;
	}
	
}
