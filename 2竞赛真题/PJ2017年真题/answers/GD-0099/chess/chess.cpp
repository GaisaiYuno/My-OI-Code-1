#include<cstdio>
#include<windows.h>

using namespace std;
int fx[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int main(){
	freopen ("chess.in","r",stdin);
	freopen ("chess.out","w",stdout);
	int m,n,S[104][104],sum=0,a,i=2,j=2,b,c,p,q;
	bool l=false,g=false;
	scanf ("%d%d",&m,&n);
	for (p=0; p<104; p++){
		for (q=0; q<104; q++){
			S[p][q]=-1;
		}
	}
	for (int i=0; i<n; i++){
		scanf ("%d%d%d",&a,&b,&c);
		S[a+1][b+1]=c;
	}
	while (i!=m+1 || j!=m+1) {
		l=false;
		for (p=0; p<4; p++){
			if (S[i+fx[p][0]][j+fx[p][1]]==S[i][j]){
		  		S[i][j]=-2;
				l=true;
		  		i=i+fx[p][0];
				j=j+fx[p][1];
				break;
		  	}
		}
		if (l) continue;
		for (p=0; p<4; p++){
			if(S[i+fx[p][0]][j+fx[p][1]]>-1){
		  		S[i][j]=-2;
				l=true;
				sum++;
		  		i=i+fx[p][0];
				j=j+fx[p][1];
				break;
		  	}
		}
		if (l) continue;
		for (p=0; p<4; p++){
			for (q=0; q<4; q++){
				if (S[i+fx[p][0]+fx[q][0]][j+fx[p][1]+fx[q][1]]==S[i][j] && i+fx[p][0]+fx[q][0]!=i && j+fx[p][1]+fx[q][1]!=j){
					sum+=2;
					l=true;
					g=true;
					i=i+fx[p][0]+fx[q][0];
					j=j+fx[p][1]+fx[q][1];
					break;
				}
			}
			if (g) break;
		}
		if (l) continue;
		for (p=0; p<4; p++){
			for (q=0; q<4; q++){
				if (q==2) continue;
				if (S[i+fx[p][0]+fx[q][0]][j+fx[p][1]+fx[q][1]]>-1 && i+fx[p][0]+fx[q][0]!=i && j+fx[p][1]+fx[q][1]!=j){
					sum+=3;
					l=true;
					g=true;
					i=i+fx[p][0]+fx[q][0];
					j=j+fx[p][1]+fx[q][1];
					break;
				}
			}
			if (g) break;
		}
		if (l) continue;
		printf("-1");
		return 0;
	}
	printf ("%d",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
