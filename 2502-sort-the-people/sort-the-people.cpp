class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n=heights.size();
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-i-1;j++){
                if(heights[j]<heights[j+1]){
                    int h=heights[j];
                    heights[j]=heights[j+1];
                    heights[j+1]=h;
                    string s=names[j];
                    names[j]=names[j+1];
                    names[j+1]=s;
                }
            }
        }
        return names;
        
    }
};