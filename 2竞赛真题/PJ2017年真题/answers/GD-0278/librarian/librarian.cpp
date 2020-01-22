#include<iostream>
#include<string.h>
#include<stdio.h>
#include<math.h>
using namespace std;
int shu[12],s[2000];
int n,a,b,sum,i,j,q;
int pan(int a,int b){
	int w;
	
	for(i=0;i<=n;i++){
		if(b<s[i]){
		
		w=s[i]-b;
		if(w%shu[a]==0){cout<<s[i]<<endl;return 0;
		}}
		
		
	}
	cout<<-1<<endl;
	
	
	
}
void quick(int f,int l){
	if(f<l){
		int i=f,j=l,x=s[i];
		while(i<j){
			while(i<j&&s[j]>=x)j--;
			if(i<j)s[i++]=s[j];
			while(i<j&&s[i]<x)i++;
			if(i<j)s[j--]=s[i];	
			
		}
		s[i]=x;
		quick(f,i-1);
		quick(i+1,l);
		
		
	}
	
	
}


int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	shu[0]=1;
	shu[1]=10;
	shu[2]=100;
	shu[3]=1000;
	shu[4]=10000;
	shu[5]=100000;
	shu[6]=1000000;
	shu[7]=10000000;
	shu[8]=100000000;
	for(i=0;i<n;i++){ cin>>s[i];}
	quick(0,n-1);
	for(int one=0;one<q;one++){
		cin>>a>>b;
		pan(a,b);
	}
	return 0;
}
