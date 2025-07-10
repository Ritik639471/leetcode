class Solution {
public:
    int maxArea(vector<int>& height) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int maxarea=0;
      int i=0,j=height.size()-1;
      while(i<j){
        int heigh=(height[i]<height[j])?height[i]:height[j];
        int area =((heigh)*(j-i));
        if(maxarea<area)
           maxarea=area;
        if(height[i]<height[j]) 
           i++;
        else if(height[i]>height[j]) 
          j--;
        else{
            i++;j--;
        }
       }
      return maxarea;
    }
};