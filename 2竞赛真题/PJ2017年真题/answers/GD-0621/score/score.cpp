#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int A,B,C;
int main(){
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%d%d%d",&A,&B,&C);
	A=A/10*2;B=B/10*3;C=C/10*5;
	printf("%d",A+B+C);
	return 0;
}
