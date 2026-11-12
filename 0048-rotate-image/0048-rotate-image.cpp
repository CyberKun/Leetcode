class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int i=0,j=0;
        int newi=0,newj=0;
        int ct=0;
        int st=n;
        while(ct<n/2){
            for(int a=1;a<st;a++){
                int temp=matrix[i][j];
                newi=j,newj=n-i-1;
                swap(temp,matrix[newi][newj]);

                i=newj,j=n-newi-1;
                swap(temp,matrix[i][j]);

                newi=j,newj=n-i-1;
                swap(temp,matrix[newi][newj]);

                i=newj,j=n-newi-1;
                swap(temp,matrix[i][j]);
                j++;
            }
            st-=2;
            ct++;
            i++;
            j=i;
        }
    }
};