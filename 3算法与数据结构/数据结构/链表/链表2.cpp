//HDU 1387 
#include<iostream>
#include<cstring>
#include<map>
using namespace std;
map<int,int>group;
struct node {
	int num;
	int team;
	node *front;
	node *next;
};
node *head=new node();
node *tail=NULL;
int size=0;
bool empty() {
	if(size==0) return true;
	else return false;
}
void insert(int n,int t) {
	size++;
	node *tmp1=new node();
	node *tmp2=tail;
	while(tmp2!=NULL) {
		if(tmp2->team==t) {
			tmp1->next=tmp2->next;
			if(tmp2->next!=NULL)tmp2->next->front=tmp1;
			tmp1->front=tmp2;
			tmp1->num=n;
			tmp1->team=t;
			tmp2->next=tmp1;
			if(tmp1->next==NULL) tail=tmp1;
			return;
		} else tmp2=tmp2->front;
	}
	tmp1->num=n;
	tmp1->team=t;
	if(tail==NULL) {
		head->next=tmp1;
		tail=tmp1;
		tmp1->front=head;
		tmp1->next=NULL;
	} else { //Î²²åÈë
		tail->next=tmp1;
		tmp1->front=tail;
		tmp1->next=NULL;
		tail=tmp1;
	}
	return;
}
int del() {
	size--;
	node *tmp=head->next;
	head->next=tmp->next;
	int x=tmp->num;
	delete tmp;
	return x;
}
void clean(){
	node *tmp=head;
	node *p=tmp;
	while(tmp!=NULL){
		p=tmp;
		tmp=tmp->next;
		delete p;
	}
	head=new node();
	tail=NULL;
	size=0;
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
int t,n;
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
