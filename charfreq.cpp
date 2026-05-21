#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char,int>freq;
        vector<int>ans;
        for(char x : s){
            freq[x]++;
        }
        for(auto & it : freq){
            ans.push_back(it.second);
        }
        for(int i = 1; i < ans.size(); i++){
            if(ans[i] != ans[i-1]){
                return false;
            }
        }
        return true;
    }
};
int main (){
    Solution s;
    string str = "abacbc";
    cout<<s.areOccurrencesEqual(str)<<endl;
    return 0;
}


