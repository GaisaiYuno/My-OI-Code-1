#include<iostream>
#define max 105
using namespace std;
int a[max];
int b[max];
void merge(int l,int r,int a[]) {
	int mid=(l+r)/2;
	int fh=l,sh=mid+1;//前头fh，后头sh
	int ou=l;
	while(fh<=mid&&sh<=r) {
		if(a[fh]<a[sh]) {
			b[l++]=a[fh++];
	
		} else b[l++]=a[sh++];
	}
	if(fh>mid) {
		while(sh<=r) b[l++]=a[sh++];
	} else {
		while(fh<=mid) {
			b[l++]=a[fh];
			fh++;
		}
	}
	for(int i=ou; i<=r; i++) {
		a[i]=b[i];
	}

}
void div(int l,int r,int a[]) {
	if(l==r) return;
	else {
		int mid=(l+r)/2;
		div(l,mid,a);
		div(mid+1,r,a);
		merge(l,r,a);
	}
}
int main() {
	int N;
	cin>>N;
	for(int i=0; i<N; i++) cin>>a[i];
	div(0,N-1,a);
	for(int i=0; i<N; i++)cout<<a[i]<<' ';
	return 0;
}
