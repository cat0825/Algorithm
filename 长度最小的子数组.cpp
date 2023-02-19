#include "iostream"
#include "vector"
using namespace std;

int demo1(vector<int> &v, int target)
{ // 暴力解法
    int result = INT32_MAX;
    int sublength = 0;
    int sum = 0;
    int size = v.size();
    for (int i = 0; i < size; i++)
    {
        sum = 0;   //???
        for (int j = i; j < size; j++)
        {
            sum += v[j];
            if (sum >= target)
            {
                sublength = j - i + 1;
                result = result < sublength ? result : sublength;
                break;
            }
        }
    }
    return result == INT32_MAX ? 0 : result;
}

int minSubArrayLen(int s, vector<int> &nums)
{
    int result = INT32_MAX; // 最终的结果
    int sum = 0;            // 子序列的数值之和
    int subLength = 0;      // 子序列的长度
    int size = nums.size();
    for (int i = 0; i < size; i++)
    { // 设置子序列起点为i
        sum = 0;
        for (int j = i; j < size; j++)
        { // 设置子序列终止位置为j
            sum += nums[j];
            if (sum >= s)
            {                          // 一旦发现子序列和超过了s，更新result
                subLength = j - i + 1; // 取子序列的长度
                result = result < subLength ? result : subLength;
                break; // 因为我们是找符合条件最短的子序列，所以一旦符合条件就break
            }
        }
    }
    // 如果result没有被赋值的话，就返回0，说明没有符合条件的子序列
    return result == INT32_MAX ? 0 : result;
}


int demo2(vector<int>&v,int target){
    int sum = 0;
    int result = INT32_MAX;
    int subLength = 0;
    int size = v.size();
    int i = 0;
    for (int j = 0; j < size;j++){
        sum += v[j];
        while(sum>=target){
            subLength = j - i + 1;
            result=result<subLength?result:subLength;
            sum -= v[i];
            i++;
        }
    }
    return result == INT32_MAX ? 0 : result;
}

int main()
{
    vector<int> v = {2, 3, 1, 2, 4, 3};
    int target = 7;
    //int result = minSubArrayLen(target, v);
    int result = demo2(v, target);
    cout << result << endl;
    return 0;
}