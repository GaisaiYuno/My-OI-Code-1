#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime> 
#define maxv 1000
using namespace std;
typedef long long ll;
int random(int l,int r){
	return (ll)rand()*rand()%(r-l+1)+l;
}
int main(){
	srand(time(NULL));
	printf("%d %d %d\n",random(1,maxv),random(1,maxv),random(1,maxv/100));
}

