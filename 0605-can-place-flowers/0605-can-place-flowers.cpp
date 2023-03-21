class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
         for(int i=0;i<flowerbed.size();i++){
             if(!i){
                 if(!flowerbed[i] && i+1<flowerbed.size() && !flowerbed[i+1])flowerbed[i]=1,n--;
             }
             else if(i==flowerbed.size()-1){
                 if(!flowerbed[i] && i && !flowerbed[i-1])flowerbed[i]=1,n--;
             }
             else {
                 if(!flowerbed[i] && !flowerbed[i-1] && !flowerbed[i+1])
                     flowerbed[i]=1,n--;
             }
         }
        if(flowerbed.size()==1 && n==1 && !flowerbed[0] )return 1;
        return n<=0;
    }
};