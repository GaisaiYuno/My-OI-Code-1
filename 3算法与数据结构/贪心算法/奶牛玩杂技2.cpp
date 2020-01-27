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
    int sum,ans;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].w>>a[i].s;
	}
	sort(a,a+n,comp);
    ans=-10000000;
    sum=0;
    for(int j=0;j<n;j++)  
    {   
        ans=max(ans,sum-a[j].s);  
        sum+=a[j].w; 
    }  
	cout<<ans;
	return 0;
}
