class MyQueue {
private:

    // inputStack mein naye elements add honge.
    // Ye basically "incoming/new elements" ko store karta hai.
    stack<int> inputStack;

    // outputStack se elements remove honge.
    // Isme elements ka order reverse ho jata hai,
    // isliye sabse purana element TOP par aa jata hai.
    stack<int> outputStack;

public:

    MyQueue() {
        // Starting mein dono stacks empty hain.
    }


    void push(int x) {

        // Queue mein new element add karna hai,
        // isliye directly inputStack mein push karenge.
        //
        // Example:
        // push(1), push(2), push(3)
        //
        // inputStack:
        //     3 <- top
        //     2
        //     1
        inputStack.push(x);
    }


    int pop() {

        // Agar outputStack empty hai,
        // iska matlab abhi dequeue ke liye
        // elements correct order mein available nahi hain.
        if (outputStack.empty()) {

            // inputStack ke saare elements ko
            // outputStack mein transfer karenge.
            //
            // Ye transfer order ko reverse karega.
            //
            // inputStack:          outputStack:
            //
            //     3                     1 <- top
            //     2          --->       2
            //     1                     3
            //
            // Ab sabse purana element 1 top par hai.
            while (!inputStack.empty()) {

                // inputStack ka top element
                // outputStack mein daal rahe hain.
                outputStack.push(inputStack.top());

                // inputStack se wahi element remove kar rahe hain.
                inputStack.pop();
            }
        }

        // Ab outputStack ka TOP
        // queue ka FRONT element represent karta hai.
        int value = outputStack.top();

        // Queue se element remove karna hai,
        // isliye outputStack se bhi remove karenge.
        outputStack.pop();

        // Removed element return kar do.
        return value;
    }


    int peek() {

        // Agar outputStack empty hai,
        // pehle inputStack se elements transfer karne padenge.
        if (outputStack.empty()) {

            // inputStack -> outputStack
            // Isse oldest element top par aa jayega.
            while (!inputStack.empty()) {

                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }

        // Sirf front element dekhna hai,
        // remove nahi karna.
        return outputStack.top();
    }


    bool empty() {

        // Queue tabhi empty hogi
        // jab DONO stacks empty hon.
        //
        // Case 1:
        // inputStack empty + outputStack empty
        // => Queue empty
        //
        // Case 2:
        // inputStack mein elements hain
        // => Queue empty nahi hai
        //
        // Case 3:
        // outputStack mein elements hain
        // => Queue empty nahi hai

        return inputStack.empty() && outputStack.empty();
    }
};
