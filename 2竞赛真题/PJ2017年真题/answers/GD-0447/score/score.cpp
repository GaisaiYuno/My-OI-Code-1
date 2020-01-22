#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("score.in","rb",stdin);
	freopen("score.out","wb",stdout);
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	printf("%d\n",a/5+b/10*3+c/2);
}
