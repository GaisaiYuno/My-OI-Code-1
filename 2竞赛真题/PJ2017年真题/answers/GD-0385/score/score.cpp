#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cctype>
#include<string>
#include<map>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	printf("%d\n",(a*2+b*3+c*5)/10);
	return 0;
}
