class Solution {
private:
    static bool cmp(pair<char, int>& a, pair<char, int>& b) {
        if (a.second == b.second) {
            return a.first > b.first;  // Sort lexicographically if frequencies are the same
        }
        return a.second > b.second;  // Sort by frequency
    }

public:
    string frequencySort(string s) {
        // Create a frequency map to store the count of each character
        unordered_map<char, int> freqMap;

        // Count the frequency of each character
        for (char ch : s) {
            freqMap[ch]++;
        }

        // Move the frequency data to a vector of pairs for sorting
        vector<pair<char, int>> freqVec(freqMap.begin(), freqMap.end());

        // Sort by frequency (and lexicographically if frequency is the same)
        sort(freqVec.begin(), freqVec.end(), cmp);

        // Build the result string
        string ans = "";
        for (auto& p : freqVec) {
            ans += string(p.second, p.first);  // Append character 'p.first' p.second times
        }

        return ans;
    }
};
