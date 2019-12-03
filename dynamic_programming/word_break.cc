#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


unordered_map<string, bool> memo;

// top-down approach
bool wordBreakRecurse(string s){
    int found = false;
    if(memo.find(s)!=memo.end()){
        return memo[s];
    }
    else{
        for(int i=0; i<s.size(); i++){
            found = found || (wordBreakRecurse(s.substr(0,i)) && 
                                wordBreakRecurse(s.substr(i, s.size()-i)));
            if(found){
                break;
            }
        }
        memo[s] = found;
        return found;
    }        
}

bool wordBreak(string s, vector<string>& wordDict) {
    for(auto s : wordDict){
        memo[s] = true;
    }
    return wordBreakRecurse(s);
}


int main(){
    vector<string> leetcode = {string("leetcode"), string("code")};
    cout<<wordBreak("leetcode", leetcode)<<endl;
    vector<string> applepenapple = {string("apple"), string("pen")};
    cout<<wordBreak("applepenapple", applepenapple)<<endl;
    vector<string> catsandog = {string("cats"), string("dog"), string("sand"), string("and"), string("cat")};
    cout<<wordBreak("catsandog", catsandog)<<endl;
}