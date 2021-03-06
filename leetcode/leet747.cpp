#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxNum=0,index=0;
        maxNum=*(max_element(nums.begin(),nums.end()));
        for(int i=0;i<nums.size();i++){
            int tmp=nums[i]*2;
            if(nums[i]==maxNum){
                index=i;
                continue;
            }
            if(maxNum >= tmp){
                continue;
            }
            else{
                return -1;
            }
        }
        return index;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        int ret = Solution().dominantIndex(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
