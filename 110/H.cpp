#include<iostream>
#define fo(b) for(int i=0;i<b;i++)
typedef long long ll;
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    fo(n){
        ll total=0;
        fo(10){
            ll b1,b2;
            scanf("%llx %llx",&b1,&b2);
            total+=b1*0x100+b2;
            printf("%02llx %02llx ",b1,b2);
        }
        total=total%0x10000+total/0x10000;
        printf("%04llx\n",total^0xffff);
    }
    system("Pause");
    //5
    //45 00 00 30 cc 61 40 00 40 06 00 00 0a 05 04 6b 0a 08 09 ed
    //45 00 00 73 00 00 40 00 40 11 b8 61 c0 a8 00 01 c0 a8 00 c7
    //45 00 00 47 73 88 40 00 40 06 00 00 83 9f 0e 85 83 9f 0e a1
    //45 00 00 47 73 88 40 00 40 06 a2 c4 83 9f 0e 85 83 9f 0e a1
    //45 00 05 14 42 a2 21 40 80 01 00 00 c0 a8 00 03 c0 a8 00 01
    return 0;
}