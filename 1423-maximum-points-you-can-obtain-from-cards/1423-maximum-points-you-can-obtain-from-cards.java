class Solution {
    // We have to take exactly k elements, so in the end cardPoints.length - k elements remain. 
    // We minimize the sum of the remaining elements to maximize the sum of the elements we take.
    // We find the smallest sum subarray of length cardPoints.length - k.
    public int maxScore(int[] cardPoints, int k) {
        int totalSum = 0, minWindowSum = 0, currWindowSum = 0, windowSize = cardPoints.length - k;
        
        for (int i = 0; i < windowSize; ++i)
            currWindowSum += cardPoints[i];   // create sum for initial window
        
        minWindowSum = currWindowSum;
        totalSum += currWindowSum;
        for (int i = windowSize; i < cardPoints.length; ++i) {
            totalSum += cardPoints[i];
            currWindowSum += cardPoints[i];                   
            currWindowSum -= cardPoints[i - windowSize];      
            minWindowSum = Math.min(minWindowSum, currWindowSum);
        }
        return totalSum - minWindowSum;
    }
}