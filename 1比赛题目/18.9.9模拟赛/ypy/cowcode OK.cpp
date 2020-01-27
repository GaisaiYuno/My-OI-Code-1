#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char a[35];
long long n,len,k;
int main(){
	scanf("%s ",a);
	cin>>n;
	n--;
	len=strlen(a);
	k=len;
	while(k<=n){
		k<<=1;
	} 
	k>>=1;
	while(n>=len){
		n-=k+1;
		if(n<0)	n+=k;
		k>>=1;
	}
	printf("%c",a[n]);
}
