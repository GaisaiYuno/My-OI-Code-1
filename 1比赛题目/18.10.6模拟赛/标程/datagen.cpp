#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<ctime>
#include<cstdlib>
using namespace std;

//legacy
int main(){
	#define MAXW 100000000
	#define MAXN 100000
	srand(time(0));
	freopen("legacy10.in","w",stdout);
	int n=MAXN;
	cout<<MAXN<<" "<<MAXN<<" "<<rand()%MAXN+1<<endl;
	for(int i=0;i<MAXN;i++){
		int type=rand()%3;
		if(type==1){
			cout<<1<<" "<<rand()%n+1<<" "<<rand()%n+1<<" "<<900000000+rand()%MAXW<<endl;
		}else if(type==2){
			int l=rand()%n+1;
			int r=rand()%(n-l+1)+l;
			cout<<2<<" "<<rand()%n+1<<" "<<l<<" "<<r<<" "<<900000000+rand()%MAXW<<endl;
		}else{
			int l=rand()%n+1;
			int r=rand()%(n-l+1)+l;
			cout<<3<<" "<<rand()%n+1<<" "<<l<<" "<<r<<" "<<900000000+rand()%MAXW<<endl;
		}
	}cout<<endl;
}

//stairs
//int main(){
//	#define MAXAB 1000000
//	#define MAXN 100000
//	srand(time(0));
//	freopen("stairs10.in","w",stdout);
//	cout<<1<<" "<<1<<" "<<MAXN<<endl;
//	for(int i=0;i<MAXN;i++){
//		cout<<1<<" "<<1000000<<" "<<1000000<<endl;
//	}cout<<endl;
//}


