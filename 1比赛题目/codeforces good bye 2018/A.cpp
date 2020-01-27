/*
Problem:A
Source:Codeforces Good Bye 2018 https://codeforces.com/contest/1091/
Algorithm:
Description:
*/
#include<iostream>
#include<cstdio>
using namespace std;
int y,b,r;
int main(){
	scanf("%d %d %d",&y,&b,&r);
	b-=1;
	r-=2; 
	printf("%d\n",3*min(min(y,b),r)+3);
}

