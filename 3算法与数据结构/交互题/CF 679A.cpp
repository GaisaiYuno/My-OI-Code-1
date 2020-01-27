//我的第一道交互题~ 
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char s[5];
const int ask[]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,4,9,25,49 };
int main(){
	int cnt=0;
	for(int i=1;i<=19;i++){
		printf("%d\n",ask[i]);
		fflush(stdout);
		scanf("%s",s);
		if(s[0]=='y') cnt++;
		if(cnt>=2) break;
	}
	if(cnt>=2) printf("composite");
	else printf("prime\n");
	fflush(stdout); 
} 
