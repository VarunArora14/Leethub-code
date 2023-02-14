class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        int carry=0,i=a.length()-1,j=b.length()-1;
        
        // till either of this satisfy the condition
        while(i>=0 || j>=0 || carry)
        {
            // for a string
            if(i>=0)
            {
                carry=carry+(a[i]-'0');
                i--; // for next char
            }
            else carry+=0; // add 0 if a string has ended
            
            // for b string
            if(j>=0)
            {
                carry=carry+(b[j]-'0');
                j--;
            }
            else carry+=0; // add 0 if b string has ended
            
            // to the ans string add carry%2 as carry is int to store the last bit and thn do carry=carry/2 for next MSB
            ans = ans + char(carry%2 + '0') ; // add carry to start as we going right to left
            // ans = char(carry%2 + '0') + ans; => this costs O(n) as inserting at start of string takes full traversal, better we reverse and do it, so better to add next and later reverse the ans
            carry=carry/2;
        }
        reverse(ans.begin(),ans.end());
        return  ans;
        // return reverse as we add the next bit on right and not left as putting on leftward is O(N)
    }
};