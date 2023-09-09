#include<iostream>
#include<vector>
using namespace std;
int main() {
    int n;
    cin>>n;
    int nums[n];
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<int>seq;
    seq.push_back(nums[0]);
    for(int i=1;i<n;i++){
        if(nums[i]>seq[seq.size()-1]){
            seq.push_back(nums[i]);
        }
        else{
            int left=0,right=seq.size()-1;
            while (left<right)
            {
                int mid=left+(right-left)/2;
                if(seq[i]<nums[mid])left=mid+1;
                else right=mid;
            }
            seq[left]=nums[i];
        }
    }
    cout<<seq.size()<<endl;
    cin.get();
    return 0;
}