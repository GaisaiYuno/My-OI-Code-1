//Ве№И ISBN
#include<iostream>
#define maxn 100
using namespace std;
string in;
char a[maxn];
int main(){
	char num,code;
	int i,sum=0;
    scanf("%c-%c%c%c-%c%c%c%c%c-%c",&a[1],&a[2],&a[3],&a[4],&a[5],&a[6],&a[7],&a[8],&a[9],&num);//
	for(i=1;i<=9;i++){
		sum+=(a[i]-48)*i;
	}
	if(sum%11==10) code='X';
	else code=sum%11+'0';
	if(code==num) cout<<"Right";
	else{
		printf("%c-%c%c%c-%c%c%c%c%c-%c",a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9],code);
	}
	return 0;
} 
