//////not all cases are pased , some bugs are there//////


class Solution {
public:
    bool isValid(string s) {
      stack<char> st;
for (char c : s) {
                if (c == '(' || c== '{' ||  c== '['){
                    st.push(c);
                }
}
             for (char c: s) {
                if (c==')'){
                   if( st.top()==c){
                    st.pop();
                   }
                   else{
                    return false;
                   }
                }
                   if (c=='}'){
                   if( st.top()==c){
                    st.pop();
                   }
                   else{
                    return false;
                   }
                  }
                 if (c==']'){
                   if( st.top()==c){
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




