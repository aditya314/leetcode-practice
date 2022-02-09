/*
time : O(2.k)
space: O(1)
int maxScore(vector<int> &cardPoints, int k) {
        int frontScore = 0;
        int rearScore = 0;
        int n = cardPoints.size();

        for (int i = 0; i < k; i++) {
            frontScore += cardPoints[i];
        }

        // take all k cards from the beginning
        int maxScore = frontScore;

        // take i from the beginning and k - i from the end
        for (int i = k - 1; i >= 0; i--) {
            rearScore += cardPoints[n - (k - i)];
            frontScore -= cardPoints[i];
            int currentScore = rearScore + frontScore;
            maxScore = max(maxScore, currentScore);
        }

        return maxScore;
    }
    */

class Solution {
    /*
    Another way that we could view the problem is that our objective is to choose cards from the beginning or end of the array in such a way that the sum of the remaining cards is minimized.
    */
private:
    int get_min_subarray_total_score(vector<int>& card_points, int size){
        int curr_subarray_score = 0, min_subarray_score = INT_MAX, start = 0;
        for(int end = 0; end < card_points.size(); end++){
            curr_subarray_score += card_points[end];
            if(end - start  + 1 == size){
                min_subarray_score = min(min_subarray_score, curr_subarray_score);
                curr_subarray_score -= card_points[start];
                start++;
            }
        }
        return (min_subarray_score == INT_MAX) ? 0 : min_subarray_score;
    }
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int total_score = 0;
        for(int point : cardPoints)     total_score += point;
        int min_subarray_size = cardPoints.size() - k;
        int min_subarray_score = get_min_subarray_total_score(cardPoints, min_subarray_size);
        return total_score - min_subarray_score;
    }
};