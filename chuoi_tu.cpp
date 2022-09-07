// https://oj.vnoi.info/problem/chain2
#include <iostream>

using namespace std;

struct node{
    int val;
    node* a[26];
};

typedef struct node* trie;

trie root=new node;

trie add(){
    trie p=new node;
    p->val=0;
    for(int i=0;i<26;i++)
        p->a[i]=NULL;
    return p;
}

int res=0;;

void ins(string s){
    int tmp=0;
    trie p=root;
    for(char x:s){
        int id=x-'a';
        if (p->a[id]==NULL)
            p->a[id]=add();
        tmp=max(tmp,p->val);
        p=p->a[id];
    }
    p->val=tmp+1;
    res=max(res,p->val);
}

int main(){
    root=add();
    int n;
    cin>>n; string s;
    while(n--){
        cin>>s;
        ins(s);
    }
    cout<<res;
}