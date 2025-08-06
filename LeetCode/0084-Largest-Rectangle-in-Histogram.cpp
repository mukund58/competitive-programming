class Solution {
public:
    int largestRectangleArea(vector<int>& histo) {
        stack<int> st;
        int maxA = 0;
        int n = histo.size();

        for (int i = 0; i <= n; i++) {
            int currHeight = (i == n) ? 0 : histo[i];
            
            while (!st.empty() && histo[st.top()] >= currHeight) {
                int height = histo[st.top()];
                st.pop();
                
                int width;
                if (st.empty()) width = i;
                else width = i - st.top() - 1;
                
                maxA = max(maxA, width * height);
            }

            st.push(i);
        }

        return maxA;
    }
};

