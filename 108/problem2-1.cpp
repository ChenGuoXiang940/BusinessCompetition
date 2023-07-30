#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n,A,B,N;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>A>>B>>N;
        string N_str=to_string(N);
        int count=0;
        for(int i=A;i<=B;i++) {
            string num_str=to_string(i);
            if(num_str.find(N_str)!=string::npos) {
                count++;
            }
        }
        cout<<count<<endl;
    }
    system("Pause");
    return 0;
}