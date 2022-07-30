class Solution {
public:
    int solve(string& word, map<char,int> mp){

        for(char w: word){
            if(mp.find(w) != mp.end()){
                mp[w]-=1;
                if(mp[w] == 0) mp.erase(w);
            }
        }
        
        if(mp.size() == 0) return 1;
        return 0;
    }
	
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        map<char, int> mp;
        vector<string> ans; 

        for(auto &w: words2){
            map<char, int> m;
            for(auto &c: w){
                m[c]++;
                mp[c] = max(mp[c], m[c]);
            }
        }

        for(auto &word: words1){
            int valid = solve(word, mp);
            if(valid) ans.push_back(word);
        }
        
        return ans;
    }
};