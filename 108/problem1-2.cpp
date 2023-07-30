#include<iostream>
#include<vector>
#include<sstream>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s,data;
    cin.ignore();
    for(int i=0;i<n;i++){
        getline(cin,s);
        stringstream ss(s);
        vector<int>record;
        vector<string>str;
        while (getline(ss,data,' '))
        {
            str.push_back(data);
        }
        int sum=0,len=str.size(),index=0;
        for(int i=0;i<len;i++){
            if(str[i]=="X"){
                if(index/2<9&&i+2<len){
                    if(str[i+1]==str[i+2]&&str[i+1]=="X")sum+=30;
                    else if(str[i+2]=="/")sum+=20;
                    else if (str[i+1]=="X")sum+=10+atoi(str[i+2].c_str());
                    else sum+=10+atoi(str[i+1].c_str())+atoi(str[i+2].c_str());
                }
                else sum+=10;
                index+=2;
            }
            else if (str[i]=="/")
            {
                sum-=atoi(str[i-1].c_str());
                if(index/2<9){
                    if(i+1<len&&str[i+1]=="X")sum+=20;
                    else sum+=10+atoi(str[i+1].c_str());
                }
                else sum+=10;
                index++;
            }
            else{
                sum+=atoi(str[i].c_str());
                index++;
            }
            cout<<sum<<endl;
        }
    }
    system("Pause");
    return 0;
}