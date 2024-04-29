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

int input(){
    int t;
    cin>>t;
    return t;
}

void solve(){
    string s;
    cin>>s;
    cout<<s<<endl;
    map<char,int> chars;
    for(char ch = 'a'; ch<='z'; ch++){
        chars[ch] = 0;
    }

    int l = 0,r = 1;
    chars[s[l]]++;
    int count = 1,ans = 0;
    while(l < s.size() && r < s.size()){
        cout<<s[r]<<"  "<<r<<endl;
        if(chars[s[r]] < 1){
            count ++;
            chars[s[r]]++;
            r++;
        }
        else{
            chars[s[l]]--;
            l++;
            ans = max(count,ans);
            count --;
        }
    }
    cout<<max(ans,count)<<endl;
}
int main(){
    ReadWriteIO();
    // for (int i = 0; i < input(); i++)
        solve();
}