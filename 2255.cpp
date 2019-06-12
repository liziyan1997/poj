#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;

struct node{
    node* left;
    node* right;
    char c;
};
typedef struct node Node;

Node* build(char* pre,char* in){
    int pre_len = strlen(pre);
    if(pre_len<=0){
        return NULL;
    }
    Node *root = new Node();
    memset(root,0,sizeof(Node));

    root->c = *pre;

    int pos = strchr(in,*pre)-in;   //找到头节点出现的位置
    char *leftin = new char[26];
    char *leftpre = new char[26];
    memset(leftin,'\0',26);
    memset(leftpre,'\0',26);
    strncpy(leftin,in,pos);
    strncpy(leftpre,pre+1,pos);

    char *rightin = new char[26];
    char *rightpre = new char[26];
    memset(rightin,'\0',26);
    memset(rightpre,'\0',26);
    strcpy(rightin,in+(pos+1));
    strcpy(rightpre,pre+(pos+1));

    // cout << "leftpre " << leftpre << endl;
    // cout << "leftin " << leftin << endl; 

    Node * left = build(leftpre,leftin);
    Node * right = build(rightpre,rightin);

    root->left = left;
    root->right = right;

    delete[] leftin;
    delete[] leftpre;
    delete[] rightin;
    delete[] rightpre;

    return root;
}

void printpostorder(Node* root){
    if(root==NULL){
        return;
    }
    printpostorder(root->left);
    printpostorder(root->right);
    printf("%c",root->c);
}



int main(){
    char *pre=new char[26],*in = new char[26];
    while(cin >> pre >> in){
        Node* root = build(pre,in);
        printpostorder(root);
        printf("\n");
    }
    return 0;
}

