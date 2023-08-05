#include<iostream>
#include<vector>
using namespace std;
typedef long long int ll;
int bs(ll key,int right,vector<ll>num){
    int record=-1;
    int left=1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(num[mid]<=key){
            record=mid;
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    return record;
}
int main() {
    vector<ll>num(100);
    num[0]=1;
    num[1]=1;
    for(int i=2;i<100;i++){
        num[i]=num[i-1]+num[i-2];
    }
    int n,a,a1;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        a1=a;
        int record=bs(a,99,num);
        char arr[record+1]={'0'};
        arr[record]='1';
        a-=num[record];
        while(a!=0){
            record=bs(a,record,num);
            arr[record]='1';
            a-=num[record];
        }
        string r="";
        for(const int item:arr){
            r=(item==0)?'0'+r:'1'+r;
        }
        r.erase(r.end()-1);
        cout<<a1<<"="<<r<<endl;
    }   
    cin.get();
    return 0;
}