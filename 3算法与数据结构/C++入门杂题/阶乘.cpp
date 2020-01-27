#include<iostream> 
using namespace std;
int main(){
    int n,jc=1;
input:
	printf("请输入数据：");
	cin>>n;

   if(n>=0) {
	  if(n>16){
	  printf("您必须输入一个小于17的非负数,");
	  goto input;
	  }else{
	     for(int i=1;i<=n;i++){
	    jc=jc*i	;
         } 
	  cout<<n<<"的阶乘是"<<jc;
	  cout<<'\n';	
	  cout<<'\n';	
	  jc=1;	
      goto input; 
      }
   }else{
   printf("您必须输入一个非负数,");
   goto input ; 
   } 
}

