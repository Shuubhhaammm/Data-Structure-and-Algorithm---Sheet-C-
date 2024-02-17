class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;   //maxHeap
        int i=0;
        for( i=0; i<heights.size()-1; i++){
            if(heights[i+1] <= heights[i]){
                continue;
            }
            int diff=heights[i+1]-heights[i];
            bricks = bricks -diff;
            pq.push(diff);

            if(bricks < 0){
                bricks=bricks+pq.top();
                pq.pop();
                ladders--;
            }
            if(ladders < 0){
                break;
            }

        }
        return i;
    }
};