class Solution {
private:
    static const long long MOD = 1e9 + 7;
    long long get_vowel_permutation_count(vector<vector<long long>>& dp, int i, int n, int vowel){
        if(i == n - 1)  return 1;
        if(i >= n)   return 0;
        if(dp[i][vowel] != -1)  return dp[i][vowel];
        if(vowel == 0){
            dp[i][vowel] = get_vowel_permutation_count(dp, i + 1, n, 1) % MOD;
        }
        else if(vowel == 1){
            dp[i][vowel] = (get_vowel_permutation_count(dp, i + 1, n, 0) %MOD + get_vowel_permutation_count(dp, i + 1, n, 2) %MOD) % MOD;
        }
        else if(vowel == 2){
            dp[i][vowel] = (get_vowel_permutation_count(dp, i + 1, n, 0) %MOD + get_vowel_permutation_count(dp, i + 1, n, 1) %MOD + get_vowel_permutation_count(dp, i + 1, n, 3) %MOD + get_vowel_permutation_count(dp, i + 1, n, 4) %MOD) % MOD;
        }
        else if(vowel == 3){
            dp[i][vowel] = (get_vowel_permutation_count(dp, i + 1, n, 2) %MOD  + get_vowel_permutation_count(dp, i + 1, n, 4)% MOD) % MOD;
        }
        else if(vowel == 4){
            dp[i][vowel] = get_vowel_permutation_count(dp, i + 1, n, 0) % MOD;       
        }
        return dp[i][vowel];
    }
public:
    int countVowelPermutation(int n) {
        vector<vector<long long>> dp(n, vector<long long>(5, -1LL));
        long long result = 0;
        for(int vowel = 0; vowel < 5; vowel++){
            result = (result % MOD + get_vowel_permutation_count(dp, 0, n, vowel) % MOD) % MOD;
        }
        cout << result << endl;
        return (int) result;
    }
};