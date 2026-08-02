class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>> events;

        // Start: negative height, End: positive height
        for (auto &b : buildings) {
            events.push_back({b[0], -b[2]});
            events.push_back({b[1],  b[2]});
        }

        sort(events.begin(), events.end());

        multiset<int> heights;
        heights.insert(0);

        unordered_map<int, vector<int>> startMap, endMap;

        for (auto &b : buildings) {
            startMap[b[0]].push_back(b[2]);
            endMap[b[1]].push_back(b[2]);
        }

        vector<vector<int>> ans;
        int prev = 0;

        int i = 0;
        while (i < events.size()) {
            int x = events[i].first;

            // Add all buildings starting here
            if (startMap.count(x)) {
                for (int h : startMap[x])
                    heights.insert(h);
            }

            // Remove all buildings ending here
            if (endMap.count(x)) {
                for (int h : endMap[x])
                    heights.erase(heights.find(h));
            }

            int curr = *heights.rbegin();

            if (curr != prev) {
                ans.push_back({x, curr});
                prev = curr;
            }

            while (i < events.size() && events[i].first == x)
                i++;
        }

        return ans;
    }
};