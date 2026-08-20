// ------wrong solution ,still some bugs, need to think again from start----------
class Solution {
public:
    bool isValid(string s) {
      stack<char> st;
for (char c : s) {
                if (c == '(' || c== '{' ||  c== '['){
                    st.push(c);
                }
              if ((c == ')' && st.top() == '(') || 
                    (c == '}' && st.top()== '{') || 
                    (c == ']' && st.top() == '[')) {
                    st.pop();
           }
           
                if (st.empty()) {
                    return false;
                }
}

             for (char c: s) {
                if (c==')'){
                   if( st.top()=='('){
                    st.pop();
                   }
                   else{
                    return false;
                   }
                }
                   if (c=='}'){
                   if( st.top()=='{'){
                    st.pop();
                   }
                   else{
                    return false;
                   }
                  }
                 if (c==']'){
                   if(st.top()=='['){
                    st.pop();
                   }
                   else{
                    return false;
                   }
                
             }
             }

            if (st.empty()){
                return true ;
            }
            else {
                return false ;
            }
         
    }
};
