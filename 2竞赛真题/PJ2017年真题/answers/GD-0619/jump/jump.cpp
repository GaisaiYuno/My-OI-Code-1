#include<bits/stdc++.h>
using namespace std;
int l[500500],n,d,t,val[500500],llmin,llmax,lmin,f[500500],k,lr,r;
int main(){
	freopen("jump.in.txt","r",stdin);
	freopen("jump.out.txt","w",stdout);
	cin>>n>>d>>t;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&l[i],&val[i]);
		lmin=max(lmin,l[i]-l[i-1]);
	}
	for(int g=max(lmin-d,0);g<d;g++){
		llmin=d-g; llmax=d+g;
		memset(f,-21000000,sizeof(f));
		f[0]=0;
		if(l[1]>=llmin&&l[1]<=llmax){
			f[1]=val[1];
		} 
		else continue;
		if(f[1]>=t){
			cout<<g;
			return 0;
		}
		for(int i=2;i<=n;i++){
			k=i-1;
			while(l[i]-l[k]<llmin) k--;
			r=k;
			while(l[i]-l[k]<=llmax&&k>=0) k--;
			lr=k+1;
			for(int j=min(lr,r);j<=r;j++){
				f[i]=max(f[i],f[j]+val[i]);
				if(f[i]>=t){
					cout<<g;
					return 0;
				}
			}
		}
	}
	cout<<-1;
}
