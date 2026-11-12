class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        map<int,int>rows,cols;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    rows[i]++;
                    cols[j]++;
                }
            }
        }

        for(int i=0;i<max(n,m);i++){
            if(rows[i]){
                for(int j=0;j<m;j++)matrix[i][j]=0;
            }
            if(cols[i]){
                for(int j=0;j<n;j++)matrix[j][i]=0;
            }
        }
    }
};