#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int n,m,k,a[500010],ans,d,f[500010],l=0,r=10000,mid,b[500010];
long long tot;
int check(int aa){
for(int i=1;i<=n;i++)f[i]=-9999999;
f[1]=0;
	int maxx=0;
for(int i=1;i<=n;i++){
for(int j=i;j>0;j--){
if((a[i]-a[j])>=max(d-aa,0)&&(a[i]-a[j])<=d+aa){
f[i]=max(f[i],f[j]+b[j]);	
}
if((a[i]-a[j])>d+aa)break;	
}
maxx=max(maxx,f[i]);	
}
cout<<maxx<<' '<<aa<<endl;
if(maxx>=k)return 1;
return 0;	
}
int main(){	
scanf("%d%d%d",&n,&d,&k);
for(int i=1;i<=n;i++){
	scanf("%d%d",&a[i],&b[i]);
	if(b[i]>0)tot+=b[i];
}
if(tot<k){
printf("-1");
return 0;	
}	
while(l<r){
mid=(l+r)/2;
if(check(mid)==1)r=mid;
else l=mid+1;	
}
printf("%d",mid);
}
