//洛谷 小木棍【数据加强】
#include<iostream>
#include<algorithm> 
#include<cstring>
using namespace std;
int stick[66];
int used[66]={0};
int now,last;//一定要是全局变量！ 
int n,l;
bool cmp(int a,int b){
   return a>b;
}
bool dfs(int m,int left){
	//int now,last;
	if(m==0&&left==0) return true;
	if(left==0) left=l;
	now=0;
	if(left!=l) now=last;
	for(int i=now;i<n;i++){
		if(used[i]==0&&stick[i]<=left){
			if(i>0&&used[i-1]==0&&stick[i]==stick[i-1]) continue;
			last=i;
			used[i]=1;
			if(dfs(m-1,left-stick[i])) return true;
			else{
				used[i]=0;
				if(left==l&&used[i]==0) return false;
				if(left==l||stick[i]==left) return false;
			}
		}
	}
	return false;
	
}
int main(){
	int N,temp,sum;
	cin>>N;
	n=0,sum=0;
	for(int i=0;i<N;i++){
		cin>>temp;
		if(temp<=50){
			stick[n]=temp;
			sum=sum+stick[n];
			n++; 
		}
		else continue;
	}	
	sort(stick,stick+n,cmp);
	for(l=stick[0];l<=sum/2;l++){
		//if(sum%2==1&&l%2==0) continue;
		if(sum%l!=0) continue;
		memset(used,0,sizeof(used));
		if(dfs(n,l)){
			cout<<l;
			break; 
		}
	}
	if(l>sum/2) cout<<sum; 
	return 0;
} 
