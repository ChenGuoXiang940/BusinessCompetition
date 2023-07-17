#include<iostream>
#include<math.h>
#include<set>
using namespace std;
int main(){
    int n,val;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>val;
        set<int>set;
        set.insert(val);
        while(true)
        {
            int val2=0;
            while(val!=0)
            {
                val2+=pow(val%10,2);
                val/=10;
            }
            if(val2==1){
                cout<<"T"<<endl;
                break;
            }
            else if(set.count(val2)==1)
            {
                cout<<"F"<<endl;
                break;
            }      
            val=val2;
            set.insert(val2);
        }
    }
    system("Pause");
    return 0;
}