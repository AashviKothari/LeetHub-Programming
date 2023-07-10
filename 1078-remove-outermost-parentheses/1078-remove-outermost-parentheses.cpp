class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> store;
        string ans = "";
        for(auto c : s){
            if(c == '('){
                if(store.size() > 0){
                    ans += c;
                }
                store.push(c);
            }
            else if(c == ')'){
                if(store.size() > 1){
                    ans += c;
                }
                store.pop();
            }
        }
        return ans;
    }
};