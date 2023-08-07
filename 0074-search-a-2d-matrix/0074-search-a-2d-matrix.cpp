class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
   int m=matrix.size();
   int n=matrix[0].size();
   int i=0;
   int j=n-1;
   while(i<m && j>=0){
    int p=matrix[i][j];
    if(p==target)
    return true;
    else if(p>target)
    j--;
    else 
    i++;
   }
   return false;
   
    }
};

// for each cell: mat[i[[j] > mat[i][j-1] and mat[i][j] < mat[i+1][j]
// if mat[i[[j] > target, so target must be left side, so we move leftwards
// if mat[i[[j] < target, so target must be down side, so we move downwards