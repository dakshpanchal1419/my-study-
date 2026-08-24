class MyQueue {
private:
    stack<int> inputstack;
    stack<int> outputstack;
public:
    MyQueue() {     
    }
    void push(int x) {
        inputstack.push(x);
    }
    int pop() {
        if (outputstack.empty()){
         while(!inputstack.empty()){
           outputstack.push(inputstack.top());
           inputstack.pop();
         }
        }
        int value = outputstack.top() ;
         outputstack.pop();
         return value;
        
    }
    
    int peek() {
         if (outputstack.empty()){
         while(!inputstack.empty()){
           outputstack.push(inputstack.top());
           inputstack.pop();
         }
        }
        return   outputstack.top();
    }
    
    bool empty() {
        // if(inputstack.empty() && outputstack.empty())
        // return true;
        // else 
        // return false;
         return inputstack.empty() && outputstack.empty();
        
    }
};
