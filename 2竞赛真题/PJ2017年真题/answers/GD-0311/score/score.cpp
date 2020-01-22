#include<cstdio>

using namespace std;

int x,y,z;

int main(){
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%d%d%d",&x,&y,&z);
	printf("%d\n",x/5+y/10*3+z/2);
}
