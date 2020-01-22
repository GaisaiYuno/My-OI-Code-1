#include<iostream>
#include<cstdio>
#include<math.h>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
long long  a[500005],b[500005];
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	long long i,j,k,m,n,s=0,p,q,u=0,d,r=-1,w;
	long long e,o,v,l,an=-1;
	cin>>n>>d>>k;
	for(i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		r=max(a[i],r);
	}
	l=0;
	p=d;
	q=d;
	long long g=0,h=0,kk=1,uu=0,tt=0;
	while(l<r){
		m=(l+r+1)/2;
		q=d+m;
		if(m>=d) p=1;
		else p=d-m;
		w=0;
		u=0;
		e=-1000000;
		o=0;
		s=0;
		l=0;
		v=0;
		kk=0;
		g=0;
		while(u!=n){
			while(w<n){
				v=0;
				h=0;
				i=w+1;
				if(a[i]-a[w]<=q&&a[i]-a[w]>=p){
					v=e;
					e=max(e,b[i]);
					if(e!=v) l=i;
					if(l==i) h=1;
					if(b[i]>=0){
						w=i;
						s+=b[i];
					}
				}
				if(l==0&&s<k){
					w=i;
					kk=1;
					for(uu=w;uu<=n;uu++){
					if(a[uu]-a[w]<=q&&a[uu]-a[w]>=p) {
						w=i+1;
						break;
					}
					}
					if(v!=0&&w==i) s+=b[i];
					else if(w==i) kk=0;
				}
				if(v==0&&kk==0){
				 	break;
				}
				l=0;
			}
			if(s<k){
				o=-1;
				if(h==0){
					u=n;
					g=-1;
				}
				w=l;
				l=0;
			}
			else {
				u=n;
			}
		}
		if(s<k) g=-1;
		if(g==0) {
			r=m-1;
			if(an==m) tt++;
			an=m;
		}
		else {
			l=m;
			tt=0;
			if(an==m) tt++;
		}
		if(tt==50) break;
	}
	cout<<an;
	return 0;
}
