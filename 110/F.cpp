#include<iostream>
#include<vector>
using namespace std;
int bs(int left,int right,int key,vector<int>v1){
    if(left>right)return right+1;
    int mid=left+(right-left)/2;
    if(v1[mid]==key){
        int len=v1.size();
        while(mid!=len&&key==v1[mid]){
            mid++;
        }
        return mid;
    }
    else if(v1[mid]>key)return bs(left,mid-1,key,v1);
    else return bs(mid+1,right,key,v1);
}
int main(){
    int n,data,total=0,target;
    vector<int>v1;
    cin>>n;
    cin>>data;
    v1.push_back(data);
    for(int i=1;i<n;i++){
        cin>>data;
        if(data<v1[0])target=0;
        else if(data>v1[i-1])target=i;
        else target=bs(0,i-1,data,v1);
        //cout<<"target:"<<target<<" "<<i-target<<endl;
        v1.insert(v1.begin()+target,data);
        total+=i-target;
        for(int j=0;j<v1.size();j++){
            cout<<v1[j]<<" ";
        }
        cout<<"\r\n";
    }
    cout<<total;
    system("Pause");
    return 0;
    //vector insert begin()+target 在第target位置的元素"前"加入值
    //二分插入排序法
    //8
    //1 20 54 1 50 100 2000 50
    //7
    //25 100 50 3 122 20 1001
}