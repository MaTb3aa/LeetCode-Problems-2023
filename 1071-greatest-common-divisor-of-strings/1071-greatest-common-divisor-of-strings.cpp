class Solution {
public:
    
    string gcdOfStrings(string a, string b) {
            if(a+b != b +a)return "";
            int g = gcd(a.size(),b.size());
            return a.substr(0,g);
        
      
    }
};