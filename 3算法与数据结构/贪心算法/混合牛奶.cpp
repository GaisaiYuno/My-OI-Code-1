//Âå¹È »ìºÏÅ£ÄÌ 1208
#include<iostream>
#include<algorithm> 
#define maxn 10000
using namespace std;
int n,m; 
struct my_milk{
	int p;
	int a;
}milk[maxn];
int comp(my_milk x,my_milk y){
	return x.p<y.p;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
     	cin>>milk[i].p>>milk[i].a;
	}
	sort(milk,milk+m,comp);
	int j=0,left=n,ans=0;
    while(left>0){
    	if(left-milk[j].a>=0){
    		left-=milk[j].a;
    		ans+=milk[j].a*milk[j].p;
		}
		else{
			ans+=left*milk[j].p;
			break;
		}
		j++;
	}
	cout<<ans;
	return 0;
} 
