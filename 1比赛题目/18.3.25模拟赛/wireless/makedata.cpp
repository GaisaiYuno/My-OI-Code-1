#include<iostream>
#include<cstdlib>
#include<ctime>
#define size 128
using namespace std;
int main(){
	freopen("wireless.in","w",stdout);
	/*srand(time(NULL));
	int d=rand()%20+1;
	int n=rand()%20+1;
	printf("%d\n%d\n",d,n);
	while(n--){
		int x=rand()%129;
		int y=rand()%129;
		int k=rand()*1000+1;
		printf("%d %d %d\n",x,y,k);
	} */
	printf("%d\n %d\n",129,129*129);
	for(int i=0;i<=size;i++){
		for(int j=0;j<=size;j++){
			printf("%d %d %d\n",i,j,1000000);
		} 
	}
} 
