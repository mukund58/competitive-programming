class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        bool valid = true;
        for(int i = 0;i<s.length();i++){
            if(!st.empty()){
                char last = st.top();
                char cur = s[i];
                if(isPair(last,cur)){
                st.pop();
                continue;
                }
            }
            st.push(s[i]);
        }
        return st.empty();


        return valid;
    }

private:
    bool isPair(char last, char cur) {
        return (last == '(' && cur == ')') ||
               (last == '{' && cur == '}') ||
               (last == '[' && cur == ']');
    }
};    
