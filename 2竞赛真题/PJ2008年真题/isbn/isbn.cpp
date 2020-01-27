//isbn 
#include<iostream>
#include<cstdio>
#define maxn 10
using namespace std;
char a[maxn];
int main(){
	int sum=0;
	char x,y;
	freopen("isbn.in","r",stdin);
	freopen("isbn.out","w",stdout);
	scanf("%c-%c%c%c-%c%c%c%c%c-%c",&a[1],&a[2],&a[3],&a[4],&a[5],&a[6],&a[7],&a[8],&a[9],&x);
	for(int i=1;i<=9;i++){
		sum+=(a[i]-48)*i; 
	} 
	if(sum%11==10) y='X';
	else y=sum%11+'0';
	if(y==x) cout<<"Right";
	else{
		printf("%c-%c%c%c-%c%c%c%c%c-%c",a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9],y);
	}
	return 0;
}
