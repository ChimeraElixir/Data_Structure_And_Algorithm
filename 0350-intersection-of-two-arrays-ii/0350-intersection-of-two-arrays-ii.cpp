class Solution {
public:
    vector<int> intersect(vector<int>& arr1, vector<int>& arr2) {
        vector<int> result; 
  
    // Sort both arrays 
    sort(arr1.begin(), arr1.end()); 
    sort(arr2.begin(), arr2.end()); 
  
    // Two pointers for iterating through both arrays 
    int pointer1 = 0; 
    int pointer2 = 0; 
  
    // Iterate until one of the arrays is fully traversed 
    while (pointer1 < arr1.size() 
           && pointer2 < arr2.size()) { 
        if (arr1[pointer1] == arr2[pointer2]) { 
            // Found a common element 
            result.push_back(arr1[pointer1]); 
            pointer1++; 
            pointer2++; 
        } 
        else if (arr1[pointer1] < arr2[pointer2]) { 
            // Move pointer1 forward 
            pointer1++; 
        } 
        else { 
            // Move pointer2 forward 
            pointer2++; 
        } 
    } 
  
    return result; 
    }
};