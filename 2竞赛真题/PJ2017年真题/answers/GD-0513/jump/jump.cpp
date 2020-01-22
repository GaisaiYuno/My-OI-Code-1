#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
int num[500005],k,n,d,t;
int getmax(int now,int s,int e){
	if(s<0){
		s=0;
	}
	s=now+s;
	int maxn=-99999,nm;
	for(int i=s;i<=e;++i){
		if(num[i]>maxn){
			maxn=num[i];
			nm=i;
		}
	}
	return nm;
}
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>k;
	for(int i=0;i<n;++i){
		cin>>t;
		cin>>num[t];
	}
	{
		int sum=0;
		for(int i=0;i<t;++i){
			if(num[i]>0){
				sum+=num[i];
			}
		}
		if(sum<k){
			cout<<"-1";
			return 0;
		}
	}
	int now,sum,tmp=n+1;
	bool canget;
	for(int g=0;g+d<n;++g){
		now=0;
		sum=0;
		canget=false;
		while(now<n){
			if(num[getmax(now,d,now+d+g)]<0){
				break;
			}
			sum+=num[getmax(now,d-g,now+d+g)];
			now+=getmax(now,d-g,now+d+g);
			if(sum>=k){
				canget=true;
			}
		}
		if(canget){
			tmp=g;
			break;
		}
	}
	cout<<tmp;
	return 0; 
}
