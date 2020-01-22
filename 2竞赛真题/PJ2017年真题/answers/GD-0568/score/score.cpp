#include<cstdio>
using namespace std;
int read(){
	int x=0;char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x;
}
void print(int x){
	if(x>9) print(x/10);
	putchar(x%10+'0');
}
int main(){
	int a,b,c;
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	a=read(),b=read(),c=read();
	print(int(a*1.0/5+b*1.0/10*3+c*1.0/2));
	fclose(stdin);
	fclose(stdout);
	return 0;
}
