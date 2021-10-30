#include <bits/stdc++.h>
using namespace std;

int bSearch(vector<int> &vec, int x)
{
    int start = 0;
    int end = vec.size() - 1;
    int mid;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (start == mid)
        {
            if (vec[start] > x)
            {
                return start;
            }
            else if (vec[end] > x)
            {
                return end;
            }
            else
            {
                return -1;
            }
        }
        else
        {
            if (vec[mid] > x)
            {
                end = mid;
            }
            else
            {
                start = mid;
            }
        }
    }
    return -1;
}

int lengthOfLIS(vector<int> &nums)
{
    vector<int> vec;
    vec.push_back(nums[0]);
    for (int i = 1; i < nums.size(); i++)
    {
        int j = bSearch(vec, nums[i]);
        if (j == -1)
        {
            if (vec.back() != nums[i])
            {
                vec.push_back(nums[i]);
            }
        }
        else
        {
            if (j >= 1 && vec[j - 1] == nums[i])
            {
                continue;
            }
            vec[j] = nums[i];
        }
    }
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
    return vec.size();
}

int main(){
    int n;cin>>n;
    vector<int>v(n,0);
    for(int i=0;i<n;i++)cin>>v[i];
    lengthOfLIS(v);
}