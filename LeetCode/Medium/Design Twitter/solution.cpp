class Twitter {
public:
    int time = 0;
    vector<unordered_set<int>> followers;
    map<int,pair<int,int>,greater<int>> posts;
    
    Twitter() {
        followers.resize(501);
        for(int i = 0; i < 501; i++){
            followers[i].insert(i);
        }
    }
    
    void postTweet(int userId, int tweetId) {
        posts[time] = {userId,tweetId};
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;

        for(auto it: posts){
            if(ans.size() == 10) break;
            
            int poster = it.second.first;
            int tweet = it.second.second;
            if(followers[userId].find(poster) != followers[userId].end()){
                ans.push_back(tweet);
            }
        }
        
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if((followers[followerId].find(followeeId) != followers[followerId].end()) && followerId != followeeId) followers[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */