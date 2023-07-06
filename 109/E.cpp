#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    string s,s2;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        while (true)
        {
            s2=s;
            reverse(s2.begin(),s2.end());
            if(s==s2)break;
            s=to_string(stoi(s.c_str())+stoi(s2.c_str()));
        }
        cout<<s<<endl;
    }
    system("Pause");
    return 0;
}