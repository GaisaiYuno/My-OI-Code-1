//��� �������أ�1020��
//O(n^2)�ᳬʱ
//�Ż�����last[i]ά��fֵΪi�����һ��������λ�ã�tmp��¼��ǰ�Ѿ��������������г��� 
//ö��a[d[t]]��a[d[t-1]]����������a[d[1]]�Ƿ�ݵ�ǰ��ĵ����߶ȣ��Ǿ͸���f
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
	for(int i=1;i<=n;i++){//i��1~n 
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
	for(int i=1;i<=n;i++){//i��1~n 
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
