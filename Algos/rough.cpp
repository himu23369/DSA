class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int i = 0;
        int len = nums.size();
        while (i != len - 1)
        {
            if (nums[i] == 0 && i != len - 1)
            {
                return false;
            }
            else
            {
                if (nums[i] < len - i)
                {
                    i += nums[i];
                }
                else
                {
                    i += len - i;
                }
            }
        }
    }

    return true;
};