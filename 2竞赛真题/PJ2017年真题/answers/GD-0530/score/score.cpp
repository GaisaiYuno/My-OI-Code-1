#include<cstdio>

int main(){
	freopen("score.in","r",stdin);
	
	freopen("score.out","w",stdout);
	
	int a,b,c,s;
	
	scanf("%d%d%d",&a,&b,&c);
	
	s=a/5+b/10*3+c/2;
	
	printf("%d",s);
	
	fclose(stdin);
	
	fclose(stdout);
	
	return 0;
}
