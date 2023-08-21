class Solution {
public:
    int minLength(string s) {
        stack<char>st;
        for( auto it : s){ 
            if(!st.empty() and ((it == 'B' and st.top()=='A') || (it == 'D' and st.top() == 'C'))){
                st.pop();
            }
            else{
                st.push(it);
            }
        }
        return st.size();
    }
};