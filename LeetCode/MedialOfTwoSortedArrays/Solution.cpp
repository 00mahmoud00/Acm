#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ShowPoint cout << setprecision(20) << setiosflags(ios::fixed) << setiosflags(ios::showpoint);

void FastIO(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}

void ReadWriteIO(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}

int inputMultiple(){
    int t;cin>>t;return t;
}
void appendVec(int p,int pRes,vector<int>& merged,vector<int> vec){
    while(p < vec.size()){
        merged[pRes++] = vec[p++];
    }
}
void solve(){
    vector<int> num1 = {1,2};
    vector<int> num2 = {3,4};
    vector<int> merged(num1.size() + num2.size());

    int p1 = 0, p2 = 0,p3 = 0;
    while(p1 < num1.size() && p2 < num2.size()){
        if(num1[p1] < num2[p2]){
            merged[p3++] = num1[p1++];
        }
        else{
            merged[p3++] = num2[p2++];
        }
    }
    appendVec(p1,p3,merged,num1);
    appendVec(p2,p3,merged,num2);
    int size = merged.size();
    if(size % 2 != 0)
        cout<<merged[(size + 1) / 2 - 1]<<endl;
    else
        cout<<(double)((double)merged[(size) / 2 - 1] + (double)merged[(size) / 2]) / 2.00 << endl;
}

int main(){
    // ReadWriteIO();
    // for (int i = 0; i < input(); i++)
        solve();
}