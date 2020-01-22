#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int x,y,z;
	scanf("%d%d%d",&x,&y,&z);
	int ans=x*2/10+y*3/10+z*5/10;
	printf("%d",ans);
	return 0;
}
