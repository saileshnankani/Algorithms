// Code to compute the nth fibonacci number using dynamic programming. 

#include <iostream>
#include <unordered_map>

using namespace std;

std::unordered_map<long long, long long> memo;

// Top-down implementation (recursive)
// Running Time: Theta(n)
long long fib_down(long long n){
    if(memo.find(n)!=memo.end()){
        return memo[n];
    }
    else{
        memo.insert({n-1,fib_down(n-1)});
        memo.insert({n-2,fib_down(n-2)});
        return memo.at(n-1)+ memo.at(n-2);
    }   
}   

// Bottom up implementation 
// Running Time: Theta(n)
long long fib_up(long long n){
    long long f = 0;
    for(long long i=1; i<=n; i++){
        if(i<=2){
            f = 1;
        }
        else{
            f = memo[i-1] + memo[i-2];
        }
        memo[i] = f; 
    }
    return memo[n];
}

int main(){
    memo[0] = 0;
    memo[1] = 1;
    cout<<fib_down(50)<<endl;
    cout<<fib_up(50)<<endl;    
}