#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(const std::vector<int>& nums, int target) {
    // Step 1: Create an empty hash map
    std::unordered_map<int, int> num_map;
    
    // Step 2: Iterate through the array
    for (int i = 0; i < nums.size(); ++i) {
        // Step 3: Calculate the complement
        int complement = target - nums[i];
        
        // Step 4: Check if the complement exists in the hash map
        if (num_map.find(complement) != num_map.end()) {
            // Complement found, return the indices
            return {num_map[complement], i};
        }
        
        // Step 5: Add the current number and its index to the hash map
        num_map[nums[i]] = i;
    }
    
    // Return an empty vector if no solution found (though the problem guarantees a solution)
    return {};
}

// Example usage
int main() {
    std::vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    std::vector<int> result1 = twoSum(nums1, target1);
    std::cout << "[" << result1[0] << ", " << result1[1] << "]" << std::endl; // Output: [0, 1]

    std::vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    std::vector<int> result2 = twoSum(nums2, target2);
    std::cout << "[" << result2[0] << ", " << result2[1] << "]" << std::endl; // Output: [1, 2]

    std::vector<int> nums3 = {3, 3};
    int target3 = 6;
    std::vector<int> result3 = twoSum(nums3, target3);
    std::cout << "[" << result3[0] << ", " << result3[1] << "]" << std::endl; // Output: [0, 1]

    return 0;
}



//what i submitted
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         unordered_map<int, int> hashmap;

//         for (int i = 0; i < nums.size(); i++) {
//             int complement = target - nums[i];

//             if (hashmap.find(complement) != hashmap.end()){
//                 return {hashmap[complement], i};
//         }
//         hashmap[nums[i]] = i;
//     }
//     return {};
//     }
// };



// Visual Explanation
// Consider the input array nums = [2, 7, 11, 15] and target = 9.

// Step-by-step Execution:

// Initialization:

// An empty hash map (unordered_map) num_map is created.
// Iteration:

// First Iteration (i=0, num=2):

// Calculate complement: 9 - 2 = 7.
// Check if 7 is in num_map: No.
// Add 2 to num_map with index 0: num_map = {2: 0}.
// Second Iteration (i=1, num=7):

// Calculate complement: 9 - 7 = 2.
// Check if 2 is in num_map: Yes, it is at index 0.
// Return indices: [0, 1].
// Result:

// The function returns [0, 1] because nums[0] + nums[1] = 2 + 7 = 9.
// Code Breakdown
// Here is the code again for reference:

// cpp
// Copy code
// #include <iostream>
// #include <vector>
// #include <unordered_map>

// std::vector<int> twoSum(const std::vector<int>& nums, int target) {
//     std::unordered_map<int, int> num_map;
    
//     for (int i = 0; i < nums.size(); ++i) {
//         int complement = target - nums[i];
        
//         if (num_map.find(complement) != num_map.end()) {
//             return {num_map[complement], i};
//         }
        
//         num_map[nums[i]] = i;
//     }
    
//     return {};
// }
// Explanation of Syntax and Concepts
// Function Signature:

// cpp
// Copy code
// std::vector<int> twoSum(const std::vector<int>& nums, int target)
// std::vector<int>: The function returns a vector of integers, which are the indices of the two numbers that add up to the target.
// const std::vector<int>& nums: The function takes a constant reference to a vector of integers as input.
// const: Ensures that the input vector nums is not modified within the function.
// &: Denotes that nums is passed by reference, which avoids copying the entire vector and improves performance.
// Hash Map (unordered_map):

// cpp
// Copy code
// std::unordered_map<int, int> num_map;
// This is a hash map that stores each number in nums as a key and its index as the value.
// Iteration:

// cpp
// Copy code
// for (int i = 0; i < nums.size(); ++i) {
//     int complement = target - nums[i];
    
//     if (num_map.find(complement) != num_map.end()) {
//         return {num_map[complement], i};
//     }
    
//     num_map[nums[i]] = i;
// }
// We iterate over the nums vector.
// For each element, calculate the complement (target - nums[i]).
// Check if the complement exists in num_map.
// If it does, return the indices of the current element and the complement.
// If it doesn’t, add the current element and its index to num_map.
// Why Use const and &?
// Efficiency: Passing by reference (&) avoids making a copy of the vector, which is especially important for large datasets as it saves memory and processing time.
// Safety: Using const ensures that the function does not modify the input vector, providing a guarantee about the immutability of nums within the function.
// Visual Representation
// Here is a simplified visual representation of how the function processes the array:

// plaintext
// Copy code
// nums = [2, 7, 11, 15]
// target = 9

// Iteration 1:
// num = 2, complement = 7
// num_map: {}

// Iteration 2:
// num = 7, complement = 2
// num_map: {2: 0}
// Found complement in num_map: 2 at index 0
// Return indices: [0, 1]
// Summary
// const std::vector<int>& nums: Efficiently passes the input vector by reference without copying and ensures it remains unchanged.
// Hash Map: Stores elements and their indices for quick lookup of complements.
// Iteration and Check: Efficiently finds the pair of indices that sum up to the target.
// Related Suggestions
// a. Add error handling for edge cases where no solution exists, even though the problem guarantees one.

// b. Extend the function to handle multiple solutions and return all pairs that sum up to the target.