class Solution {
public:
    bool ok(string &a,string &b,string &c){
        int i=0,j=0,k=0;
        while(i<a.size() || j < b.size()){
           if(i<a.size()){
               if(a[i++]!=c[k])return 0;
              
           } 
           if(j<b.size()){
               if(b[j++]!=c[k])return 0;
           }
            k++;
            k%=c.size();
        }
        return 1;
    }
    string gcdOfStrings(string a, string b) {
        int sza = a.size() , szb = b.size();
        string ans="",best="";
        for(int i = 0 ; i < min(sza,szb);i++){
            if(a[i]==b[i]){
                ans+=a[i];
                if(sza%ans.size()==0 && szb%ans.size()==0 && ok(a,b,ans)){
                    best = ans;
                }
            }
            else break;
        }
        return best;
        
      
    }
};