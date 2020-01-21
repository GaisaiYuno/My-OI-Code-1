#include<iostream>
#include<cstring>
using namespace std;
void pai2(int in[],int n) {

	int x,j,i;
	for(i=1; i<n; i++) {
 		x=in[i];
		j=i-1;
		while(x<in[j]&&j>=0) {
			in[j+1]=in[j];
			j--;
		}
		in[j+1]=x;
	}
	for(int p=0;p<n;p++) cout<<in[p]<<' ';
}
int main(){
	int test[5]={-6,-18,3,5,7};
	pai2(test,5);
    return 0;
}	
