#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution{
public:
    vector<int> twoSum(vector<int>&nums, int target){

        unordered_map<int, int> hash;
        vector<int> res;
        for(int i = 0; i < nums.size(); ++i){
            int another = target - nums[i];
            if(hash.find(another) != hash.end()){
                res.push_back(hash[another]);
                res.push_back(i);
                return res;
            }
            hash[nums[i]] = i;
        }
        return {-1};
    }
};
int main(){

    vector<int>nums = {2,7,11,15};
    int target = 13;
    vector<int> res;

    Solution solution;
    res = solution.twoSum(nums, target);

    for(auto it = res.begin(); it != res.end(); it++)
        cout << *it << endl;

}