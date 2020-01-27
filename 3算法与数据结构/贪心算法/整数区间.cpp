//书 p268 例6.8 
#include<iostream>
#include<algorithm>
using namespace std;
int s[10000],e[10000];//s开头，e结尾 
int main(){
	int n;
	cin>>n; 
	for(int i=0;i<n;i++)	cin>>s[i]>>e[i];
	sort(e,e+n);
	int count=0,x=-1;
	for(int j=0;j<n;j++){
		if(x>=s[j]) continue;
		else{
		count++;
		x=e[j];
		}
	}
	cout<<count;
	return 0;
} 
