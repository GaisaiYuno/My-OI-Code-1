//Âå¹È ÄÌÅ£ÍæÔÓ¼¼ 1842
#include<iostream>
#include<algorithm>
#define maxn 1000000
using namespace std;
int n;
struct cow{
	int w;
	int s;
}a[maxn];
int comp(cow x,cow y){
	return x.w+x.s<y.w+y.s;
}
int main() {
	int t=0,ans=-10000000;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].w>>a[i].s;
	}
	sort(a,a+n,comp);
	for(int j=1;j<n;j++){
		t=0;
		for(int k=0;k<j;k++){
			t+=a[k].w; 
		}
		t-=a[j].s;
		if(t>ans) ans=t;
	} 
	cout<<ans;
	return 0;
}
