class Solution {
    public:
        int largestRectangleArea(vector<int> &height) { 
            int max_area = 0;
            stack<int> index;
            for(int i = 0; i < height.size(); i++){
                while(!index.empty() && height[index.top()] >= height[i]){
                    //height[i] is next smaller element
                    int base_height = height[index.top()];
                    index.pop();
                    //index.top() is previous smaller element since stack is montonic increasing 
                    int pse_idx = index.empty() ? -1 : index.top();
                    int width = (i - pse_idx - 1);
                    max_area = max(max_area, base_height * width);
                }
                index.push(i);
            }
            while(!index.empty()){
                int base_height = height[index.top()];
                index.pop();
                int pse_idx = index.empty() ? -1 : index.top();
                int width = (height.size() - pse_idx - 1);
                max_area = max(max_area, base_height * width);
            }
                
            return max_area;
        }
    };
