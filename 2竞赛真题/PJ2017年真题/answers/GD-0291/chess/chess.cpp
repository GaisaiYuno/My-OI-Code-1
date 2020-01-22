#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<cstdio>
using namespace std;
int m,n,i,j,k,a[1005],b[1005],map[105][105],xz[4],yz[4],x,z,value[105][105],a0,a1,xmin;
int myabs(int x){
	if (x>=0) return x;
		else return -x;
}
main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&m,&n);
	for (i=1; i<=m; ++i)
		for (j=1; j<=m; ++j)
			value[i][j]=2000000000,map[i][j]=0;
	for (i=1; i<=n; ++i){
		scanf("%d%d%d",&a[i],&b[i],&z);
		if (a[i]==1&&b[i]==1) x=i;
		map[a[i]][b[i]]=z+1;
	}
	xz[0]=0,xz[1]=1,xz[2]=0,xz[3]=-1;
	yz[0]=1,yz[1]=0,yz[2]=-1,yz[3]=0;
	value[1][1]=0;
	for (i=1; i<=n; ++i){
		a0=a[x],a1=b[x];
		for (j=0; j<4; ++j)
			if (a0+xz[j]>0&&a0+xz[j]<m+1&&a1+yz[j]>0&&a1+yz[j]<m+1)
				if (map[a0+xz[j]][a1+yz[j]]!=0){
					if (value[a0][a1]+myabs(map[a0][a1]-map[a0+xz[j]][a1+yz[j]])<value[a0+xz[j]][a1+yz[j]])
						value[a0+xz[j]][a1+yz[j]]=value[a0][a1]+myabs(map[a0][a1]-map[a0+xz[j]][a1+yz[j]]);
				}
				else{
					for (k=0; k<4; ++k)
						if (a0+xz[j]+xz[k]>0&&a0+xz[j]+xz[k]<m+1&&a1+yz[j]+yz[k]>0&&a1+yz[j]+yz[k]<m+1){
							if (value[a0+xz[j]+xz[k]][a1+yz[j]+yz[k]]>value[a0][a1]+myabs(map[a0][a1]-map[a0+xz[j]+xz[k]][a1+yz[j]+yz[k]])+2)
								value[a0+xz[j]+xz[k]][a1+yz[j]+yz[k]]=value[a0][a1]+myabs(map[a0][a1]-map[a0+xz[j]+xz[k]][a1+yz[j]+yz[k]])+2;
						}
				}
		xmin=1000000000,x=0;
		value[a0][a1]=-1;
		for (j=1; j<=n; ++j)
			if (value[a[j]][b[j]]<xmin&&value[a[j]][b[j]]!=-1){
				xmin=value[a[j]][b[j]];
				x=j;
			}
		if (x==0){
			printf("-1\n");
			break;
		}
		if (map[m][m]!=0&&a[x]==m&&b[x]==m){
			printf("%d\n",value[m][m]);
			break;
		}
		if (map[m][m]==0){
			if (a[x]==m&&b[x]==m-1){
				printf("%d\n",value[m][m-1]+2);
				break;
			}
			if (a[x]==m-1&&b[x]==m){
				printf("%d\n",value[m-1][m]+2);
				break;	
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
}
