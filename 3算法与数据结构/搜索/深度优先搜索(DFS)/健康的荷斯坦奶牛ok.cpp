//Âå¹È  ½¡¿µµÄºÉË¹Ì¹ÄÌÅ£
#include<iostream>

using namespace std;
int vn,gn;
int v[30],g[30][30];
int sumv[30],cho[30],ans[30];
int p=1000000000,cnt=0;
void dfs(int d,int x){
	if(d>gn){
		bool flag=true;
	//	for(int i=0;i<vn;vn++) {
		for(int i=0;i<vn;i++) {
		//	if(sumv[i]>=v[i]){
				if(sumv[i]<v[i]){
				flag=false;
				break;
			}
		}
		if(flag) {
			if(x<p) {
				p=x;
				for(int j=0;j<gn;j++) ans[j]=cho[j];
			}
		}
		return;
	}
	cho[cnt++]=d;
	for(int k=0;k<vn;k++) sumv[k]+=g[d][k];
	dfs(d+1,x+1);
	for(int k=0;k<vn;k++) sumv[k]-=g[d][k];
	cnt--;
	dfs(d+1,x);
}
int main(){
	cin>>vn;
	for(int i=0;i<vn;i++) cin>>v[i];
	cin>>gn;
	for(int j=0;j<gn;j++){
		for(int k=0;k<vn;k++) cin>>g[j][k];
	}
	dfs(0,0);
	cout<<p<<' ';
//	for(int u=0;u<p;u++) cout<<ans[u]<<' ';
		for(int u=0;u<p;u++) cout<<ans[u]+1<<' ';
	return 0;
} 
