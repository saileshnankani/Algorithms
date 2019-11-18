#include <unordered_map>
#include <limits>
#include <vector>
#include <iostream>

using namespace std;

unordered_map<int,int> memo;

// top-down approach
int coinChange_down(vector<int>& coins, int amount, int num_coins = 0){
    if(amount==0) return 0;
    if(amount < 0) return -1;
    
    if(memo.find(amount)!=memo.end()){
        return memo[amount];
    }
    int min = numeric_limits<int>::max();  
    for(int i=0; i<coins.size(); i++){
        int coin_result = coinChange_down(coins, amount-coins[i], num_coins);
        if(coin_result<min && coin_result>=0){
            min = 1 + coin_result;
        }
    }
    memo[amount] = min == numeric_limits<int>::max() ? -1 : min;
    return memo[amount];
}

// bottom-up approach
int coinChange_up(vector<int>& coins, int amount){
    memo[0] = 0;
    for(int i=1; i<=amount; i++){
        int min = numeric_limits<int>::max();
        for(int j=0; j<coins.size(); j++){
            if(i-coins[j]>=0 && memo.find(i-coins[j])!=memo.end() && memo[i-coins[j]]>=0){
                min = min < memo[i-coins[j]] ? min : memo[i-coins[j]];
            }
        }
        min == numeric_limits<int>::max() ? memo[i] = -1 : memo[i] = min + 1;
    }
    return memo[amount];
}


int main(){
    vector<int> coin = {1,2,5};
    for(int i=0; i<11; i++){
        cout<<coinChange_down(coin,i)<<endl;
    }
    memo.clear();
    for(int i=0; i<11; i++){
        cout<<coinChange_up(coin,i)<<endl;
    }
    memo.clear();   
}