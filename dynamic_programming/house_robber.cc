#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;

unordered_map<int,int> memo;

int maxHouse(vector<int>&nums, int begin){
    if(begin>=nums.size()){
        return 0;
    }
    if(memo.find(begin)!=memo.end()){
        return memo[begin];
    }
    int first = nums[begin]+maxHouse(nums,begin+2);
    int second = maxHouse(nums,begin+1);
    memo[begin] = max(first,second);
    return memo[begin];    
}

// top-down approach
int rob_down(vector<int>& nums) {
    if(nums.size()==2){
        return max(nums[0],nums[1]);
    }
    return maxHouse(nums,0);
}

// bottom-up approach
int rob_up(vector<int>& nums) {
    if(nums.size()==0) return 0;
    int prev2 = 0, prev1 = 0;
    for(int num: nums){
        int temp = prev1;
        prev1 = max(prev1,prev2+num);
        prev2 = temp;
    }
    return prev1;
}


int main(){
    vector<int> test = {2,7,9,3,1};
    cout<<rob_down(test)<<endl;
    memo.clear();
    vector<int> test2 = {1,2,3,1};
    cout<<rob_down(test2)<<endl;
    memo.clear();
    cout<<rob_up(test)<<endl;
    memo.clear();
    cout<<rob_up(test2)<<endl;
    memo.clear();

}