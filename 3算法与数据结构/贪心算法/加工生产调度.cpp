//洛谷 加工生产调度
#include<iostream>
#include<algorithm>
#define maxn 1000
using namespace std;
struct mac{
	int a;
	int b;
}f1[maxn],f2[maxn];
int comp1(mac x,mac y) {
	return x.a<y.a
}
int comp2(mac x,mac y){
	return x.b>y.b
}
int main(){
	int n,t1,t2,p=0;q=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>t1>>t2;
		if(t1>t2){
			f1[p++].a=t1;
			f1[p++].b=t2;
		}
		else{
			f2[q++].a=t1;
			f2[q++].b=t2;
		}
	}
	
} 
 
