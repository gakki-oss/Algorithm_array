#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> Presum (nums.size()+2,0);
        int k=1;
        int sum=0;
        for(int i=0;i<=nums.size()-1;i++)
        {
            sum+=nums[i];
            Presum[k++]=sum;
        }
        for(int j=1;j<Presum.size()-1;j++)
        {
            if(Presum[j-1]==(Presum[Presum.size()-2]-Presum[j]))
            {
                return j-1;
            }
        }
        return -1;
    }
};

int main()
{
    vector<int> arr{1, 7, 3, 6, 5, 6};
    Solution ans;
    int index = ans.pivotIndex(arr);
    cout << "中心下标为:" << index << endl;
    return 0;

}