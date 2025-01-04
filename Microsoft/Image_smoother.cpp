/*
QUESTION:
An image smoother is a filter of the size 3 x 3 that can be applied to each cell of an image by rounding down the average of the cell and the eight surrounding cells (i.e., the average of the nine cells in the blue smoother). If one or more of the surrounding cells of a cell is not present, we do not consider it in the average (i.e., the average of the four cells in the red smoother).


Given an m x n integer matrix img representing the grayscale of an image, return the image after applying the smoother on each cell of it.

 

Example 1:


Input: img = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[0,0,0],[0,0,0],[0,0,0]]
Explanation:
For the points (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
For the points (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
For the point (1,1): floor(8/9) = floor(0.88888889) = 0
Example 2:


Input: img = [[100,200,100],[200,50,200],[100,200,100]]
Output: [[137,141,137],[141,138,141],[137,141,137]]
Explanation:
For the points (0,0), (0,2), (2,0), (2,2): floor((100+200+200+50)/4) = floor(137.5) = 137
For the points (0,1), (1,0), (1,2), (2,1): floor((200+200+50+200+100+100)/6) = floor(141.666667) = 141
For the point (1,1): floor((50+200+200+200+200+100+100+100+100)/9) = floor(138.888889) = 138
 

Constraints:

m == img.length
n == img[i].length
1 <= m, n <= 200
0 <= img[i][j] <= 255
*/
// SOLUTION
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();
        // Create another vector for smooth image
        vector<vector<int>> v(m, vector<int>(n));
        // Iterate through the img
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int sum=0; // sum of element and its surrounding
                int no=0; // total no of elements 

                // Iterate through surrounding elements
                for(int x=i-1;x<=i+1;x++){
                    for(int y = j - 1; y <= j + 1; y++){
                        // Check if all sides are valid or not
                        if(0 <= x && x < m && 0 <= y && y < n ){
                            // If valid find sum and no of valid elements
                            sum+=img[x][y];
                            no+=1;
                        }
                    }
                }
                // Find average and store 
                v[i][j] = sum/no;

            }
        }
        // Return the new vector
        return v;




        
    }
};