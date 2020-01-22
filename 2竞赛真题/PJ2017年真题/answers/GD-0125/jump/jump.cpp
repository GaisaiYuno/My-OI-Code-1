#include<iostream>
#include<fstream>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
int n,d,k,num[1000002],f[500002],nn;
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>k;
	int sum=0;
	for(int i=1;i<=n;i++){
		int xi,si;
		cin>>xi>>si;
		num[xi]=si;
		sum+=max(0,si);
		nn=max(nn,xi);
	}
	if(sum<k){
		cout<<-1;return 0;
	}
	int L=0,R=nn+1;
	while(L!=R-1){
		int mid=(L+R)/2;
		f[1]=num[1];
		for(int i=2;i<=nn;i++){
			int maxn=-999999999;
			int left=max(1,i-(d+mid)),right=min(i-1,i-(d-mid));
		//	cout<<left<<" "<<right<<endl;
			for(int j=left;j<=right;j++)
				maxn=max(maxn,f[j]);
			f[i]=maxn+num[i];
		}
		int maxn=-999999999;
		for(int i=1;i<=nn;i++)
			maxn=max(maxn,f[i]);
	//	cout<<L<<" "<<mid<<" "<<R<<" "<<maxn<<endl;
		if(maxn>=k)R=mid;
		else L=mid;
	}
	cout<<L;
	return 0;
}
