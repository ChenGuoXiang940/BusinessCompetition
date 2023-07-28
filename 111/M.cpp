#include<iostream>
#include<math.h>
#include<bitset>
using namespace std;
int N;
string toBinary(int n)
{
    return bitset<16>(n).to_string().substr(16-N);
}
int main() {
    int n;
    cin>>n;
    N=n;
    int len=pow(2,n);
    for(int i=0;i<len;i++){
        cout<<toBinary(i^(i>>1))<<endl;
    }
    cin.get();
    return 0;
}