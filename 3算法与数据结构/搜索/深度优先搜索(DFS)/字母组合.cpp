#include<iostream>
#include<cstdio>
using namespace std;
int a[4]={0}; 
int count=0; 
void dfs(int l,int cho){
	if(l==4){
	  for(int j=0;j<4;j++){
	  char out=a[j]+'A';
 	  cout<<out; 
	  }  
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
	freopen("letter.txt","w",stdout); 
	dfs(0,-1);
	return 0;
} 
