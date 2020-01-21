#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
#include<set>
#define INF 0x3f3f3f3f
#define maxc 26
using namespace std;
int t;
int n;

int string_to_int(string s) {//提取字符串里的数字，如果没有数字返回INF 
	int num=0;
	bool is_num=false;
	for(int i=0; i<(int)s.length(); i++) {
		if(s[i]>='0'&&s[i]<='9') {
			is_num=true;
			num=num*10+s[i]-'0';
		}
	}
	if(is_num) return num;
	else return INF;
}


int parase_cplex(string s) {//解析时间复杂度表达式 
	int pos=s.find('^');
	if(pos==-1) return 0;//如果是O(1),返回0 
	else return string_to_int(s.substr(pos+1,s.length()-pos-2)); //否则返回指数 
}

struct loop {
	string name;//变量名
	string ls;//左边界 
	string rs;//右边界 
	//左右边界转成数字后的结果,如果是n,就标记成INF 
	int l;
	int r;
	int type;//当前循环复杂度为O(n^type) 
};
int name_count[maxc+5];//记录变量名是否出现 
stack<loop>st;//用栈存储循环,每有一个F就进栈，每有一个E就出栈 
int now_cplex;//当前过程的复杂度 
int cplex_in;//小明的时间复杂度 
int cplex_real=0;//实际上的时间复杂度 
bool is_err=false;//是否有语法错误 
int skip_deep=0;//记录跳过的循环在栈中的深度 
int parase_loop(loop &a) {//处理循环 
	a.l=string_to_int(a.ls);
	a.r=string_to_int(a.rs);
	if(name_count[a.name[0]-'a']) {
		return -1;//变量名重名 
	} else {
		name_count[a.name[0]-'a']=1;
		if(a.l<=a.r) {
			if(a.l!=INF&&a.r==INF) a.type=1;//如果左边界不是n，右边界是n，那么复杂度就要*O(n) 
			else a.type=0;//否则*O(1) 
			return a.type;
		} else {//跳过循环 
			a.type=0;
			return -2;
		}
	}
}

void insert_loop(loop x,int err_level){//将循环插入栈 
	st.push(x);
	if(err_level>=0){
		if((int)st.size()<=skip_deep||skip_deep==0){//如果没有被跳过 
			now_cplex+=err_level;//更新时间复杂度 
			cplex_real=max(cplex_real,now_cplex);
		} 
	}else if(err_level==-1){
		is_err=true;
	}else if(err_level==-2){
		if(!skip_deep) skip_deep=st.size();
		//更新跳过循环的深度 
		//如果一个被跳过的循环里还嵌套被跳过的循环，那么取外面的哪一个 
	} 
	
}
void del_loop(){
	if(st.empty()) is_err=true;//栈为空说明括号不匹配 
	else{
		if((int)st.size()<=skip_deep||skip_deep==0) now_cplex-=st.top().type;
		//注意只有没被跳过时now_cplex才会增加，所以减回去的时候也要判断 
		name_count[st.top().name[0]-'a']=0;
		st.pop();
		if((int)st.size()==skip_deep) skip_deep=0;//如果被跳过循环内部的循环已经执行完毕了，就取消 
		
	}
}
void ini(){
	memset(name_count,0,sizeof(name_count));
	while(!st.empty()) st.pop();
	now_cplex=0;
	cplex_in=cplex_real=0;
	is_err=false;
	skip_deep=0;
}
int main() {
	scanf("%d",&t);
	while(t--) {
		string cplex;
		string cmd_type;
		loop code;
		ini();
		scanf("%d",&n);
		cin>>cplex;
		cplex_in=parase_cplex(cplex);
		for(int i=1; i<=n; i++) {
			cin>>cmd_type;
			if(cmd_type[0]=='F') {
				cin>>code.name>>code.ls>>code.rs;
				if(is_err) continue;
				int id=parase_loop(code);
				insert_loop(code,id);
			} else if(cmd_type[0]=='E') {
				if(is_err) continue;
				del_loop();
			}
		}

		if(st.size()>0) is_err=true;//最后如果栈非空，也说明括号不匹配 
		if(is_err) printf("ERR\n");
		else if(cplex_in==cplex_real) printf("Yes\n");
		else printf("No\n");
	}
}

