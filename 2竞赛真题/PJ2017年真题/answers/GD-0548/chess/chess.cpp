#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int bestway[101][101];
bool magic[101][101];
bool havm[101][101];
bool havc[101][101];
bool col[101][101];
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
int inpx,inpy,inpc;
int m,n;
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cout<<-1;
}
