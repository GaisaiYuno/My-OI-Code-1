#include<iostream>
#include<cstring>
using namespace std;
void pai(int in[],int n){
	int k,max,a;
	int i,j;
	for( i=0;i<n;i++){
	 k=i;
	 for(j=i+1;j<n;j++){
	 if(in[j]<in[k]) k=j;
	 }
	 if(k!=i){
	  a=in[i];
	  in[i]=in[k];
	  in[k]=a;
	 }
	} 
	for(int p=0;p<n;p++) cout<<in[p]<<' ';

}
int main(){
	int test[10]={1,-10,-0,5,27,16,67,44,7,7};
	int m=10;
	pai(test,m);
    return 0;
}	
