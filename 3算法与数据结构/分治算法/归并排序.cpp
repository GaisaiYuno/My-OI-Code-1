#include<iostream>
#define maxn 1000 
using namespace std;
int a[maxn];
int temp[maxn];
void merge(int l,int r,int a[]){
	int mid=(l+r)/2;
	int fh=l,sh=mid+1;
	int u=l;//一定要把l的初始值存下来 
	while(fh<=mid&&sh<=r){
	  if(a[fh]<a[sh]){
	  	temp[l++]=a[fh++];
	  } 
	  else temp[l++]=a[sh++];
	}
	if(fh>mid){
		while(sh<=r) temp[l++]=a[sh++];
	}
	else {
		while(fh<=mid) temp[l++]=a[fh++];
	} 
	for(int i=u;i<=r;i++) a[i]=temp[i];
}
void div(int l,int r,int a[]){
	if(l==r) return;
	else{
		int mid=(l+r)/2;
		div(l,mid,a);
		div(mid+1,r,a);
		merge(l,r,a);
	}
}
int main(){
	int n;
	cin>>n;
	for(int k=0;k<n;k++){
		cin>>a[k];
	}
	div(0,n-1,a);
	for(int k=0;k<n;k++){
		cout<<a[k]<<' ';
	}
} 
