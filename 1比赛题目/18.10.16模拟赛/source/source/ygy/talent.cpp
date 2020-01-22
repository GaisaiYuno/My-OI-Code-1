#include<iostream>
#include<cstdio>
using namespace std;
int n,w;
int weight[255],talent[255];
int ans;
int lat[255];
void dfs(int place,int totw,int tott){
//	if(place<n/2)putchar(place/100+48),putchar((place/10)%10+48),putchar(place%10+48),putchar(' ');
	if(place>n){
		if(totw>=w)ans=max(ans,tott/totw);
		return;
	}
	dfs(place+1,totw,tott);
	dfs(place+1,totw+weight[place],tott+talent[place]);
}
int main(){
	froepen("talent.in","r",stdin);
	freopen("talent.out","w",stdout);
	cin>>n>>w;
	for(int i=1;i<=n;i++){
		cin>>weight[i]>>talent[i];
		talent[i]*=1000;
	}
	for(int i=n;i>=1;i--)
		lat[i]=lat[i+1]+weight[i];
	dfs(1,0,0);
	cout<<ans;
}
