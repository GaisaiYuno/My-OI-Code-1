#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int l,n;
int a[105],b[105];
int main() {
	srand((unsigned)time(NULL));
	//freopen("data.txt","w",stdout);
	int t=rand()%10+1;
	while(t--) {
		int l=rand()%20+1,n=rand()%100+1;
		printf("%d %d\n",l,n);
		for(int i=1; i<=l; i++) a[i]=rand()%100+2;
		for(int i=1; i<=l; i++) b[i]=rand()%a[i]+1;
		for(int i=1; i<=l; i++) printf("%d ",a[i]);
		cout<<endl;
		for(int i=1; i<=l; i++) printf("%d ",b[i]);
		cout<<endl;
	}
}
