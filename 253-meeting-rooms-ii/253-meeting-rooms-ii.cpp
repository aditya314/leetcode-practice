class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> meeting_room_tracker(1e6 + 1, 0);
        for(vector<int> interval : intervals){
            meeting_room_tracker[interval[0]]++;
            meeting_room_tracker[interval[1]]--;
        }
        int current_meeting_room_requirement = 0, minimum_meeting_rooms = 0;
        for(int meeting_room_count : meeting_room_tracker){
            current_meeting_room_requirement += meeting_room_count;
            minimum_meeting_rooms = max(minimum_meeting_rooms, current_meeting_room_requirement);
        }
        return minimum_meeting_rooms;
    }
};