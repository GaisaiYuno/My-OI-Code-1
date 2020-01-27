//洛谷 FBI树 
#include<iostream>
#include<cstdio>
using namespace std;
int n;
int a[10000];
char b[10000];
void build(int pos/*存储在b数组中的位置*/,int left,int right){
	int sum=0;
	for(int i=left;i<=right;i++) sum+=a[i];
	if(sum==right-left+1) b[pos]='I';
	else if(sum==0) b[pos]='B';
	else b[pos]='F' ;
	if(left==right) {
		cout<<b[pos];
		return;
	}
	build(2*pos,left,(left+right)/2);
	build(2*pos+1,(left+right)/2+1,right);
    cout<<b[pos];
    return;
}
int main(){
	cin>>n;
    n=1<<n;
    //cout<<n<<endl;
	for(int i=1;i<=n;i++)  scanf("%1d",&a[i]); //直接一位一位 输入 
	build(1,1,n);
	return 0;
}
