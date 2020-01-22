#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c;
	int score=0;
	freopen("score.in","r",stdin);
	scanf("%d%d%d",&a,&b,&c);
	score+=(a/10)*2;
	score+=(b/10)*3;
	score+=(c/10)*5;
	freopen("score.out","w",stdout);
	printf("%d",&score);
}
