#include <iostream>

using namespace std;

int alp,dig,spec,cap;

bool f(string s){
    if (s.length()<8)
        return false;
    for(int i=0;i<s.length()-1;i++)
        if (s[i]==s[i-1])
            return false;
    for(auto x:s)
        switch (x){
            case 'a'...'z': alp++;break;
            case 'A'...'Z': cap++;break;
            case '0'...'9': dig++;break;
            default: spec++;
        }
    if (!alp || !cap || !dig || !spec)
        return false;
    return true;
}

int main(){
    cin.tie(0)->ios::sync_with_stdio(0);
    string s;
    cin>>s;
    if (f(s))
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}