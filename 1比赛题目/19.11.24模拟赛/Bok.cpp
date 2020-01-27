#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 500000 
using namespace std;
inline void qread(int &x){
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
}
inline void qprint(int x){
	if(x<0){
		putchar('-');
		qprint(-x);
	}else if(x==0){
		putchar('0');
		return;
	}else{
		if(x>=10) qprint(x/10);
		putchar('0'+x%10);
	}
} 
int n,k;
int a[maxn+5];

int pos[maxn+5];
int tmp[maxn+5];
int sufmin[maxn+5];

int ans[maxn+5];
/*
for(rg int i=1;i<=n;i++){
	for(rg int j=1;j<n-i+1;j++){
		if(pos[j]-pos[j+1]>=k) swap(pos[j],pos[j+1]);
	}
} 
*/
void merge_sort(int l,int r){
	if(l==r) return;
	int mid=(l+r)>>1;
	merge_sort(l,mid);
	merge_sort(mid+1,r);
	sufmin[mid]=pos[mid];
	for(int i=mid-1;i>=l;i--) sufmin[i]=min(sufmin[i+1],pos[i]);
	int i=l,j=mid+1,ptr=l;
	while(i<=mid&&j<=r){
		if(sufmin[i]-pos[j]>=k) tmp[ptr++]=pos[j++];//if(pos[j]-pos[j+1]>=k) swap(pos[j],pos[j+1]);
		else tmp[ptr++]=pos[i++];
	} 
	while(i<=mid) tmp[ptr++]=pos[i++];
	while(j<=r) tmp[ptr++]=pos[j++];
	for(int i=l;i<=r;i++) pos[i]=tmp[i];
}
int main(){
	qread(n);
	qread(k);
	for(int i=1;i<=n;i++){
		qread(a[i]);
		pos[a[i]]=i;
	}
	merge_sort(1,n);
	for(int i=1;i<=n;i++) ans[pos[i]]=i;
	for(int i=1;i<=n;i++){
		qprint(ans[i]);
		putchar('\n');
	}

}

