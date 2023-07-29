#include<iostream>
#include<vector>
using namespace std;
vector<int>v;
int bs(int left,int right,int key){
    if(left>right)return right+1;
    int mid=left+(right-left)/2;
    if(v[mid]==key){
        int len=v.size();
        while(mid!=len&&key==v[mid]){
            mid++;
        }
        return mid;
    }
    else if(v[mid]>key)return bs(left,mid-1,key);
    else return bs(mid+1,right,key);
}
int main(){
    int n,data,total=0,target;
    cin>>n;
    cin>>data;
    v.push_back(data);
    for(int i=1;i<n;i++){
        cin>>data;
        if(data<v[0])target=0;
        else if(data>v[i-1])target=i;
        else target=bs(0,i-1,data);
        v.insert(v.begin()+target,data);
        total+=i-target;
    }
    cout<<total<<endl;
    system("Pause");
    return 0;
    //vector insert begin()+target 在第target位置的元素"前"加入值
    //二分插入排序法
/*
8
1 20 54 1 50 100 2000 50
7
25 100 50 3 122 20 1001
}
*/
}