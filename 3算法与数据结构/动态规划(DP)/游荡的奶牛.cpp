//��� �ε�����ţ
#include<iostream>
#include<cstring>
using namespace std;
char a[101][101];
int f[16][101][101];
const int hx[4]= {0,0,1,-1},hy[4]= {1,-1,0,0};
int n,m,t,r1,c1,r2,c2;
int main() {
	cin>>n>>m>>t;
	for(int p=1; p<=n; p++) {
		for(int q=1; q<=m; q++) cin>>a[p][q];
	}
	cin>>r1>>c1>>r2>>c2;
	f[0][r1][c1]=1;
	//�������ƹ����� 
	for(int l=1; l<=t; l++) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
                for(int u=0;u<4;u++){
                	if(a[i][j]=='*') f[l][i][j]=0;
                	else f[l][i][j]=f[l][i][j]+f[l-1][i+hx[u]][j+hy[u]];
				}
			}
		}
	}
    cout<<f[t][r2][c2];
    return 0;
}
/*״̬ת�Ʒ���
    dp[i][x][y]=dp[i-1][x+1][y]+dp[i-1][x-1][y]+dp[i-1][x][y+1]+dp[i-1][x][y-1]
    (dp[a][b][c]��ʾʱ��Ϊaʱ���㣨b,c����·�������� 
*/ 
