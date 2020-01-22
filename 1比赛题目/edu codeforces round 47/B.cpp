#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100005
using namespace std;
char s[maxn];
int main() {
	scanf("%s",s);
	int len=strlen(s);
	int swap_cnt=1;
	while(swap_cnt>0) {
		swap_cnt=0;
		for(int i=0; i<len-1; i++) {
			if(s[i]=='1'&&s[i+1]=='0'){
				swap(s[i],s[i+1]);
				swap_cnt++;
			}
			if(s[i]=='2'&&s[i+1]=='1'){
				swap(s[i],s[i+1]);
				swap_cnt++; 
			} 
		}
	}
	printf("%s",s);
}
