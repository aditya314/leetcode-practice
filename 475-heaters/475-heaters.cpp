class Solution {
private:
    int get_min_radius_for_house(int house, vector<int>& heaters){
        int low = 0, high = heaters.size() - 1, radius = INT_MAX;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(house > heaters[mid]){
                radius = min(radius, house - heaters[mid]);
                low = mid + 1;
            }   
            else if(house < heaters[mid]){
                radius = min(radius, heaters[mid] - house);
                high = mid - 1;
            }   
            else    return 0; 
        }
        return radius;
    }
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        
        int req_radius = 0;
        for(int house :  houses){
            if(house <= heaters.front()) {
                req_radius = max(req_radius, heaters.front() - house);
                continue;
            }
            if(house >= heaters.back()) {
                req_radius = max(req_radius, house - heaters.back());
                continue;
            }
            req_radius = max(req_radius, get_min_radius_for_house(house, heaters));
        }    
        return req_radius;
    }
};