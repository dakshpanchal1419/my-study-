class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque <int>dq;    // used to store the indexes of nums
        vector<int>answer ; // used to store maximum element in the window
         
         for (int i=0 ; i<nums.size();i++){
            
            //remove the previous element (front when window reach the size k) OR REMOVE THE INDEXES OUTSIDE THE WINDOW  (condition if dq.front()<=i-k  must remove dq.front())
            if (!dq.empty() && dq.front() <= i-k){
                dq.pop_front() ;
            }

            //REMOVE THE SMALLER USELESS PREVIOUS NUMBER IN THE DEQUE  // here dq.back() is last index
            while (!dq.empty() && nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }  
            //add current index after each itteration
            dq.push_back(i);     

           //window is ready need to collect max element
            if (i>=k-1){
                answer.push_back(nums[dq.front()]);
            }             
         }
         return answer;

    }
};
