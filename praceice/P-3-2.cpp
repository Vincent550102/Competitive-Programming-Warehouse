#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    while(cin >> str){
        stack<char> st;
        bool ok = true;
        for(char c:str){
            if(c=='(' || c=='[' || c=='{'){
                st.push(c);
            }else if(!st.empty()){
                switch(c){
                case ')':
                    if(st.top()!='(') ok = false;
                    else st.pop();
                    break;
                case ']':
                    if(st.top()!='[') ok = false;
                    else st.pop();
                    break;
                case '}':
                    if(st.top()!='{') ok = false;
                    else st.pop();
                    break;

                }
            }
        }
        cout << (ok&&st.empty()?"yes":"no") << endl;
    }
}
