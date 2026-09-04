class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        stack<vector<int>> st;
        st.push(newInterval);
        for(int i=0;i<intervals.size();i++){
            if(st.top()[0]>intervals[i][0]){
                if(st.top()[0]>intervals[i][1]){
                    int start = st.top()[0];
                    int end = st.top()[1];
                    st.pop();
                    st.push(intervals[i]);
                    st.push({start,end});
                }else{
                    int start = intervals[i][0];
                    int end = max(st.top()[1],intervals[i][1]);
                    st.pop();
                    st.push({start,end});
                }
            }else if(st.top()[0]<intervals[i][0]){
                if(st.top()[1]<intervals[i][0]){
                    st.push(intervals[i]);
                }else{
                    int start = st.top()[0];
                    int end = max(st.top()[1],intervals[i][1]);
                    st.pop();
                    st.push({start,end});
                }
            }else{
                int start = st.top()[0];
                int end = max(st.top()[1],intervals[i][1]);
                st.pop();
                st.push({start,end});
            }
        }
        vector<vector<int>> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};