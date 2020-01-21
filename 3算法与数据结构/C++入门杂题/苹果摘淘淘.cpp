// Âå¹È Æ»¹ûÕªÌÔÌÔ 1505
#include<iostream>
#include<algorithm>
using namespace std;
int a[2000],t[2000];
int comp(int p,int q){
	return p>q;
}
int main(){
	int n,m,count=0;
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int j=0;j<m;j++) cin>>t[j];
	sort(a,a+n,comp);
	sort(t,t+m,comp);
	for(int k=0;k<n;k++){
		for(int u=0;u<m;u++){
			if(a[k]>t[u]&&t[u]!=0){
				t[u]=0;
			    count++;
				break;
			}
		}
	} 
	cout<<m-count;
	return 0;
} 
