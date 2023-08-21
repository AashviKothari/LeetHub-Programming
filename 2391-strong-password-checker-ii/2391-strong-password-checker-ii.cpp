class Solution {
public:
    bool strongPasswordCheckerII(string pwd) 
    {
        int lower=0, upper=0, digit=0, special=0;
        
        for(int i=0; i<pwd.length(); i++)
        {
            if(i>0 && pwd[i]==pwd[i-1])  return false; //check pwd contains same char in adjacent
            
            if(islower(pwd[i])) lower=1; //check pwd contains lowercase letter
            
            else if(isupper(pwd[i])) upper=1; //check pwd contains uppercase letter
            
            else if(isdigit(pwd[i])) digit=1; //check pwd contains digit
            
            else special=1; //check pwd contains special characters
        }
        
        return (pwd.length()>7 && lower && upper && digit && special); 
        
    }
};