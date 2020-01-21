//Âå¹È »¨½³ 1970 
#include<iostream>
#define maxn 100001
using namespace std;
int h[maxn];
int a[maxn],b[maxn],f[maxn]; 
int n,m;
int main(){
	int lena,lenb;
	cin>>n;
	for(int k=0;k<n;k++){
		cin>>h[k];
	}
	lena=lenb=0;
	a[lena]=h[0];
	b[lenb]=h[0];
	for(int i=1;i<n;i++){
		int tmpa=a[1],tmpb=a[2],pa,pb;
		for(int j=1;j<i;j++){
			if(a[j]>tmpa) {
			tmpa=a[j];
			pa=j; 
			}
			if(b[j]>tmpb) {
			tmpb=b[j];
			pb=j; 
			}
		}
        if((pa%2==0&&h[i]<tmpa)or(pa%2!=0&&h[i]>tmpa)){
        	a[i]=tmpa+1;
			lena++;
		} 
		else a[i]=tmpa+1;
		if((pa%2==0&&h[i]<tmpa)or(pa%2!=0&&h[i]>tmpa)){
        	b[i]=tmpb+1;
			lenb++;
		} 
		else b[i]=tmpb+1;
		f[i]=max(tmpa,tmpb);
	}
	m=f[n-1];
	cout<<m;
	return 0;
} 
