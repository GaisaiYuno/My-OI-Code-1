#include<iostream>
#include<stdio.h>
#include<cstdlib>
using namespace std;
int main(){
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int A,B,C;
	cin>>A>>B>>C;
	cout<<A*0.2+B*0.3+C*0.5;
	return 0;
}
