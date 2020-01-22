#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
	srand(time(NULL));
	cout<<1<<endl;
	int n=rand()%7;
	cout<<n<<endl;
	for(int i=1;i<=n;i++){
		int dir=rand()%6;
		int d=rand()%19;
		if(dir==0) printf("left %d",d);
		if(dir==1) printf("right %d",d);
		if(dir==2) printf("up %d",d);
		if(dir==3) printf("down %d",d);
		if(dir==4) printf("forward %d",d);
		if(dir==5) printf("back %d",d);
		printf("\n");
	}
}
