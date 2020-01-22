#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std; 
int n;
string a; 
int is_num(char c){
	if(c>='0'&&c<='9') return 1;
	else return 0;
}
int str10_to_int(string s){//将字母转换为数字 
	int len=s.length();
	int x=0;
	for(int i=0;i<len;i++){
		x=x*10+s[i]-'0';
	}
	return x;
}
int str26_to_int(string s){
	int len=s.length();
	int x=0;
	for(int i=0;i<len;i++){
		x=x*26+s[i]-'A'+1;
	}
	return x;
} 
string int_to_str10(int x){
	char tmp1[20],tmp2[20];
	memset(tmp1,0,sizeof(tmp1));
	memset(tmp2,0,sizeof(tmp2));
	int size=0;
	while(x>0){
		tmp1[size++]='0'+x%10; 
	    x/=10;
	}
	for(int i=size-1;i>=0;i--){
		tmp2[size-1-i]=tmp1[i];
	}
	string ans=tmp2;
	return ans;
}
string int_to_str26(int x){
	char tmp1[20],tmp2[20];
	memset(tmp1,0,sizeof(tmp1));
	memset(tmp2,0,sizeof(tmp2));
	int size=0;
	int last_mod=1;
	while(x>0){
		int mod=x%26;
		if(mod==0){
			 tmp1[size++]='Z';
			 x/=26;
			 x--;
		}else{
			tmp1[size++]='A'+mod-1;
			x/=26;
		}
		
	}
	for(int i=size-1;i>=0;i--){
		tmp2[size-1-i]=tmp1[i];
	}
	string ans=tmp2;
	return ans;
}
int judge_system(string s){
	int len=s.length();
	int cnt=0;
	for(int i=1;i<len;i++){
		if(is_num(a[i])&&!is_num(a[i-1])){
			cnt++;
		}
	}
	if(cnt==2) return 1;	
	else return 2; 
	//cnt=2为第一种,cnt=1为第二种 
}
//R228C494
//R98C688
string convert(string s){
	int type=judge_system(s);
	int len=s.length();
	char a[100];
	memset(a,0,sizeof(a));
	if(type==1){
		int pos1,pos2;
		for(int i=0;i<len;i++){
			if(is_num(s[i])&&!is_num(s[i-1])){
				pos1=i;
			}
			if(is_num(s[i])&&!is_num(s[i+1])){
				pos2=i;
				break;
			}
		}
		string num1s=s.substr(pos1,pos2-pos1+1);
//		cout<<"num1s="<<num1s<<endl;
		int new_s=pos2;
		for(int i=new_s+1;i<len;i++){
			if(is_num(s[i])&&!is_num(s[i-1])){
				pos1=i;
				break;
			}
		}
		pos2=len-1;
		int num2=str10_to_int(s.substr(pos1,pos2-pos1+1));
//		cout<<num2<<endl;
		string num2s=int_to_str26(num2);
//		cout<<"num2s="<<num2s<<endl;
		int len_num1s=num1s.length();
		int len_num2s=num2s.length();
		for(int i=0;i<len_num2s;i++){
			a[i]=num2s[i];
		}
		for(int i=0;i<len_num1s;i++){
			a[len_num2s+i]=num1s[i];
		}
	}else{
		int pos1,pos2;
		for(int i=0;i<len;i++){
			if(is_num(s[i])&&!is_num(s[i-1])){
				pos1=i;
			}
			if(is_num(s[i])&&!is_num(s[i+1])){
				pos2=i;
				break;
			}
		}
		string num1s=int_to_str10(str26_to_int(s.substr(0,pos1))); 
//		cout<<str26_to_int(s.substr(0,pos1))<<"  num1s="<<num1s<<endl;
		string num2s=s.substr(pos1,pos2-pos1+1);
		int len_num1s=num1s.length();
		int len_num2s=num2s.length();
		a[0]='R';
		for(int i=0;i<len_num2s;i++){
			a[i+1]=num2s[i];
		}
		a[len_num2s+1]='C';
		for(int i=0;i<len_num1s;i++){
			a[len_num2s+i+2]=num1s[i];
		}
	}
	string ans=a;
	return ans;
} 
int main(){
	scanf("%d",&n);
	while(n--){
		cin>>a;
		cout<<convert(a)<<endl;
	}
} 
