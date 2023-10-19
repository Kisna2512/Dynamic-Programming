int solveUsingBinarySearch(vector<int> &nums)
    {
        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] > temp.back()){
                temp.push_back(nums[i]);
            }else
            {
                int idx=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[idx]=nums[i];
            }
        }
        return temp.size();
    }
   