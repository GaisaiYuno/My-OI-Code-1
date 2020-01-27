//书 p278 例7.2 
#include<iostream>
//#include<algorithm>
using namespace std;
int n;
int a[1000];
int mid;
int  search(int s,int e,int x){
	mid=(s+e)/2;
    if(s>e) return 0;//找不到，l,r相同 再递归l>r return 0 
	if(x==a[mid]) return mid;
	else if(x<a[mid]) search(s,mid-1,x);
	else search(mid+1,e,x);
	  
}
int main(){
	int x;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	cin>>x;
    if(search(1,n,x)>0)cout<<search(1,n,x);
    else cout<<"impossible";
    return 0;
} 
