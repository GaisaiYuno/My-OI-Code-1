#include<iostream> 
using namespace std;
int main(){
    int n,jc=1;
input:
	printf("���������ݣ�");
	cin>>n;

   if(n>=0) {
	  if(n>16){
	  printf("����������һ��С��17�ķǸ���,");
	  goto input;
	  }else{
	     for(int i=1;i<=n;i++){
	    jc=jc*i	;
         } 
	  cout<<n<<"�Ľ׳���"<<jc;
	  cout<<'\n';	
	  cout<<'\n';	
	  jc=1;	
      goto input; 
      }
   }else{
   printf("����������һ���Ǹ���,");
   goto input ; 
   } 
}

