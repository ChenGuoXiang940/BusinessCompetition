#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    string s,s1;
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++){
        getline(cin,s);
        stringstream ss(s);
        vector<int>v;
        while(getline(ss,s1,' '))
        {
            v.push_back(atoi(s1.c_str()));
        }
        sort(v.begin(),v.end());
        cout<<v[v.size()-1]<<" "<<v[v.size()-2]<<endl;
    }
    system("Pause");
/*
3
1 2 3 4 10 9 8 7
10 11 12 99 1 2 3
1 2 1 2 1 2

3
1 1 1 1 1 1 1
99 99 99
99 1
*/
    return 0;
}