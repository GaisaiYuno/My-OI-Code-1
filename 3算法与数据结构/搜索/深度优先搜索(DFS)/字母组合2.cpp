#include<iostream>
#include<cstdio>
#define max 6
using namespace std;
int a[max]={0}; 
int count=0; 
void dfs(int l,int cho){
	if(l==max){
	  for(int j=0;j<max;j++){
	  char out=a[j]+'A';
 	  cout<<out; 
	  }  
	  count++;//可不用 
	  cout<<'\n';
	  return; 
	}else{
		for(int i=cho+1;i<26;i++){
			a[l]=i;
			dfs(l+1,i);
		}
	}
}
int main(){
	freopen("letter2.txt","w",stdout); 
	dfs(0,-1);
	cout<<"共"<<count<<"个"; //可不用 
	return 0;
} 
