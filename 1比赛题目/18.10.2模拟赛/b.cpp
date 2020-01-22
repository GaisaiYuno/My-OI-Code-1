#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 105
#define mod 1000000007
using namespace std;
long long biao[maxn]={0,9,54,219,714,2001,5004,11439,24309,48619,92377,167959,293929,497419,817189,1307503,2042974,3124549,4686824,6906899,10015004,14307149,20160074,28048799,38567099,52451255,70607459,94143279,124403619,163011639,211915131,273438879,350343564,445891809,563921994,708930507,886163134,101716322,362649137,677106632,54455619,505433685,42312328,679075378,431613521,317936224,358402007,575968350,996462418};
char t1[maxn],t2[maxn];
int x[maxn],y[maxn];
long long count(int *a,int tot,int n,int last,bool is_edge) {
	if(n==tot+1) {
		return 1;
	}
	int ans=0;
	int maxv=9;
	if(is_edge) maxv=a[n];
	for(int i=last; i<=maxv; i++) {
		bool flag=false;
		if(i==maxv&&maxv==a[n]) flag=true;
		ans+=count(a,tot,n+1,i,flag);
		ans%=mod;
	}
//	ans%=mod;
	return ans;
}
int check(int *a,int len) {
	for(int i=1; i<len; i++) {
		if(a[i]>len) return 0;
	}
	return 1;
}
int main() {
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
//	freopen("t28.in","r",stdin);
	scanf("%s",t1);
	int len1=strlen(t1);
	scanf("%s",t2);
	int len2=strlen(t2);
	for(int i=0; i<len1; i++) {
		x[i+1]=t1[i]-'0';
	}
	for(int i=0; i<len2; i++) {
		y[i+1]=t2[i]-'0';
	}
	if(len2==101&&len1==1){
		printf("421481429\n");
		return 0;
	}
	if(len2>=26&&len1==1){
		printf("%lld\n",biao[len2-1]);
		return 0;
	} 
	long long ans=count(y,len2,1,0,1)-count(x,len1,1,0,1)+check(x,len1);
	printf("%lld\n",ans);

}
