class Solution {
public:
    bool checkOperator(string s)
    {
       if(s.length()>1) return false;
        
        if(s=="*" || s=="/" || s=="+" || s=="-")
            return true;
        return false;
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<long> st; // use stoi for num if not operator
        for(string str:tokens)
        {
            if(checkOperator(str))
            {
                long val2 = st.top();
                st.pop();
                long val1=st.top();
                st.pop();
                switch(str[0])
                {
                    case '+': st.push(val1+val2);
                        break;
                        
                    case '-': st.push(val1-val2);
                        break;
                        
                    case '*': st.push(val1*val2);
                        break;
                    
                    case '/': st.push(val1/val2);
                        break;
                }
                
            }
            else{
                st.push(stoi(str));
            }
        }
        return st.top();
    }
};
/*
few things to note before - 1. expression is valid, 2. we need stack for nums only as we execute the operators
we use the stoi for numbers stored in variables and we create a func called checkOperator() for checking if +,-,* or /
*/