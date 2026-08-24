//MAX_SLIDING_WINDOW_MONOTONIC_DEQUE 
/*
Maximum → Decreasing Deque

Front → Maximum
Back  → New element se comparison

1. Expired index → pop_front()
2. Smaller element → pop_back()
3. Current index → push_back()
4. Front → current window ka maximum

Time  : O(n)
Space : O(k)
*/
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;       // indexes store karo, values nahi
    vector<int> answer;

    for (int i = 0; i < nums.size(); i++) {

        // Window ke bahar wala index hatao
        if (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        // Chhote useless elements ko back se hatao
        while (!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }

        // Current index add karo
        dq.push_back(i);

        // Window complete → front par maximum
        if (i >= k - 1) {
            answer.push_back(nums[dq.front()]);
        }
    }

    return answer;
}
