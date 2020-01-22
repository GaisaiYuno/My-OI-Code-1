#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100005
using namespace std;
int find_next(char *s,char *q,int last_pos) {
	int slen=strlen(s);
	int qlen=strlen(q);
	for(int i=0; i<slen; i++) {
		int j=0;
		for(j=0; j<qlen; j++) {
			if(s[i]!=q[j]) break;
			else i++;
		}
		if(j==qlen&&i-qlen>last_pos) return i-qlen;
		if(j>0)i--;
	}
	return -1;
}
char s[maxn];
char t1[]="AB";
char t2[]="BA";
int is_ok1() {
	int lst1,lst2;
	lst1=lst2=-1;
	int s1,s2;
	int cnt=1;
	while(cnt++) {
//		printf("%d %d\n",s1,s2);
		s1=find_next(s,t1,lst1);
		if(s1==-1) return 0;
        int flag;
        lst2=-1;
		while(1) {
			s2=find_next(s,t2,lst2);
			if(s2!=-1){
				if(s1+1!=s2&&s1!=s2&&s2+1!=s1)return 1;
				lst2=s2;
			} 
			if(s2==-1){
				break;
			}
		}
//		printf("%d %d\n",s1,s2);
		if(lst1!=-1||cnt==1) lst1=s1;
		else return 0;
	}
	return 0;
}
int is_ok2(){
	int lst1,lst2;
	lst1=lst2=-1;
	int s1,s2;
	int cnt=1;
	while(cnt++) {
//		printf("%d %d\n",s1,s2);
		s1=find_next(s,t2,lst1);
		if(s1==-1) return 0;
        int flag;
        lst2=-1;
		while(1) {
			s2=find_next(s,t1,lst2);
			if(s2!=-1){
				if(s1+1!=s2&&s1!=s2&&s2+1!=s1)return 1;
				lst2=s2;
			} 
			if(s2==-1){
				break;
			}
		}
//		printf("%d %d\n",s1,s2);
		if(lst1!=-1||cnt==1) lst1=s1;
		else return 0;
	}
	return 0;
} 
int main() {
	while(scanf("%s",s)!=EOF) {
		if(is_ok1()||is_ok2()) printf("YES\n");
		else printf("NO\n");
	}
}
