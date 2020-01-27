#include<iostream>
#include<cstring>
using namespace std;
int main() {
	string in;
	int len,k,i;
	cin>>in;
	len=in.length();
	int out[len];
	memset(out,0,len);
	if(in[0]=='-') {
		for(i=1; i<len; i++) 
			out[i]=in[i]-48;
		cout<<"-";
		for(k=len-1; k>1; k--)
			if(out[k]!=0) break;
		for(;k>=1; k--)
			cout<<out[k];
	} else {
		for(i=0; i<len; i++) 
			out[i]=in[i]-48;

		for(k=len-1; k>0; k--)
			if(out[k]!=0) break;
		for(;k>=0; k--)	
			cout<<out[k];
	}
	return 0;
}











