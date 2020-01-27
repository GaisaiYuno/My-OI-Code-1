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

int string_to_int(string s) {//��ȡ�ַ���������֣����û�����ַ���INF 
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


int parase_cplex(string s) {//����ʱ�临�Ӷȱ��ʽ 
	int pos=s.find('^');
	if(pos==-1) return 0;//�����O(1),����0 
	else return string_to_int(s.substr(pos+1,s.length()-pos-2)); //���򷵻�ָ�� 
}

struct loop {
	string name;//������
	string ls;//��߽� 
	string rs;//�ұ߽� 
	//���ұ߽�ת�����ֺ�Ľ��,�����n,�ͱ�ǳ�INF 
	int l;
	int r;
	int type;//��ǰѭ�����Ӷ�ΪO(n^type) 
};
int name_count[maxc+5];//��¼�������Ƿ���� 
stack<loop>st;//��ջ�洢ѭ��,ÿ��һ��F�ͽ�ջ��ÿ��һ��E�ͳ�ջ 
int now_cplex;//��ǰ���̵ĸ��Ӷ� 
int cplex_in;//С����ʱ�临�Ӷ� 
int cplex_real=0;//ʵ���ϵ�ʱ�临�Ӷ� 
bool is_err=false;//�Ƿ����﷨���� 
int skip_deep=0;//��¼������ѭ����ջ�е���� 
int parase_loop(loop &a) {//����ѭ�� 
	a.l=string_to_int(a.ls);
	a.r=string_to_int(a.rs);
	if(name_count[a.name[0]-'a']) {
		return -1;//���������� 
	} else {
		name_count[a.name[0]-'a']=1;
		if(a.l<=a.r) {
			if(a.l!=INF&&a.r==INF) a.type=1;//�����߽粻��n���ұ߽���n����ô���ӶȾ�Ҫ*O(n) 
			else a.type=0;//����*O(1) 
			return a.type;
		} else {//����ѭ�� 
			a.type=0;
			return -2;
		}
	}
}

void insert_loop(loop x,int err_level){//��ѭ������ջ 
	st.push(x);
	if(err_level>=0){
		if((int)st.size()<=skip_deep||skip_deep==0){//���û�б����� 
			now_cplex+=err_level;//����ʱ�临�Ӷ� 
			cplex_real=max(cplex_real,now_cplex);
		} 
	}else if(err_level==-1){
		is_err=true;
	}else if(err_level==-2){
		if(!skip_deep) skip_deep=st.size();
		//��������ѭ������� 
		//���һ����������ѭ���ﻹǶ�ױ�������ѭ������ôȡ�������һ�� 
	} 
	
}
void del_loop(){
	if(st.empty()) is_err=true;//ջΪ��˵�����Ų�ƥ�� 
	else{
		if((int)st.size()<=skip_deep||skip_deep==0) now_cplex-=st.top().type;
		//ע��ֻ��û������ʱnow_cplex�Ż����ӣ����Լ���ȥ��ʱ��ҲҪ�ж� 
		name_count[st.top().name[0]-'a']=0;
		st.pop();
		if((int)st.size()==skip_deep) skip_deep=0;//���������ѭ���ڲ���ѭ���Ѿ�ִ������ˣ���ȡ�� 
		
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

		if(st.size()>0) is_err=true;//������ջ�ǿգ�Ҳ˵�����Ų�ƥ�� 
		if(is_err) printf("ERR\n");
		else if(cplex_in==cplex_real) printf("Yes\n");
		else printf("No\n");
	}
}

