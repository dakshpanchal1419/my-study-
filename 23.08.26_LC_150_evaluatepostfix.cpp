// appraoch by chatgpt optimal
class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> st;

        for (string token : tokens) {

            if (token == "+" || 
                token == "-" || 
                token == "*" || 
                token == "/") {

                int right = st.top();
                st.pop();

                int left = st.top();
                st.pop();

                if (token == "+")
                    st.push(left + right);

                else if (token == "-")
                    st.push(left - right);

                else if (token == "*")
                    st.push(left * right);

                else
                    st.push(left / right);
            }
            else {
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};

//manual way to convert string to int 
class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> st;

        for (int i = 0; i < tokens.size(); i++) {

            // If token is an operator
            if (tokens[i] == "+" || 
                tokens[i] == "-" || 
                tokens[i] == "*" || 
                tokens[i] == "/") {

                int right = st.top();
                st.pop();

                int left = st.top();
                st.pop();

                int result;

                if (tokens[i] == "+") {
                    result = left + right;
                }
                else if (tokens[i] == "-") {
                    result = left - right;
                }
                else if (tokens[i] == "*") {
                    result = left * right;
                }
                else {
                    result = left / right;
                }

                st.push(result);
            }

            // Otherwise, token is a number
            else {

                int num = 0;
                int sign = 1;
                int j = 0;

                // Handle negative number
                if (tokens[i][0] == '-') {
                    sign = -1;
                    j = 1;
                }

                // Convert string to integer manually
                while (j < tokens[i].size()) {
                    num = num * 10 + (tokens[i][j] - '0');
                    j++;
                }

                num = num * sign;

                st.push(num);
            }
        }

        return st.top();
    }
};

///  1 or 2 bugs ...use of stoi in leetcode in not available so manually make string to number...

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
      stack <int>st;
      int result;
for (int i=0; i<tokens.size(); i++){
    // if (isdigit(tokens[i])){
    //     st.push(tokens[i]);  //wrong bcoz string can't be compare with isdigit() function char is applicable
    // }
    if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
       st.push(stoi(tokens[i]));      // st.push(tokens[i] is wrong..You need to use stoi() (String to Integer) to convert the string  to number before pushing: st.push(stoi(tokens[i]));.
    }
    else {
        int right =st.top();
        st.pop();
        int left= st.top();
        st.pop();
       
        if (tokens[i]=="+"){
        result = left+right ;
       }
       else if (tokens[i]=="-"){
        result = left-right ;
       }
       else if (tokens[i]=="*"){
        result = left*right ;
       }
       else{
        result = left/right ;
       }
        st.push(result);
    }
      
      }
      return st.top();
   }





};
