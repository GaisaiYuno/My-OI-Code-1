//HDU 1387 
#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<map>
using namespace std;
map<int,int>group;
struct node {
	int num;
	int team;
	node *next;
};
node *head;
node *tail;
node* vis_team[1005];
int size=0;
int t,n;
bool empty() {
	if(size==0) return true;
	else return false;
}
void insert(int n,int t) {
	size++;
	node *tmp=new node();
	tmp->num=n;
	tmp->team=t;
	if(vis_team[group[n]]==NULL) {
		vis_team[group[n]]=tmp;
		tmp->next=NULL;  
		tail->next=tmp;
		tail=tmp;
	} else { //Î²²åÈë
		node *tmp2=vis_team[group[n]];
		tmp->next=tmp2->next;
		tmp2->next=tmp;
		vis_team[group[n]]=tmp;
		if(tail==tmp2) tail=tmp;
	}
	return;
}
int del() {
	int x;
	size--;
	if(head->next!=NULL)x=head->next->num;
	if(head->next==vis_team[group[x]]) vis_team[group[x]]=NULL;
	head=head->next;
	return x;
}
void clean(){
	head=tail=new node();
	head->next=NULL;
	group.clear();
	size=0;
	for(int i=1;i<=t;i++) vis_team[i]=NULL;
}
void output() {//µ÷ÊÔÓÃ 
	node *tmp=head->next;
	while(tmp!=NULL) {
		printf("%d %d\n",tmp->num,tmp->team);
		tmp=tmp->next;
	}
	cout<<endl;
	return;
}
inline int fread() {
	int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}
string cmd;
int main() {
	//freopen("data.txt","r",stdin);
	/*int t,a,b;
	while(cin>>t){
		if(t==1){
			cin>>a>>b;
			insert(a,b);
		}
		if(t==2) del();
		if(t==3) output();
	} */
	int x,y,cnt=0;
	while(cin>>t&&t!=0) {
		cnt++;
		clean();
		for(int k=1; k<=t; k++) {
			n=fread();
			for(int i=1; i<=n; i++) {
				x=fread();
				group[x]=k;
			}
		}
		printf("Scenario #%d\n",cnt);
		while(cin>>cmd&&cmd!="STOP") {
			if(cmd=="ENQUEUE") {
				y=fread();
				insert(y,group[y]);
			} else if(cmd=="DEQUEUE") {
				if(!empty()) cout<<del()<<endl;
			}
		}
		cout<<endl;
	}
}
