#include<iostream>
#define maxn 101
using namespace std;
int n,m,k,s;
struct item {
	int a;
	int b;
} c[maxn];
int f[maxn][maxn];
int main() {
	//此处应改为多组输入数据  
	cin>>n>>m>>k>>s;
	for(int i=0; i<k; i++) {
		cin>>c[i].a>>c[i].b;
	}
	for(int i=0; i<k; i++) {
		for(int u=0; u<s; u++) {
			for(int j=0; j<m; j++) {
				f[i][j]=max(f[i-c[u].b][j-1]+c[u].a,f[i][j]);
				//f[j]=max(f[j],f[j-c[i].b]+c[i].a);
			}
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<s;j++){
			cout<<f[i][j]<<' ';
		}
		cout<<endl;
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<s;j++){
			if(f[i][j]>=n) {
				cout<<i<<endl;
				return 0;
			} 
		}
	}
	cout<<-1<<endl;
	return 0;
}
/*状态转移方程
    f[i][j]表示忍耐度为i,杀了j只怪时的最大经验 
    f[i][j]=max(f[i-b[k]][j-1]+a[k],f[i][j])
*/
