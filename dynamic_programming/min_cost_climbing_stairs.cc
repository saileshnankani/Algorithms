#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<int,int> memo;
int minClimb(vector<int>&cost, int begin){
    if(begin>=cost.size()){
        return 0;
    }
    if(memo.find(begin)!=memo.end()){
        return memo[begin];
    }
    int first = cost[begin] + minClimb(cost,begin+1);
    int second = cost[begin] + minClimb(cost,begin+2);
    memo[begin] = min(first,second);
    return memo[begin];
}
// top-down approach
int minCostClimbingStairs_down(vector<int>& cost) {
    return min(minClimb(cost,0),minClimb(cost,1));
}

int min(int a, int b){
    return a < b ? a : b;
}

// bottom-up approach,
int minCostClimbingStairs_up(vector<int>& cost) {
    int f1 = 0, f2 = 0;
    for(int i=0; i<cost.size(); i++){
        int f0 = cost[i] + min(f1,f2);
        f2 = f1;
        f1 = f0;
    }
    return min(f1,f2);
}

int main(){
    vector<int> test = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout<<minCostClimbingStairs_down(test)<<endl;
    cout<<minCostClimbingStairs_up(test)<<endl;
}