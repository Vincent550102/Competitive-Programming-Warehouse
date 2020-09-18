#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin >> n >> m;
	vector<list<int> > data(n+1);
	while(m--){
		string q;
		cin >> q;
		if(q == "ADD"){
			int i,id;
			cin >> i >> id;
			data[i-1].push_back(id);
		}else if(q == "LEAVE"){
			int i;
			cin >> i;
			if(data[i-1].empty())cout << "queue " << i << " is empty!"<< endl; 
			else data[i-1].pop_front();
		}else{
			int i,j;
			cin >> i >> j;
			data[j-1].splice(data[j-1].end(),data[i-1]);
		}
	}
	for(int i = 0; i<n; i++){
		cout << "queue " << i+1 <<":";
		if(data[i].empty())cout << " empty";
		else for(auto x:data[i]){
			cout << " " << x;
		}
		cout << endl;
	}
} 
