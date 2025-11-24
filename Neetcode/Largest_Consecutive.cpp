/**
 * Problem: Longest Consecutive Sequence
 * Link: https://neetcode.io/problems/longest-consecutive-sequence/question
 * Approach: HashMap (Sequence Merging / Boundary Update)
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * * Intuition:
 * We iterate through the array and use a HashMap to store the length of the sequence 
 * that a number belongs to. For each new number, we check its neighbors (left and right) 
 * to see if they can be extended.
 * * 1. Retrieve the lengths of the left neighbor (num - 1) and right neighbor (num + 1).
 * 2. Calculate the new total length: left_len + right_len + 1 (the number itself).
 * 3. Crucial Step: Update the boundaries of the sequence (num - left_len and num + right_len)
 * with the new total length. This effectively "bridges" two sequences together.
 * 4. Store the length in map[num] to mark it as visited and handle duplicates.
 */

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int , int> my_map;
        int res = 0;
        for(int num : nums){
            if(!my_map[num]){

                int left = my_map[num - 1];
                int right = my_map[num + 1];
                int sum = left + right + 1;
                
                my_map[num] = sum;
                
                // Update the boundaries of the sequence
                my_map[num - left] = sum;
                my_map[num + right] = sum;

                res = max(res , sum);
            }
        }
        return res;
    }
};