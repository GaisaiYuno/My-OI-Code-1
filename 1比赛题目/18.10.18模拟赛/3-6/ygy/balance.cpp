#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
typedef pair<int,int>mp;
vector<mp>dots;
inline char gc(){
	static char bb[1000000],*s=bb,*t=bb;
	return s==t&&(t=(s=bb)+fread(bb,1,1000000,stdin),s==t)?EOF:*s++;
}
inline int read(){
	register int x=0;register char ch=getchar();
	while(ch<48)ch=getchar();
	while(ch>=48)x=x*10+ch-48,ch=getchar();
	return x;
}
int a[100005],b[100005],siza,sizb;
mp mapa(int a,int b){return mp(b,a);}
vector<int>r[100005];
int main(){
	freopen("balance.in","r",stdin);
	freopen("balance.out","w",stdout);
	n=read();
	for(int i=0;i<n;i++)
		dots.push_back(mapa(read(),read()));
	for(int i=0;i<n;i++)a[i]=dots[i].first,b[i]=dots[i].second;
	sort(a,a+n);siza=unique(a,a+n)-a;
	sort(b,b+n);sizb=unique(b,b+n)-b;
	for(vector<mp>::iterator it=dots.begin();it!=dots.end();it++)
		it->first=lower_bound(a,a+siza,it->first)-a,
		it->second=lower_bound(b,b+sizb,it->second)-b;
//	for(vector<mp>::iterator it=dots.begin();it!=dots.end();it++)
//		r[it->first].push_back(it->second);
//	for(int i=0;i<siza;i++)
//		sort(r[i].begin(),r[i].end());
	int ans=0x7fffffff;
	for(int i=0;i<siza;i++){
		for(int u=0;u<sizb;u++){
			int ss=0,sb=0,bs=0,bb=0;
			for(int j=0;j<n;j++){
//				cout<<a[dots[j].first]<<' '<<b[dots[j].second]<<' ';
				if(dots[j].first<=i){
					if(dots[j].second<=u){
//						cout<<"ss\n";
						ss++;
					}
					else sb++;
				}else{
					if(dots[j].second<=u){
						bs++;
//						cout<<"bs\n";
					}
					else bb++;
				}
			}
//			cout<<a[i]<<' '<<b[u]<<' '<<max(max(sb,bs),max(ss,bb))<<endl;
			ans=min(ans,max(max(sb,bs),max(ss,bb)));
		}
	}
	cout<<ans;
}
