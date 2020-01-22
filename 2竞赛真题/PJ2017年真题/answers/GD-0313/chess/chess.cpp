#include<cstdio>
#include<cstring>
using namespace std;
int a[1001][1001],x,y,c,jinbi=0;
bool mofa=true;
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int m,n;
	bool flag=true;
	memset(a,2,sizeof(a));
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;++i){
		scanf("%d%d%d",&x,&y,&c);
		a[x][y]=c;
	}
	int i=1,j=1;
	while(1){
		mofa=true;
		if(a[i+1][j]!=a[i][j]&&a[i+1][j]==2)
			if(a[i][j]==0&&a[i+1+1][j]==0&&mofa==true)
				a[i+1][j]=0,mofa=false,i++,jinbi+=2;
			else if(a[i][j]==0&&a[i+1][j+1]==0&&mofa==true)
					a[i+1][j]=0,mofa=false,i++,jinbi+=2;
				else if(a[i][j]==1&&a[i+1+1][j]==1&&mofa==true)
						a[i+1][j]=1,mofa=false,i++,jinbi+=2;
					else if(a[i][j]==1&&a[i+1][j+1]==1&&mofa==true)
							a[i+1][j]=1,mofa=false,i++,jinbi+=2;
		if(i==m&&j==m){
			printf("%d",jinbi);flag=false;break;
		}
		if(a[i][j+1]!=a[i][j]&&a[i][j+1]==2&&mofa==true)
			if(a[i][j]==0&&a[i+1][j+1]==0)
				a[i][j+1]=0,mofa=false,j++,jinbi+=2;
			else if(a[i][j]==0&&a[i][j+1+1]==0&&mofa==true)
					a[i][j+1]=0,mofa=false,j++,jinbi+=2;
				else if(a[i][j]==1&&a[i+1][j+1]==1&&mofa==true)
						a[i][j+1]=1,mofa=false,j++,jinbi+=2;
					else if(a[i][j]==1&&a[i][j+1+1]==1&&mofa==true)
						a[i][j+1]=1,mofa=false,j++,jinbi+=2;
		if(i==m&&j==m){
			printf("%d",jinbi);flag=false;break;
		}
		if(a[i+1][j]!=a[i][j]&&a[i+1][j]!=2){
			jinbi++;i++;
		}
		if(i==m&&j==m){
			printf("%d",jinbi);flag=false;break;
		}
		if(a[i][j+1]!=a[i][j]&&a[i][j+1]!=2){
			jinbi++;j++;
		}
		if(i==m&&j==m){
			printf("%d",jinbi);flag=false;break;
		}
		if(a[i+1][j]==a[i][j])
			i++;
		if(i==m&&j==m){
			printf("%d",jinbi);flag=false;break;
		}
		if(a[i][j+1]==a[i][j])
			j++;
		if(i==m&&j==m){
			printf("%d",jinbi);flag=false;break;
		}
	}
	if(flag==true)
		printf("-1");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
