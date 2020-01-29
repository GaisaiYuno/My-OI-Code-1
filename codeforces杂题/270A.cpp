#include<iostream>
#include<cstdio>
using namespace std;
int t,a;
int main(){
	//180(x-2)/x=a
	//x=360/(180-a)
	scanf("%d",&t);
	while(t--){
		scanf("%d",&a);
		if(360%(180-a)==0) printf("YES\n");
		else printf("NO\n");
	}
	
}
