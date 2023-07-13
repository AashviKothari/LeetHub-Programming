class Solution {
public:
    string reverseVowels(string s) {
        vector<int>pos;
        stack<int>st;

        vector<char>v{'a','e','i','o','u'};

        for(int i =0; i<s.size();i++){
            for(auto x : v){
                if(x == s[i] || x-32 == s[i]){
                    pos.push_back(i);
                    st.push(s[i]);
                }
            }
        }

        for(auto h: pos){
            s[h] = st.top();
            st.pop();
        }

        return s;
    }
};