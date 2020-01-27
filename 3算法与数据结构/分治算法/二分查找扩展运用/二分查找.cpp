#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<algorithm>
using namespace std;
int a[105];
int bin_search1(int l,int r,int x){
	while(l<=r){
		int mid=(l+r)>>1;
		if(a[mid]==x) return mid;
		else if(a[mid]<x) l=mid+1;
		else r=mid-1;
	}
	return -1;
}
int bin_search2(int l,int r,int x){
	while(l<r){
		int mid=(l+r)>>1;
		if(a[mid]>x) r=mid;
		else l=mid+1;
	}
	return l;
}
int bin_search3(int l,int r,int x){
	while(l<r){
		int mid=(l+r)>>1;
		if(a[mid]>=x) r=mid;
		else l=mid+1;
	}
	return l;
}
int main(){
	int x;
	for(int i=1;i<=100;i++) scanf("%d",&a[i]);
	scanf("%d",&x);
	printf("%d\n",bin_search1(1,100,x));
	scanf("%d",&x); 
	printf("%d\n",bin_search2(1,100,x));
	scanf("%d",&x); 
	printf("%d\n",bin_search3(1,100,x));
} 
