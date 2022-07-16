// Matrix Diagonal Sum
// Given a square matrix mat, return the sum of the matrix diagonals.
// Only include the sum of all the elements on the primary diagonal 
// and all the elements on the secondary diagonal that are not part of the primary diagonal.

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum=0;
        int n=mat.size();
        for(int i=0;i<n;i++)
        {
            sum+= mat[i][i]+mat[i][n-i-1];        // this will add first element of 1st row to last element of first row, 2nd element of 2nd row to last element of 2nd row and so on
        }
        if(n%2)                                   // if in case our n is odd i.e. mid element will repeat in both the diagonals,we'll simply subtract it once
        {
                sum-=mat[n/2][n/2];
        }
        return sum;
    }
};




// Input: mat = [[1,2,3],
//               [4,5,6],
//               [7,8,9]]
// Output: 25
// Explanation: Diagonals sum: 1 + 5 + 9 + 3 + 7 = 25
// Notice that element mat[1][1] = 5 is counted only once.

// Input: mat = [[1,1,1,1],
//               [1,1,1,1],
//               [1,1,1,1],
//               [1,1,1,1]]
// Output: 8

// Input: mat = [[5]]
// Output: 5