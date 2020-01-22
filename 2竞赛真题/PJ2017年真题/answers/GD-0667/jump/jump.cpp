#include<bits/stdc++.h>
using namespace std;
int n,d,k,i,j,fen,l,h,ax,m,wei,b[500001],s[500001],x[500001];
long long sum;
int find(int g){
	for(l=1;l<=n;l++){
		if(s[l]==g){
			return x[l];
		}
	}return -100000;
}
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>k;
	for(i=1;i<=n;i++){
		cin>>s[i]>>x[i];
		if(x[i]>0){
			sum=sum+x[i];
		}
	}
	if(sum<k){
		cout<<-1;
		return 0;
	}else if(d==1){
		jia:while(fen<k){
			m++;
			ax=-100000;
			for(i=wei+1;i<=wei+m+1;i++){
				ax=max(find(i),ax);
			}
			if(ax==0){
				goto jia;
			}
			for(i=wei+1;i<=wei+m+1;i++){
				if(x[i]==ax){
					fen=fen+x[i];
					wei=i;break;
				}
			}
		}
		cout<<m;
		return 0;
	}else{
		cout<<d/2;
		return 0;
	}
}
