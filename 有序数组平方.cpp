#include "algorithm"
#include "iostream"
#include "vector"
using namespace std;

vector<int> demo1(vector<int> &v)
{ // 暴力解法 先平方再快排
    int size = v.size();
    for (int i = 0; i < size; i++)
    {
        v[i] = v[i] * v[i];
    }
    sort(v.begin(), v.end());
    return v;
}

vector<int> demo2(vector<int>&v){  //双指针法
    vector<int> result(v.size(), 0);
    int size = v.size();
    int k = size - 1;
    for (int i = 0, j = size - 1; i <= j;){
        if(v[i]*v[i]>v[j]*v[j]){
            result[k] = v[i] * v[i];
            k--;
            i++;
        }else{
            result[k] = v[j] * v[j];
            k--;
            j--;
        }
    }
    return result;
}

vector<int> sortedSquares(vector<int> &A)
{
    int k = A.size() - 1;
    vector<int> result(A.size(), 0);
    for (int i = 0, j = A.size() - 1; i <= j;)
    { // 注意这里要i <= j，因为最后要处理两个元素
        if (A[i] * A[i] < A[j] * A[j])
        {
            result[k--] = A[j] * A[j];
            j--;
        }
        else
        {
            result[k--] = A[i] * A[i];
            i++;
        }
    }
    return result;
}

int main()
{
    vector<int> v;
    v.push_back(-4);
    v.push_back(-1);
    v.push_back(0);
    v.push_back(3);
    v.push_back(10);
    vector<int> result = demo2(v);
    int size = result.size();
    for (int i = 0; i < size; i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}