#include<iostream>
#include<cstring>
#define maxn 30005
using namespace std;
int a[maxn],f[maxn],last[maxn];
int n;
int fread(){
	int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}
int main(){
	int ans,tmp;
	while(cin>>n){
		for(int i=1;i<=n;i++) a[i]=fread();
		memset(f,0,sizeof(f));
		ans=tmp=0;
		for(int i=1;i<=n;i++){//i´Ó1~n 
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
		cout<<ans<<endl;
	}
}
