class Solution {
    //O(nlogn) time
    //space depends on sorting O(logn)/ O(n)
    // int n = arr.size(), min_diff = INT_MAX;
    //     sort(arr.begin(), arr.end());
    //     vector<vector<int>> answer;
    //     for(int i = 0; i < n - 1; i++){
    //         int curr_diff = arr[i + 1] - arr[i];
    //         if(curr_diff < min_diff){
    //             answer.clear();
    //             answer.push_back({arr[i], arr[i + 1]});
    //             min_diff = arr[i + 1] - arr[i];
    //         }
    //         else if(curr_diff == min_diff){
    //             answer.push_back({arr[i], arr[i + 1]});
    //         }
    //     }
    //     return answer;
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
  // where n is the length of arr. The current approach will take O(m+n) time,
  //       and in the worst case, m equals 2*10^6 where m is the difference between the largest and smallest element in arr.
        // Thus, for the given constraints, the previous and the current approaches have similar worst-case run times, so both approaches are acceptable. However, if the constraints were different and mm was much larger than n \log nnlogn, then the previous approach would be the better option and vice versa.
        int min_ele= *min_element(arr.begin(), arr.end());
        int max_ele= *max_element(arr.begin(), arr.end());
        int offset = -min_ele;
        vector<bool> number_line(max_ele + offset + 1, false);
        for(int num : arr)
            number_line[num + offset] = true;
        
        int n = arr.size(), min_diff = max_ele - min_ele, prev = 0;
        //number_line[prev] is true, why?
        //because mimumum_elemtnt + offset = 0
        vector<vector<int>> answer;
        for(int i = 1; i <= max_ele + offset; i++){
            if(number_line[i]){
                if(i - prev < min_diff){
                    answer.clear();
                    answer.push_back({prev - offset, i - offset});
                    min_diff = i - prev;
                }   
                else if(i - prev == min_diff){
                    answer.push_back({prev - offset, i - offset});
                }
                prev = i;
            }
        }
        return answer;
    }
};