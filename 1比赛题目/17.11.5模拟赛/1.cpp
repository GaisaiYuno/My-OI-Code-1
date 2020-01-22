//hdu 2037
#include<iostream>
#include<algorithm>
#define maxn 105
using namespace std;
int n,ans;
struct tv{
	int start;
	int end;
}a[maxn];
int comp(tv x,tv y){
	return x.end<y.end;
}
int main(){
	while(cin>>n&&n!=0){
		for(int i=0;i<n;i++){
			cin>>a[i].start>>a[i].end;
		}
		sort(a,a+n,comp);
		int j=0; 
		ans=0;
		for(int i=1;i<n;i++){
			if(a[i].start>=a[j].end){
				j=i;
				ans++;
			}
		}
		cout<<ans+1<<endl;
	} 
	return 0;
} 
