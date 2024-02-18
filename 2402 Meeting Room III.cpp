class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();

        //sort the meetings to get the least starting time meeting first
        sort(meetings.begin(), meetings.end());

        vector<int> roomBookCount(n,0);
        vector<long long> lastAvailableAt(n,0);

        for(vector<int>& meet:meetings){
            int startTime = meet[0];
            int endTime   = meet[1];

            bool found    = false;

            long long Early_End_Room_Time = LLONG_MAX;
            int Early_End_Room            = 0;

            for(int room = 0; room < n; room++){

                //rooms are available for meeting
                if(lastAvailableAt[room] <= startTime){
                    found = true;
                    lastAvailableAt[room] = endTime;
                    roomBookCount[room]++;
                    break;
                }
                
                //if rooms are occupied by meetings
                if(lastAvailableAt[room] < Early_End_Room_Time){
                    Early_End_Room = room;
                    Early_End_Room_Time = lastAvailableAt[room];
                }
            }
            //now, avail room for the meeting who are waiting
            if(!found){
                lastAvailableAt[Early_End_Room] += (endTime - startTime);
                roomBookCount[Early_End_Room]++;
            }
        }

        int resultRoom = -1;
        int maxUse = 0;

        for(int room = 0; room < n; room++){
            if(roomBookCount[room] > maxUse){
                maxUse = roomBookCount[room];
                resultRoom = room;
            }
        }
        return resultRoom;
    }
};