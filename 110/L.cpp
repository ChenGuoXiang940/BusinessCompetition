#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
vector<int>f;
bool check(int v){
    int m=v%6;
    if(m!=1&&m!=5)return false;
    int sq=(int)sqrt(v);
    for(int i=5;i<=sq;i+=6){
        if (v%i==0||v%(i+2)==0)return false;
    }
    return true;
}
int bs(int left,int right,int key){
    if(left>right){
        while(f[right]<key)right++;
        return right-1;
    }
    int mid=left+(right-left)/2;
    if(f[mid]>key)return bs(left,mid-1,key);
    else if(f[mid]<key)return bs(mid+1,right,key);
    else return mid;
}
int main(){
    f.push_back(2);
    f.push_back(3);
    for(int i = 5; i < 1000; i += 6)
    {
        if(check(i))f.push_back(i);
        if(check(i + 2))f.push_back(i + 2);
    }
    f.insert(f.begin(),1);
    int n,c;
    while(cin>>n>>c){
        int k=bs(0,169,n);
        string ans="";
        int b=c;
        if((k+1)%2!=0)b-=1;
        int a=k/2-b;
        if((k+1)%2==0){
            b=b*2;
            a+=1;
        }
        else b=b*2+1;
        b=b>=k+1?k+1:b;
        a=a<0?0:a;
        for(int i=0;i<b;i++){
            ans+=to_string(f[a+i])+" ";
        }
        cout<<n<<" "<<c<<": "<<ans<<endl;
    }
    system("Pause");
    return 0;
}