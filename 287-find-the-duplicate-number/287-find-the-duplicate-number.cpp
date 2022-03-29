class Solution {
    //To compute the intersection point, let's note that the hare has traversed twice as many nodes as the tortoise, i.e. 2d(tortoise)=d(hare), implying:
    //2(F + a) = F + nC + a, where n is some integer.
    //Hence the coordinate of the intersection point is F + a = nC
    
    //Let's show that this time they meet at the cycle entrance after FF steps.
    //The tortoise started at zero, so its position after FF steps is FF.
    //The hare started at the intersection point F + a = nC, so its position after F steps is nC + F, that is the same point as F.
    //So the tortoise and the (slowed down) hare will meet at the entrance of the cycle.
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.empty())  return -1;
        int hare = nums[0], tortoise = nums[0];
        do {
            hare = nums[nums[hare]];
            tortoise = nums[tortoise];
        } while(hare != tortoise);
        
        tortoise = nums[0];
        while(hare != tortoise){
            hare = nums[hare];
            tortoise = nums[tortoise];
        }
        return hare;
    }
};