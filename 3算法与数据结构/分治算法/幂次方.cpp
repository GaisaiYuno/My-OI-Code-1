//洛谷 幂次方 
#include<iostream>
using namespace std;
int a[16]={1,2,4,8,16,32,64,128,256,512,1024,2046,4056,8192,16384,32768};
int search(int s,int e,int x){
	int mid=(s+e)/2;
    if(s>e) return -1;
	if(x>=a[mid]&&x<a[mid+1]) return mid;
	else if(x<a[mid]) search(s,mid-1,x);
	else search(mid+1,e,x);	  
}
void div(int n){
	int i=0;//不能是全局变量 
	if(n!=0){ 
    	i=search(0,15,n);
    	if(i==0) cout<<"2(0)";
    	if(i==1) cout<<"2";
    	if(i>1){
    		cout<<"2(";
    		div(i);//递归传进来的是i;
    		cout<<")";
		}
		if(n>a[i]){
			cout<<"+"; 
			div(n-a[i]);
			
			
		} 
	} 
	return;
} 
int main(){
	int n;
	cin>>n;
	div(n);
	return 0;
} 
