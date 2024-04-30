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
map<int,int> VectorToMap(vector<int> vec){
    map<int,int> mp;
    for(int i=0;i<vec.size();i++)
    mp[vec[i]] = i + 1;
    return mp;
}
void solve(){
    vector<int> vec;
    int target = 9;
    vec.push_back(2);
    vec.push_back(7);
    vec.push_back(11);
    vec.push_back(15);

    map<int,int> mp = VectorToMap(vec);
    vector<int> ans;
    for(int i=0;i<vec.size();i++){
        if(mp[target - vec[i]] != 0)
        {
            ans.push_back(i);
            ans.push_back(mp[target - vec[i]] - 1);
            break;
        }
    }
    for(int i=0;i<ans.size();i++)cout<<ans[i]<<endl;
}

int main(){
    // ReadWriteIO();
    // for (int i = 0; i < input(); i++)
        solve();
}