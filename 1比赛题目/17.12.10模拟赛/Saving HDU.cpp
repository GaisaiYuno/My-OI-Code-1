//HDU 2111
#include<iostream>
#include<algorithm> 
#define maxn 105
using namespace std;
int v,n,ans;
struct node{
	int p;
	int m;
}a[maxn];
int comp(node x,node y){
	return x.p>y.p;
}
int main(){
	while(cin>>v&&v!=0){
		cin>>n;
		ans=0;
	    for(int i=1;i<=n;i++){
	     	cin>>a[i].p>>a[i].m;
		}
		sort(a+1,a+1+n,comp);
	    for(int i=1;i<=n;i++){
	    	if(v>=a[i].m){
	    		ans+=a[i].p*a[i].m;
	    		v-=a[i].m;
			}
			else{
			   ans+=v*a[i].p;
			   break;
		    }
		}
		cout<<ans<<endl;
	}
}
