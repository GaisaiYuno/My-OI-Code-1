//hdu 2100 
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 205
int num1[maxn],num2[maxn],sum[maxn];
int n,x;
using namespace std;
int main(){
	string a,b,c;
	while(cin>>a>>b){
		memset(num1,0,sizeof(num1));
		memset(num2,0,sizeof(num2));
		memset(sum,0,sizeof(sum));
		x=0;
		for(int i=0;i<a.length();i++) num1[a.length()-i-1]=a[i]-'A';
		for(int i=0;i<b.length();i++) num2[b.length()-i-1]=b[i]-'A';
		n=max(a.length(),b.length());
		for(int i=0;i<n;i++){
			sum[i]=num1[i]+num2[i]+x;
			if(sum[i]>=26) {
				x=sum[i]/26;
				sum[i]%=26;
			}
			else x=0; 
		}
	    sum[n]=x; 
	    int c;
	    for(c=n;c>=0;c--){
	    	if(sum[c]!=0) break;
		}
		for(;c>=0;c--){
			printf("%c",sum[c]+'A');
		}
	    cout<<endl;
	}
	return 0;
} 
