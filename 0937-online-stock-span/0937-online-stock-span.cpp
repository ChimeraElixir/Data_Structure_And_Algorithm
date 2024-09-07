class StockSpanner {
public:
    int idx = -1;
    stack <pair<int,int>> st;
    StockSpanner() {
        idx=-1;

    }
    
    int next(int price) {
        idx++;
        while(!st.empty() && price >= st.top().first ){
            st.pop();
        }
        int ans = idx - (st.empty()?-1:st.top().second);
        
        st.push({price , idx});

        return ans;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */