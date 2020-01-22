#include<iostream>
#include<utility>
#include<deque>
#include<cstdio>
using namespace std;
int n,k;
int ast[300005][19];
int ist[300005][19];
int arr[300005];
typedef pair<int,int>mp;
mp minq[300005];
int mt,mh;
mp maxq[300005];
int xt,xh;
bool check(int mid) {
	mt=mh=0;
	xt=xh=0;
	for(int i=1;i<mid;i++){
		while(mt>mh&&arr[i]<minq[mt-1].first)mt--;
		while(xt>xh&&arr[i]>maxq[xt-1].first)xt--;
//		maxq.push_back(mp(arr[i],i));
		maxq[xt++]=mp(arr[i],i);
//		minq.push_back(mp(arr[i],i));
		minq[mt++]=mp(arr[i],1);
	}
	for(int i=1; i+mid-1<=n; i++) {
		//range:i-i+mid-1
		while(mt>mh&&arr[i+mid-1]<minq[mt-1].first)mt--;
		while(xt>xh&&arr[i+mid-1]>maxq[xt-1].first)xt--;
		if(mt>mh&&minq[mh].second==i-1)mh++;
		if(xt>xh&&maxq[xh].second==i-1)xh++;
		maxq[xt++]=mp(arr[i+mid-1],i+mid-1);
		minq[mt++]=mp(arr[i+mid-1],i+mid-1);
		int maxn=maxq[xh].first;
		int minn=minq[mh].first;
//		cerr<<i<<' '<<i+mid-1<<' '<<maxn<<' '<<minn<<endl;
		if(maxn-minn<=k)return true;
	}
	return false;
}
inline char gc(){
	static char bb[3000000],*s=bb,*t=bb;
	return s==t&&(t=(s=bb)+fread(bb,1,3000000,stdin),s==t)?EOF:*s++;
}
inline int read(){
	register int x=0;register char ch=gc();
	while(ch<48)ch=gc();
	while(ch>=48)x=x*10+ch-48,ch=gc();
	return x;
}
int main() {
	freopen("bed.in","r",stdin);
	freopen("bed.out","w",stdout);
	n=read(),k=read();
	for(int i=1; i<=n; i++) {
		arr[i]=read();
	}
	int l=1,r=n;
	int ans=-1;
	while(l<=r) {
		int mid=(l+r)/2;
		if(check(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans;
}
