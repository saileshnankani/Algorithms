#include <string>
#include <vector>
#include <iostream>

using namespace std;


int max(int a, int b){ 
    return a > b ? a : b;
}

// bottom-up approach
// Time Complexity: O(mn)
// Space Complexity: O(mn)
int longestCommonSubsequence(string &a, string &b){
    vector<vector<int>> word_matrix(a.size()+1, vector<int>(b.size()+1));
    for(int i=1; i<=a.size(); ++i){
        for(int j=1; j<b.size(); ++j){
            if(a[i-1]==b[i-1]){
                word_matrix[i][j] = word_matrix[i-1][j-1]+ 1;
            }
            else{
                word_matrix[i][j] = max(word_matrix[i-1][j],word_matrix[i][j-1]);
            }
        }
    }
}


// A more memory efficient version. Only stores 2 rows (current + previous) 
// of the longer row. Still bottom-up
// Time Complexity: O(mn)
// Space Complexity: O(min(m,n))
    int longestCommonSubsequence2(string text1, string text2) {
        if(text1.size() <  text2.size()){
            return longestCommonSubsequence2(text2, text1);
        }
        vector<vector<int>> m(2, vector<int>(text2.size()+1));
        for(int i=1; i<=text1.size(); ++i){
            for(int j=1; j<=text2.size(); ++j){
                if(text1[i-1]==text2[j-1]){
                    m[i%2][j] = 1+m[(i-1)%2][j-1];
                }
                else{
                    m[i%2][j] = max(m[(i-1)%2][j],m[i%2][j-1]);
                }
            }
        }
        return m[text1.size()%2][text2.size()];
    }


int main(){
    cout<<longestCommonSubsequence(string("abcde"), string("ace"))<<endl;
    cout<<longestCommonSubsequence2(string("abcde"), string("ace"))<<endl;
}












