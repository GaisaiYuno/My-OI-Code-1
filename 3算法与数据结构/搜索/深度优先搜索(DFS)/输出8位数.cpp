#include<iostream> 
using namespace std;
int shu[8]={0,0,0,0,0,0,0,0};
int used[8]={0,0,0,0,0,0,0,0};
void pl(int wei){
    if(wei==8){
	for(int i=0;i<8;i++) cout<<shu[i]+1;
	cout<<'\n';
	}
    for(int i=0;i<8;i++){
	if(used[i]==0){
	   shu[wei]=i;
	   used[i]=1;
	   pl(wei+1);
	   used[i]=0;
	   }
	}
}
int main(){
     freopen("out1.txt","w",stdout);
	 pl(0);
}
