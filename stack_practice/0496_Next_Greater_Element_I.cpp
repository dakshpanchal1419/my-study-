// --cleaner way to think about the problem---
//   nums2
//  ↓
// process elements from left → right
//  ↓
// maintain candidates
//  ↓
// when current element is greater
//  ↓
// resolve previous elements

Create empty stack
Create mapping

For every element in nums2:

    while stack is not empty
          AND current is greater than stack.top():

        stack.top() → current
        pop stack

    push current


Remaining elements in stack:

    their answer = -1


Create final answer

For every element in nums1:

    retrieve its answer from mapping

