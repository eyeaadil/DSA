class Solution {
public:
    typedef pair<int,int>P;
    int firstUniqChar(string s) {
        int n = s.size();
        unordered_map<int,P>mp;
        for(int i=0;i<n;i++){
            int ch = s[i];
            mp[ch].first++;
            mp[ch].second = i;
        }

        int minIndex = INT_MAX;
        for(auto &it :mp){
            int chr = it.first;

            P curr = it.second;

            int count = curr.first;
            int ind = curr.second;
            
            if(count == 1){
                minIndex = min(minIndex,ind);
            }
        }

       if(minIndex ==INT_MAX) return -1;

       return minIndex;
    }
};