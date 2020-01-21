//洛谷 a-b数对（加强版） 
//分治优化 
#include<iostream>
#include<cstring>
#define maxn 100000
using namespace std;
int n,c;
int num[maxn][2];
int mid;
int ans=0;
int  search(int s,int e,int x){
	mid=(s+e)/2;
    if(s>e) return -1;//找不到，l,r相同 再递归l>r return 0 
	if(x==num[mid][0]) return mid;
	else if(x<num[mid][0]) search(s,mid-1,x);
	else search(mid+1,e,x);	  
}
int main(){
	cin>>n>>c; 
	int k=0;
	num[k][1]=1;
	cin>>num[k++][0];

	while(--n){
		int temp;
		cin>>temp;
		if(num[k-1][0]==temp){
			num[k-1][1]++;
		}
		else {
		num[k][1]=1;
		num[k++][0]=temp;	
		} 
	}
	//cout<<k;
	for(int i=0;i<k;i++){ 
	   //cout<<i<<" "<<num[i][0]-c<<endl;
	   if(search(0,i,num[i][0]-c)>-1) {
	   	//	ans+=num[search(0,k-1,num[i][0]-c)][1]*num[i][1];
	   			ans+=num[mid][1]*num[i][1];
	   }
	   //if(search(i,k-1,num[i][0]+c)) ans+=num[search(0,k-1,num[i][0]+c)][1]*num[i][1];
	} 
	cout<<ans;
	return 0;
} 
