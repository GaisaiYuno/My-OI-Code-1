#include<iostream>
using namespace std;
struct node{
    int data;
    node *next; 
};
node *head=NULL;
void insert(int x){//����x 
    node *tmp=new node();
    tmp->data=x;
    tmp->next=head;//��ͷ���� 
    head=tmp; 
    return;
} 
int is_found(int x){//��x,�ҵ�����1�����򷵻�0 
    node *tmp=head;
    while(tmp!=NULL){
        if(tmp->data==x) return 1;
        tmp=tmp->next;
    }
    return 0;
} 
void del(int x){//ɾ��x 
    node *a = head;
    node *pre = head;
    while(a != NULL) {
        if(a->data==x&&pre!=NULL) {
            if(a == pre)head=a->next;
            pre->next=a->next;
        }
        pre=a;
        a=a->next;
    }
    return;
}
void output(){//����������� 
    node *tmp=head;
    if(tmp==NULL){
       cout<<"empty"<<endl; 
       return;
    } 
    while(tmp!=NULL){
        cout<<tmp->data<<' ';
        tmp=tmp->next;
    }
    cout<<endl;
} 
int main(){
    //freopen("data8.in","r",stdin);
    //freopen("data8.out","w",stdout);
    int x,y;
    while(cin>>x&&x!=0){
        if(x==1){
          cin>>y;
          insert(y);
        }
        else if(x==2){
        	cin>>y;
        	if(is_found(y))cout<<"true"<<endl;
        	else cout<<"false"<<endl;
        } 
        else if(x==3){
            cin>>y;
            if(is_found(y)==1) del(y);
            else cout<<"error"<<endl;
        }
        else if(x==4){
            output();
        }  
    }
    return 0;
}
