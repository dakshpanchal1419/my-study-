/// using slow and fast approach (flyod algorithim)

class Solution {
private:
    // Helper function to calculate the sum of the squares of digits
    int getNext(int n) {
        int sum = 0;
        while (n > 0) {
            int dig = n % 10;
            sum += dig * dig;
            n /= 10;
        }
        return sum;
    }

public:
    bool isHappy(int n) {
        int slow = n;
        int fast = getNext(n);
        
        // Loop until fast reaches 1 (happy) or slow and fast meet (cycle detected)
        while (fast != 1 && slow != fast) {
            slow = getNext(slow);          // Moves 1 step
            fast = getNext(getNext(fast)); // Moves 2 steps
        }
        
        return fast == 1;
    }
};
