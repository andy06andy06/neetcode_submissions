class Twitter {
    int count;
    unordered_map<int, vector<pair<int, int>>> tweetmap;
    unordered_map<int, unordered_set<int>> followmap;
public:
    Twitter() {
        count = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetmap[userId].push_back({count++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>> maxheap;
        vector<int> usr_ids = {userId};
        if(!followmap[userId].empty()){
            for(int usrs : followmap[userId]){
                usr_ids.push_back(usrs);
            }
        }
        for(int user : usr_ids){
            for(auto& p : tweetmap[user]){
                maxheap.push(p);
            }
        }
        while(!maxheap.empty() && res.size()<10){
            int tweet = maxheap.top().second;
            maxheap.pop();
            res.push_back(tweet);
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followmap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followmap[followerId].erase(followeeId);
    }
};
