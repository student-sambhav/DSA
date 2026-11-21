class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxarea=0;
        int n=heights.size();
        vector<int> nse(n),pse(n);
        int element=0;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                element=st.top();
                st.pop();
                nse[i]=i;
                pse[i]=st.empty()?-1:st.top();
                maxarea=max(maxarea,heights[element]*(nse[i]-pse[i]-1));

            }
            st.push(i);
        }
        for(int i=0;i<n;i++){
        while(!st.empty()){
            nse[i]=n;
            element=st.top();
            st.pop();
            pse[i]=st.empty()?-1:st.top();
            maxarea=max(maxarea,heights[element]*(nse[i]-pse[i]-1));
        }
        }
        
        return maxarea;
    }
};