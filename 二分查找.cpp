#include"iostream"
#include"vector"
using namespace std;

int Search(vector<int>&v,int target){
    int left=0;
    int right=v.size()-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(v[mid]==target){
            return mid;
        }else if(v[mid]>target){
            right=mid-1;
        }else{
            left=mid+1;
        }
    }
    return -1;
}

int main(){
    vector<int>v={1,2,3,4,5,6,7,8,9,10};
    int target=5;
    int ret=Search(v,target);
    cout<<ret<<endl;
    return 0;
}