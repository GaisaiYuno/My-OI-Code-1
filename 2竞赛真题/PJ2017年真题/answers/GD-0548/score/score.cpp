#include<iostream>
#include<cctype>
#include<cstdio>
using namespace std;
int a,b,c;
int read(){
	int num=0;
	char ch=getchar();
	int w=1;
	while(!isdigit(ch)){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		num=num*10+ch-48;
		ch=getchar();
	}
	return num*w;
}
int main(){
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	a=read();
	b=read();
	c=read();
	cout<<(double)a*0.2+(double)b*0.3+(double)c*0.5;
}
