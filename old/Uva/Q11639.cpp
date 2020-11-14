#include<bits/stdc++.h>
using namespace std;
int main(){
	int case_num;
	cin >> case_num;
	int counter = 0;
	while(case_num--){
		counter++;
		int sol_one = 0, sol_two, sol_three;
		int x_o_one,y_o_one,x_t_one,y_t_one;
		int x_o_two,y_o_two,x_t_two,y_t_two;
		cin >> x_o_one >> y_o_one >> x_t_one >> y_t_one;
		cin >> x_o_two >> y_o_two >> x_t_two >> y_t_two;
		
		if(x_t_one > x_o_two && y_t_one > y_o_two && x_o_one < x_t_two && y_o_one < y_t_two){
			sol_one = (x_t_one - x_o_two) * (y_t_one - y_o_two);
		}
		sol_two = (x_t_one-x_o_one)*(y_t_one-y_o_one) + (x_t_two-x_o_two)*(y_t_two-y_o_two) - sol_one*2;
		int tmp = (x_t_one-x_o_one)*(y_t_one-y_o_one) + (x_t_two-x_o_two)*(y_t_two-y_o_two) - sol_one;
		sol_three = 10000-sol_two;
		cout << "Night "<<counter <<": " <<sol_one << " "<<sol_two << " "<<sol_three <<'\n';
	}
}
