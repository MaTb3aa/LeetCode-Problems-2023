class Solution {
public:
    char arr[1003][3003];
    string convert(string s, int numRows) {
        if(numRows == 1)return s;
        int i=0,j=0,idx=0,n=s.size(),m=0;
        memset(arr,'0',sizeof arr);
        while(idx<n){
            while(i<numRows && idx < n )arr[i++][j]=s[idx++];
            i-=2;j++;
            while(idx<n && i>0 && idx< n)arr[i--][j++]=s[idx++];
            m=max(m,j);
        }
        string ans="";
        for(int i = 0;i<n;i++)
            for(int j=0;j<m;j++)
                if(arr[i][j]!='0')ans+=arr[i][j];
           
        return ans;
    }
};