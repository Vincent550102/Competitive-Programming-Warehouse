#include <iostream>
#include <vector>
#include "math.h"
#define SWAP(a,b) a=a+b,b=a-b,a=a-b
using namespace  std;
struct node{
    int data;
    int parent_dir;
    node* left;
    node* right;
    node* parent;
};
void findbiggest(node* thenode,int* num){
    if(thenode->right== nullptr){
        (*num)=thenode->data;
    }
    else{
        findbiggest(thenode->right,num);
    }
}
void insert(int num,node** thenode){
    if((*thenode)== nullptr) {
        (*thenode)=new node;
        (*thenode)->data=num;
        (*thenode)->parent= nullptr;
        (*thenode)->left= nullptr;
        (*thenode)->right= nullptr;
        (*thenode)->parent_dir=0;
    }
    else{
        if(num>(*thenode)->data){
            if((*thenode)->right== nullptr){
                (*thenode)->right=new node;
                (*thenode)->right->data=num;
                (*thenode)->right->left= nullptr;
                (*thenode)->right->right= nullptr;
                (*thenode)->right->parent=(*thenode);
                (*thenode)->right->parent_dir=1;
            }
            else{
                insert(num,&((*thenode)->right));
            }
        }
        else{
            if((*thenode)->left== nullptr){
                (*thenode)->left=new node;
                (*thenode)->left->data=num;
                (*thenode)->left->left= nullptr;
                (*thenode)->left->right= nullptr;
                (*thenode)->left->parent=(*thenode);
                (*thenode)->left->parent_dir=2;
            }
            else{
                insert(num,&((*thenode)->left));
            }
        }
    }
}
void deletee(int num,node* thenode){
    if(num>thenode->data){
        deletee (num,thenode->right);
    }
    else if(num<thenode->data){
        deletee (num,thenode->left);
    }
    else{
        if(thenode->left== nullptr&&thenode->right== nullptr){
            if(thenode->parent_dir==1){
                thenode->parent->right= nullptr;
                delete(thenode);
            }
            else{
                thenode->parent->left= nullptr;
                delete(thenode);
            }
        }
        else if(thenode->left!= nullptr&&thenode->right== nullptr){
            if(thenode->parent_dir==1){
                thenode->parent->right=thenode->left;
                thenode->left->parent=thenode->parent;
                thenode->left->parent_dir=1;
                delete((thenode));
            }
            else if(thenode->parent_dir==2){
                (thenode)->parent->left=(thenode)->left;
                (thenode)->left->parent=(thenode)->parent;
                (thenode)->left->parent_dir=2;
                delete((thenode));
            }
        }
        else if((thenode)->left== nullptr&&(thenode)->right!= nullptr){
            if((thenode)->parent_dir==1){
                (thenode)->right->parent=(thenode)->parent;
                (thenode)->right->parent_dir=1;
                (thenode)->parent->right=(thenode)->right;
                delete(thenode);
            }
            else{
                (thenode)->right->parent=(thenode)->parent;
                (thenode)->right->parent_dir=2;
                (thenode)->parent->left=(thenode)->right;
                delete(thenode);
            }
        }
        else{
            int tmp=-1;
            findbiggest ((thenode)->left,&tmp);
            (thenode)->data=tmp;
            deletee(tmp,thenode->left);
        }
    }
}

void query(int num,node* thenode,int* distance,int* ans1,int* ans2){
    if(abs(num-thenode->data)<(*distance)||*distance==-1){
        (*distance)=abs(num-thenode->data);
        *ans1=thenode->data;
        *ans2=-2000000000;
    }
    else if(abs(num-thenode->data)==(*distance)){
        *ans2=thenode->data;
    }
    if(num>thenode->data&&thenode->right!= nullptr){
        query (num,thenode->right,distance,ans1,ans2);
    }
    else if(num<thenode->data&&thenode->left!= nullptr){
        query (num,thenode->left,distance,ans1,ans2);
    }
}
int main() {
    int num,i,storenum;
    string op;
    cin >> num;
    node* thenode= nullptr;
    for(i=0;i<num;i++){
        cin >> op;
        cin >> storenum;
        if(op=="insert"){
            insert(storenum,&thenode);
        }
        else if(op=="query"){
            int distance=-1;
            int ans1=-2000000000,ans2=-2000000000;
            query(storenum,thenode,&distance,&ans1,&ans2);
            if(ans1>ans2&&ans2!=-2000000000){
                SWAP(ans1,ans2);
            }
            if(ans2!=-2000000000){cout << ans1 << " " << ans2;}
            else{cout << ans1;}
            cout << endl;
        }
        else if(op=="delete"){
            if(thenode->parent== nullptr&&thenode->left== nullptr&&thenode->right== nullptr){
                delete(thenode);
                thenode= nullptr;
            }
            else if(thenode->left!= nullptr&&thenode->right== nullptr&&thenode->parent== nullptr&&storenum==thenode->data){
                thenode=thenode->left;
                delete(thenode->parent);
                thenode->parent= nullptr;
                thenode->parent_dir=0;
            }
            else if((thenode)->left== nullptr&&(thenode)->right!= nullptr&&(thenode)->parent== nullptr&&storenum==thenode->data){
                (thenode)=(thenode)->right;
                delete((thenode)->parent);
                (thenode)->parent= nullptr;
                (thenode)->parent_dir=0;
            }
            else{
                deletee(storenum,thenode);
            }
        }
    }
    return 0;
}
