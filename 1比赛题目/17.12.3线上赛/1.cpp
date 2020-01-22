#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char line[100];
const char filename[14]="Program_Name:";
const char inte[8]="integer";
const char doub[7]="double";
const char cha[5]="char";
int cnt1,cnt2,cnt3,len;
struct node1 {
	char name[11];
	char value[20];
} a[1000];
struct node2 {
	char name[11];
	char value[20];//double直接用字符串存
} b[1000];
struct node3 {
	char name[11];
	char value[20];
} c[1000];
int strncmp_new(char x[],char y[],int start){//比较从x的第start位开始是否等于y 
	for(int i=0;i<strlen(y);i++){
		if(x[i+start]!=y[i]) return 1; 
	}
	return 0;
}
int search(char x) {
	for(int i=0; i<len; i++) {
		if(line[i]==x) return i;
	}
	return -1;
}
void def(int kind) { //定义变量
	int i;
	switch(kind) {
		case 1: {
			for(i=8; i<len; i++) if(line[i]!=' '&&!isdigit(line[i])) break;
			int fpos=i;
			for(; i<len; i++) {
				if(line[i]==' ') {
					cnt1++;
					for(int j=0; j<=i-fpos; j++)a[cnt1].name[j]=line[fpos+j];
					fpos=i+1;
				}
			}
			break;
		}
		case 2: {
			for(i=7; i<len; i++) if(line[i]!=' '&&!isdigit(line[i])) break;
			int fpos=i;
			for(; i<len; i++) {
				if(line[i]==' ') {
					cnt2++;
					for(int j=0; j<=i-fpos; j++)b[cnt2].name[j]=line[fpos+j];
					fpos=i+1;
				}
			}
			break;
		}
		case 3: {
			for(i=5; i<len; i++) if(line[i]!=' '&&!isdigit(line[i])) break;
			int fpos=i;
			for(; i<len; i++) {
				if(line[i]==' ') {
					cnt3++;
					for(int j=0; j<=i-fpos; j++)c[cnt3].name[j]=line[fpos+j];
					fpos=i+1;
				}
			}
			break;
		}

	}
}
void eval(int tmp) { //赋值
	for(int i=1; i<=cnt1; i++) {
		if(strncmp(line,a[i].name,strlen(a[i].name))==0) {
			for(int j=1; j<=cnt1; j++){
			    if(strncmp_new(line,a[j].name,strlen(a[i].name)+2)==0){
				    strcpy(a[i].value,a[j].value);
				    printf("%s %s\n",a[i].name,a[i].value);
				    return;
			    }
			}
			for(int j=1; j<=cnt2; j++){
			    if(strncmp_new(line,b[j].name,strlen(a[i].name)+2)==0){
				    strcpy(a[i].value,b[j].value);
				    return;
			    }
			}
			for(int j=0; j<=len-1-tmp-2; j++) {
				a[i].value[j]=line[tmp+2+j];
			}
			printf("%s %s\n",a[i].name,a[i].value);
			return;
		}
	}
	for(int i=1; i<=cnt2; i++) {
		if(strncmp(line,b[i].name,strlen(b[i].name))==0) {
			for(int j=1; j<=cnt2; j++){
			    if(strncmp_new(line,b[j].name,strlen(b[i].name)+2)==0){
				    strcpy(b[i].value,b[j].value);
				    return;
			    }
			}
			for(int j=1; j<=cnt1; j++){
			    if(strncmp_new(line,a[j].name,strlen(b[i].name)+2)==0){
				    strcpy(b[i].value,a[j].value);
				    return;
			    }
			}
			for(int j=0; j<=len-1-tmp-2; j++) {
				b[i].value[j]=line[tmp+2+j];
			}
			printf("%s %s\n",b[i].name,b[i].value);
			return;
		}
	}
	for(int i=1; i<=cnt3; i++) {
		if(strncmp(line,c[i].name,strlen(c[i].name))==0) {
			for(int j=1; j<=cnt3; j++){
			    if(strncmp_new(line,c[j].name,strlen(c[i].name)+2)==0){
				    strcpy(c[i].value,c[j].value);
				    return;
			    }
			}
			if(line[tmp+2]==39) c[i].value[1]=line[tmp+3];
			else{
				for(int j=0; j<=len-1-tmp-2; j++) {
				   b[i].value[j]=line[tmp+2+j];
			    }
			}
			printf("%s %s\n",c[i].name,c[i].value);
			return;
		}
	}
}
void print(char out[]){
	
}
void judge() {
	int kind=0;
	if(strncmp(line,filename,13)==0) cout<<line<<endl;
	if(strncmp(line,inte,7)==0) kind=1;
	if(strncmp(line,doub,6)==0) kind=2;
	if(strncmp(line,cha,4)==0) kind=3;
	if(kind!=0) def(kind);
	int tmp=search('=');
	if(tmp!=-1) {
		eval(tmp);
	}
}
int main() {
	int kind;
	while(gets(line)) {
		kind=0;
		len=strlen(line);
		line[len]=' ';
		len+=1;
		judge();
	}
	return 0;
}
