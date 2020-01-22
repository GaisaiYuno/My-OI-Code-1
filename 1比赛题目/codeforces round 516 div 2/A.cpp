#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm> 
using namespace std;
int t[4]; 
int a,b,c;
int main(){
	scanf("%d %d %d",&a,&b,&c);
	t[1]=a;
	t[2]=b;
	t[3]=c;
	sort(t+1,t+4); 
	a=t[1];
	b=t[2];
	c=t[3];
	printf("%d\n",max(c-a-b+1,0));
} 
