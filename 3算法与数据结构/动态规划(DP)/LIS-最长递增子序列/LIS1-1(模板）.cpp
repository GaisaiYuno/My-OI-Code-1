//��Ϊģ��1 O(n^2) 
#include<iostream>
#define maxn 1000
using namespace std;
int n,ans,x;
int a[maxn],f[maxn];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
    ans=0;
	for(int i=1;i<=n+1;i++){//i��1~n+1 
		f[i]=1;
		for(int j=1;j<i;j++){
			if(a[j]<a[i]) f[i]=max(f[j]+1,f[i]);
		}
		ans=max(ans,f[i]); 
	}
    cout<<ans;
	return 0;
} 
/*״̬ת�Ʒ���
   f[i]=max(f[j]+1,1),��a[j]<a[i] 
*/ 
