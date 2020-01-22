#include<cstdio>
using namespace std;
int A,B,C;
int main(){
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%d %d %d",&A,&B,&C);
	printf("%d",A*0.2+B*0.3+C*0.5);	
	fclose(stdin);
	fclose(stdout);
}
