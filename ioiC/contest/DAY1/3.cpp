#include<iostream>
#include<algorithm>
#include<random>

using namespace std;

int a[1005];

int main(){
    int n; cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    mt19937 gen(880301);
    uniform_int_distribution<int> dis(0,n-1);
    int i=0,j=0,c=0;
    while(!is_sorted(a,a+n)){
        c++;
        if((i=dis(gen)),(j=dis(gen)),a[i]>=a[j])
            swap(a[i],a[j]);
    }
    for(int i=0;i<n;i++) cout<<a[i]<<" \n"[i+1==n];
    return 0;
}
