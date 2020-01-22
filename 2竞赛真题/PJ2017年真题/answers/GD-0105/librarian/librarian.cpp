#include<cstdio>
#include<cmath>
int a[15][100005];
int n,q;
int min(int a,int b){
	return a<b?a:b;
}
void read(){
	int x=0,t=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){
		t++;
		x=x*10+c-'0';
		c=getchar();
	}
	a[t][0]++;
	a[t][a[t][0]]=x;
}
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)read();
	/*for(int i=1;i<=10;i++){
		printf("%d:",i);
		for(int j=1;j<=a[i][0];j++){
			printf("%d ",a[i][j]);
		}
		if(!a[i][0])printf("-1");
		putchar('\n');
	}*/
	for(int i=1;i<=q;i++){
		int length,num;
		scanf("%d%d",&length,&num);
		int ans=0x7fffffff;
		int need=pow(10,length);
		for(int j=length;j<=10;j++){
			for(int k=1;k<=a[j][0];k++){
				int x=a[j][k]%need;
				if(x==num)ans=min(ans,a[j][k]);
			}
			if(ans!=0x7fffffff)break;
		}
		if(ans==0x7fffffff)printf("-1\n");
		else printf("%d\n",ans);
	}
	return 0;
} 
