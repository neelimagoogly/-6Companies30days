/*
QUESTION
You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.

Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

Note: You cannot rotate an envelope.

 

Example 1:

Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
Example 2:

Input: envelopes = [[1,1],[1,1],[1,1]]
Output: 1
 

Constraints:

1 <= envelopes.length <= 105
envelopes[i].length == 2
1 <= wi, hi <= 105
*/
// SOLUTION
class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        //Convert the vector to LIS
        sort(envelopes.begin(), envelopes.end(), comp);
        int i, j, n=envelopes.size();
        //Find the longest increasing subsequence (LIS) of the height values
        vector<int>lis;

        for(i=0; i<n; i++){
            auto it = lower_bound(lis.begin(), lis.end(), envelopes[i][1]);
            //If the height is larger than any element in lis, it gets appended.
            if(it==lis.end()){lis.push_back(envelopes[i][1]);}
            else{
                //If it is smaller than an element in lis, we replace the existing element
                *it = envelopes[i][1];
            }
        }
        return lis.size();



    }
};