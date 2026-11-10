/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int>start;
        vector<int>end;
        for(Interval& interval : intervals){
            start.push_back(interval.start);
            end.push_back(interval.end);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int room = 0;
        int max_room = 0;
        int start_index = 0;
        int end_index = 0;
        while(start_index<start.size()){
            if(start[start_index]<end[end_index]){
                room++;
                start_index++;
            }else if(start[start_index]>end[end_index]){
                room--;
                end_index++;
            }else{
                start_index++;
                end_index++;
            }
            max_room = max(max_room, room);
        }
        return max_room;
    }
};
