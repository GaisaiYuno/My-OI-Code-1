#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int fang[500000],zi[500000];
int n,d,k,i,j;
long long sum;

/*void go(int a,int b){
	int q=a; int w=b;int weizhi=0;

	
	for(i=q;i<=n;i++){
		if(sum>=k){cout<<w;return;}
		if((weizhi+d+w<fang[i]||weizhi+d-w>fang[i])and (zi[i]<=0))continue;
		if(weizhi+d+w<fang[i]||weizhi+d-w>fang[i]){
		if(fang[i]-weizhi>d+w)w=fang[i]-d;
		if(weizhi+d-w>fang[i])w=d-(weizhi+d-w-fang[i]);
		}
		sum+=zi[i];
		weizhi=fang[i];
	}
	
}*/
void go(int a,int b){
	int q=a; int w=b;int weizhi=0;
	int max,maxi;

	
	for(i=q;i<=n;i++){
		if(sum>=k){cout<<w;return;}
		max=-10000000;
		maxi=weizhi;
		for(j=i;j<=n;j++){
		if(weizhi+d+w>fang[j]&&weizhi+d-w<fang[j]){
			if(zi[i]>=max){max=zi[j];maxi=j;
			}
			
			
			}
			if(weizhi+d+w<fang[j])break;
			
		}
		if(maxi==weizhi){
		if(weizhi+d+w<fang[i]||weizhi+d-w>fang[i]){
		if(fang[i]-weizhi>d+w)w=fang[i]-d;
		if(weizhi+d-w>fang[i])w=d-fang[i]-w-weizhi;
		}
		sum+=zi[i];
		weizhi=fang[i];	
		}else {
			sum+=max;
			weizhi=fang[maxi];
		}

	}
	
}
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>k;
	for(i=1;i<=n;i++){
		cin>>fang[i]>>zi[i];
		if(zi[i]>0){sum+=zi[i];}
	}
	if (sum<=k){cout<<-1;return 0;}
	else {sum=0; go(1,0);
	}
	return 0;
}
