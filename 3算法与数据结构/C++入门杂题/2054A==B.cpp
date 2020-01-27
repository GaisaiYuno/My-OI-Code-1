#include<iostream>
#include<cstring>
using namespace std;
char m[100005],n[100005];
int delchar(char a[]){//将后导0删除,否则0.10和0.100会判断不等 
	int len=strlen(a),flag=0;
    for(int i=0;i<len;i++){
    	if(a[i]=='.'){
    		flag=1;
    		break;
		}
	}
	if(flag==1){
		while(a[len-1]=='0'){
			a[len-1]='\0';
			len--; 
		}
		if(a[len-1]=='.') a[len-1]='\0';
	}
}

int is_eqal(){
	int lenm=strlen(m);
	int lenn=strlen(n);
	if(lenm!=lenn) return 0;
	for(int i=0;i<lenm;i++){
		if(m[i]!=n[i]){
		    return 0;
		}
	}
	return 1;
}
int main(){
	while(~scanf("%s%s",m,n))
	{ 
		delchar(m);
		delchar(n);
		if(is_eqal()) cout<<"YES";
		else cout<<"NO";
 // 	if(is_eqal()) 	printf("YES\n");
	//	else printf("NO\n");
		
	//	if (strcmp(m, n))
	//		printf("NO\n");
	//	else
		//	printf("YES\n");
		cout<<endl;
	}
//	 return 0;
}
