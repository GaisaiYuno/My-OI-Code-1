//洛谷 导弹拦截（1020）
//O(n^2)会超时
//优化：用last[i]维护f值为i的最后一个导弹的位置，tmp记录当前已经求出最长不升子序列长度 
//枚举a[d[t]]，a[d[t-1]]，。。。，a[d[1]]是否≥当前求的导弹高度，是就更新f
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100001 
using namespace std;
int n=0,ans=0,tmp=0;
int a[maxn],f[maxn],last[maxn]; 
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){//i从1~n 
		f[i]=1;
		for(int j=tmp;j>=1;j--){
			if(a[i]<=a[last[j]]){
			    f[i]=f[last[j]]+1;
			    break; 
			} 
		}
		tmp=max(tmp,f[i]);
		ans=max(ans,f[i]); 
		last[f[i]]=i;
	}
	cout<<ans<<endl;
	ans=0;
	tmp=0; 
	//memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++){//i从1~n 
		f[i]=1;
		for(int j=tmp;j>=1;j--){
			if(a[i]>a[last[j]]){
			    f[i]=f[last[j]]+1;
			    break; 
			} 
		}
		tmp=max(tmp,f[i]);
		ans=max(ans,f[i]); 
		last[f[i]]=i;
	}
    cout<<ans;

} 
