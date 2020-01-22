#include<iostream>
using namespace std;
int date1,date2,ans=0;
int year1,month1,day1;
int year2,month2,day2;
int num[8];
int f[13]={0,31,28,31,30,31,30,31,31,30,31,30,32};
void input(){
	year1=date1/10000;
	day1=date1%100;
	month1=(date1%10000-day1)/100;
	year2=date2/10000;
	day2=date2%100;
	month2=(date2%10000-day2)/100;
}
bool is_rn(int y){//ÈòÄê 
	if(y%4==0){
		if(y%100==0){
			if(y%400==0) return true;
			else return false;
		}
		return true;
	}
	return false;
}
bool judge(int x[]){
	bool ans=false;
	for(int i=0;i<8;i++){
		if(x[i]==x[8-i-1]) ans=true;
		else{
			ans=false;
			break;
		}
	}
	return ans;
} 
void form(int a,int b,int c,int out[]){
	out[0]=a/1000;
	out[1]=(a/100)%10;
	out[2]=(a/10)%100;
	out[3]=(a%1000)%10;
	out[4]=b/10;
	out[5]=b%10;
	out[6]=c/10;
	out[7]=c%10;
	return;
}
int main(){
	int i,j,k;
	cin>>date1>>date2;
	input(); 
	if(date1==date2){
		form(year1,month1,day1,num);
		if(judge(num)) ans++;
		cout<<ans;
		return 0;
	}
    for(i=month1;i<=12;i++){

    		int tmp;
    		if(j==2){
    			if(is_rn(year1)) tmp=f[2]+1;
    			else tmp=f[2];
			}
			for(int k=1;k<=tmp;k++){ 
			   form(year1,j,k,num) ;
			   if(judge(num)) ans++;
		    }
		
	}
	for(i=year1+1;i<year2;i++){
		for(j=1;j<=12;j++){
    		int tmp;
    		if(j==2){
    			if(is_rn(i)) tmp=f[2]+1;
    			else tmp=f[2];
			}
			for(int k=1;k<=tmp;k++){ 
			   form(i,j,k,num) ;
			   if(judge(num)) ans++;
		    }
		}
	}
	for(i=1;i<=month2;i++){
    		int tmp;
    		if(j==2){
    			if(is_rn(year1)) tmp=f[2]+1;
    			else tmp=f[2];
			}
			for(int k=1;k<=tmp;k++){ 
			   form(year2,j,k,num) ;
			   if(judge(num)) ans++;
		    }
		
	}
	cout<<ans;
	return 0;
}
