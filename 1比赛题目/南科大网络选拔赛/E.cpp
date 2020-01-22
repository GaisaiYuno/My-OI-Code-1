#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector> 
#define maxAuthor 20
#define maxPage 200
#define nul (string::npos)
using namespace std;
int AuthorNum=0;
string FamilyName[maxAuthor+5];
string FirstName[maxAuthor+5];
string City;
string Province;
string Publisher;
string Title;
string Type;
string BookName;
string BookAuthor;
vector<int>PageNumberArray;
string ConferenceName;
string ConferencePlace;
string WebsiteName;
string WebHttpLink;
string Date;
string Month;
string Year;

string get_content(string s){
	int pos=s.find(':');
	return s.substr(pos+1,s.length()-pos-1);
}
int get_num(string s){
	int ans=0;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9') ans=ans*10+s[i]-'0';
	}
	return ans;
}
int get_num(string s,vector<int> &a){
	int x=0;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			x=x*10+s[i]-'0';
		}else{
			x=0;
			a.push_back(x);
		}
	}
	if(x!=0) a.push_back(x);
}

string op_str(string left,char c,string right){
	if(left.size()&&right.size()) return left+c+right;
	else return left+right;
}
string op_str(string left,string s,string right){
	if(left.size()&&right.size()) return left+s+right;
	else return left+right;
}

void parase_input(string s){
	if(s.find("Author")!=nul&&s.find("Name")!=nul){
		if(s.find("Family")!=nul) FamilyName[get_num(s)]=get_content(s);
		else FirstName[get_num(s)]=get_content(s);
		AuthorNum=max(AuthorNum,get_num(s));
	}else if(s.find("City")!=nul){
		City=get_content(s);
	}else if(s.find("Publisher")!=nul){
		Province=get_content(s);
	}else if(s.find("Title")!=nul){
		Title=get_content(s);
	}else if(s.find("Type")!=nul){
		Type=get_content(s);
	}else if(s.find("BookName")!=nul){
		BookName=get_content(s);
	}else if(s.find("BookAuthor")!=nul){
		BookAuthor=get_content(s);
	}else if(s.find("ConferenceName")!=nul){
		ConferenceName=get_content(s);
	}else if(s.find("ConferencePlace")!=nul){
		ConferencePlace=get_content(s);
	}else if(s.find("WebsiteName")!=nul){
		WebsiteName=get_content(s);
	}else if(s.find("WebHttpLink")!=nul){
		WebHttpLink=get_content(s);
	}else if(s.find("Date")!=nul){
		Date=get_content(s);
	}else if(s.find("Month")!=nul){
		Month=get_content(s);
	}else if(s.find("Year")!=nul){
		Year=get_content(s);
	}else if(s.find("PageNumberArray")!=nul){
		get_num(s,PageNumberArray);
	}
}

inline char to_upper(char c){
	if(c>='a'&&c<='z') return c-'a'+'A';
	else return c;
}

string get_Initial(int s){
	string ans="";
	for(int i=0;i<s.length();i++){
		if(i==0||s[i-1]==' '){
			ans+=to_upper(s[i]);
			ans+=". ";
		}
	}
}
string get_author(){
	string ans="";
	static string Initial[maxAuthor+5];
	static string Family[maxAuthor+5];
	static string Name[maxAuthor+5];
	for(int i=1;i<=AuthorNum;i++){
		Initial[i]=get_Initial(FirstName[i]);
		Family[i]=FamilyName[i];
		Name[i]=op_str(Initial[i],' ',Family[i]);
	}
	if(AuthorNum==1) ans=Name[1];
	else if(AuthorNum==2){
		ans=Name[1]+" and "+Name[2];
	}
	else if(AuthorNum<=5){
		for(int i=1;i<=n-2;i++) ans+=Name[i]+", ";
		ans+=Name[n-1]+" and "+Name[n];
	}else{
		ans=Name[1]+" et al.";
	}
	return ans;
}

string get_publisher(){
	string ans;
	ans=op_str(op_str(op_str(City,", ",Province),", ",Country),": ",Publisher);
	return ans;
}

string get_title(){
	if(Title.length()==0) return "";
	else return '"'+Titie+'"'; 
}


int main(){

}

