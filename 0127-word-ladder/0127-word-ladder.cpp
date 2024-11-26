class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(),wordList.end(),endWord) == wordList.end()) {
            return 0;
        }
        queue<pair<string,int>> q;
        unordered_set<string> s(wordList.begin(),wordList.end());
        s.erase(beginWord);
        int n = beginWord.size();

        q.push({beginWord,1});

        while(!q.empty()){
            string word = q.front().first;
            int dist = q.front().second;
            q.pop();

            if(word == endWord){
                return dist;
            }
            else{
                for(int i=0;i<n;i++){
                    string copy = word;
                    for(char c = 'a';c<='z';c++){
                        copy[i] = c;
                        if(s.find(copy) != s.end()){
                            s.erase(copy);
                            q.push({copy,dist+1});
                        }
                    }
                }
            }
        }
        return 0;
    }
};