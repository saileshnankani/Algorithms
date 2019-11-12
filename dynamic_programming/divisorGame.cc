#include <iostream>
#include <unordered_map>

using namespace std;

// top-down approach
unordered_map<int,bool> memo;
bool divisorGame_up(int N) {
    memo[1] = false;
    if(memo.find(N)!=memo.end()){
        return memo[N];
    }
    for(int i=1; i<N; i++){
        if(N%i==0 && !divisorGame_up(N-i)){
            memo[N] = true;
            return true;
        }
    }
    memo[N] = false;
    return false;
}

void initialize(int N){
    for(int i=0; i<N; i++){
        memo[i] = false;
    }    
}
    
// bottom-up approach
bool divisorGame_down(int N) {
    initialize(N);
    for(int i=1; i<=N; i++){
        for(int j=1; j<i; j++){
            if(i%j==0){
                memo[i] = !memo[i-j] || memo[i];
            }
        }
    }
    return memo[N];
}



int main(){
    for(int i=1; i<11; i++){
        cout<<divisorGame_up(i)<<endl;
    }
    memo.clear();
    for(int i=1; i<11; i++){
        cout<<divisorGame_down(i)<<endl;
    }
}