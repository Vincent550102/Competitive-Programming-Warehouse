#include<iostream>
using namespace std;
int main(){
	cout << "abcgd"-"asdgd" << endl;
	cout << (int)((&"abcgd"-&"asdgd")*sizeof("asdgd"));
}
