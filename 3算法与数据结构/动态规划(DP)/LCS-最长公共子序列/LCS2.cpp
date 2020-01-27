#include<iostream>
#include<cstring>
#define maxn 151
using namespace std;
string a,b;
int f[maxn][maxn],d[maxn][maxn];
int lena,lenb;
int sa,sb,ea,eb;//子序列的开始和结束 
void find(int x,int y) {
	if(!d[x][y])
		return;
	if(d[x][y]==1) find(x-1,y);	//左
	if(d[x][y]==2) find(x,y-1);	//上
	if(d[x][y]==3) {
		find(x-1,y-1);	//左上
        //cout<<b[x-1]<<' '<<x-1<<' '<<y-1<<endl; 
        sa=min(y-1,sa);
        ea=max(y-1,ea);
        sb=min(x-1,sb);
        eb=max(x-1,eb);
        //printf("%d %d %d %d\n",sa,ea,sb,eb);
	}
}
int main() {
	while(cin>>a>>b){ 
	lena=a.length();
	lenb=b.length();
	for(int i=1; i<=lenb; i++) {
		for(int j=1; j<=lena; j++) {
			if(a[j-1]==b[i-1]) {
				int temp=max(max(f[i-1][j-1]+1,f[i][j-1]),f[i-1][j]);
				f[i][j]=temp;
				if(f[i-1][j-1]+1==temp) {
					d[i][j]=3;
				} else if(f[i][j-1]==temp) {
					d[i][j]=2;
				} else {
					d[i][j]=1;
				}
			} else if(f[i][j-1]>f[i-1][j])	{
				f[i][j]=f[i][j-1];
				d[i][j]=2;
			} else {
				f[i][j]=f[i-1][j];
				d[i][j]=1;
			}
		}
	}
	sa=sb=100000;
	ea=eb=-100000;
	find(lenb,lena);
	for(int i=0;i<sa;i++) cout<<a[i];
	for(int i=0;i<sb;i++) cout<<b[i];
	for(int i=sa;i<=ea;i++) cout<<a[i];
	for(int i=ea+1;i<lena;i++) cout<<a[i];
	for(int i=eb+1;i<lenb;i++) cout<<b[i];
	cout<<endl;
	} 
	return 0;
}
