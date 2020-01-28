#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=5e5+10,maxk=30+5;
int n,k,p,a[maxn],k1,k2;
ll val0[maxk],val1[maxk];
vector<int> vec;
vector<pair<ll,int> > vec1,vec2;

void init(vector<int>&vec,int k){
	if(k<0||vec.empty())
		return;
	int cnt0=0,cnt1=0;
	vector<int> vec0,vec1;
	for(int i=0;i<vec.size();++i)
		if(vec[i]>>k&1){
			++cnt1;
			val1[k]+=cnt0;
			vec1.push_back(vec[i]);
		}
		else{
			++cnt0;
			val0[k]+=cnt1;
			vec0.push_back(vec[i]);
		}
	init(vec0,k-1);
	init(vec1,k-1);
}
inline int calc(pair<ll,int> limit){
	int res=0;
	for(int i=0,j=vec2.size()-1;i<vec1.size();++i){
		while(~j&&make_pair(vec1[i].first+vec2[j].first,vec1[i].second|vec2[j].second<<k1)>limit)
			--j;
		res+=j+1;
	}
	return res;
}

int main(){
	freopen("f.in","r",stdin);
	freopen("f.out","w",stdout);
	scanf("%d%d%d",&n,&k,&p);
	for(int i=0;i<n;++i)
		scanf("%d",&a[i]);
	vec=vector<int>(a,a+n);
	init(vec,k-1);
	k1=k/2;k2=k-k1;
	for(int i=0;i<1<<k1;++i){
		ll tmp=0;
		for(int j=0;j<k1;++j)
			if(i>>j&1)
				tmp+=val1[j];
			else
				tmp+=val0[j];
		vec1.push_back(make_pair(tmp,i));
	}
	sort(vec1.begin(),vec1.end());
	for(int i=0;i<1<<k2;++i){
		ll tmp=0;
		for(int j=0;j<k2;++j)
			if(i>>j&1)
				tmp+=val1[k1+j];
			else
				tmp+=val0[k1+j];
		vec2.push_back(make_pair(tmp,i));
	}
	sort(vec2.begin(),vec2.end());
	ll l1=0,r1=n*(n-1ll)/2;
	while(l1<r1){
		ll mid=(l1+r1)/2;
		if(calc(make_pair(mid,1<<k))<p)
			l1=mid+1;
		else
			r1=mid;
	}
	int l2=0,r2=(1<<k)-1;
	while(l2<r2){
		int mid=(l2+r2)/2;
		if(calc(make_pair(l1,mid))<p)
			l2=mid+1;
		else
			r2=mid;
	}
	printf("%lld %d\n",l1,l2);
	return 0;
}
