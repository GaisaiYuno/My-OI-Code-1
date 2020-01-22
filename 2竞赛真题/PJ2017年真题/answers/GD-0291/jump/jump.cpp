#include<iostream>
#include<string.h>
#include<cstdio>
using namespace std;
int i,ii,j,kk,len=0,f[500005],myheap[500005],lc[500005],n,d,k,a[500005],b[500005],l,h,mid,lefts,rights,xmin=2000000000;
bool yes;
int mymax(int x,int y){
	if (x>y) return x;
		else return y;
}
void Down_Heap(int x){
	int i=x,j=x*2;
	while (j<=len){
		if (j<len&&f[myheap[j+1]]<f[myheap[j]]) ++j;
		if (f[myheap[j]]<=f[myheap[i]]) break;
		swap(lc[myheap[i]],lc[myheap[j]]);
		swap(myheap[i],myheap[j]);
		i=j,j=i*2;
	}
}
void Up_Heap(int x){
	int i=x,j=i/2;
	while (i>1){
		if (f[myheap[i]]<=f[myheap[j]]) break;
		swap(lc[myheap[i]],lc[myheap[j]]);
		swap(myheap[i],myheap[j]);
		i=j,j=i/2;
	}
}
main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&kk);
	for (i=1; i<=n; ++i) scanf("%d%d",&a[i],&b[i]);
	l=1,h=a[n]-d;
	while (l<=h){
		mid=(l+h)/2;
		lefts=mymax(d-mid,1);
		rights=d+mid;
		j=k=0,ii=1,len=0;
		memset(lc,0,sizeof(lc));
		memset(myheap,0,sizeof(myheap));
		memset(f,0,sizeof(f));
		myheap[++len]=0;
		lc[0]=1;
		yes=0;
		while (a[ii]-a[j]<lefts) ++ii;
		for (i=ii; i<=n; ++i){
			while (a[i]-a[j]>rights){
				f[a[j]]=-2000000000;
				Down_Heap(lc[a[j]]);
				++j;
			}
			if (j>k) k=j;
			while (a[i]-a[k+1]>=lefts){
				++k;
				myheap[++len]=k;
				lc[k]=len;
				Up_Heap(len);
			}
			f[i]=f[myheap[1]]+b[i];
			if (f[i]>=kk){
				yes=1;
				break;
			}
		}
		if (yes==1){
			h=mid-1;
			if (mid<xmin) xmin=mid;
		}
			else l=mid+1;
	}
	if (xmin==2000000000) printf("-1\n");
		else printf("%d\n",xmin);
	fclose(stdin);
	fclose(stdout);
}
