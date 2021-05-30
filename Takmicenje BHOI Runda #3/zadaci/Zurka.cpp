#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;
// map<int, bool> visited;
// map<int, bool> visited2;
// map<int, bool> friendOfGoodFriend;
// map<int, bool> isGoodFriend;
// map<int, bool> hasGoodFriend;

// map<int, vector<int>> goodFriendGraph;
map<int, vector<int>> graph;

// void bfs(int src) {
//     visited[src] = true;
//     queue<int> q;
//     int counter = 0;
//     q.push(src);

//     while(!q.empty()) {
//         int curr = q.front();
//         q.pop();

//         if(graph[curr].size() >= 2) {
//             isGoodFriend[curr] = true;
//             goodFriendGraph[curr] = {};
//         } else {
//             return;
//         }

//         for (int i = 0; i < graph[curr].size(); i++) {
//             if(!visited[graph[curr][i]]) {
//                 visited[graph[curr][i]] = true;
//                 // if(graph[graph[curr][i]].size() >= 2) {
//                 //     isGoodFriend[graph[curr][i]] = true;
//                 // }
//                 if(graph[graph[curr][i]].size() >= 2) {
//                     q.push(graph[curr][i]);
//                     goodFriendGraph[curr].push_back(graph[curr][i]);
//                 }
//             }
//         }
//     }
// }

// bool checkIfGood(int src, int _counter) {
//     visited[src] = true;
//     int counter = _counter;
//     if(graph[src].size() >= 2) {
//         for (int i = 0; i < graph[src].size(); i++) {
//             if(!visited[graph[src][i]] && checkIfGood(graph[src][i], 1)) {
//                 counter++;
//             }
//         }
//         if(counter >= 2) {
//             return true;
//         } else {
//             return false;
//         }
//     } else {
//         return false;
//     }
// }

void removeSingleNodes() {
    queue<int> q;
    for(auto node : graph) {
        int myId = node.first;
        if(node.second.size() == 1) {
            q.push(myId);
        }
    }
    while(!q.empty()) {
        int myId = q.front();
        q.pop();
        if(graph[myId].size() <= 0)
            continue;
        int childId = graph[myId][0];

        graph[myId] = {};
        vector<int> neighbours = graph[childId];
        auto iterator = find(neighbours.begin(), neighbours.end(), myId);
        neighbours.erase(iterator);
        graph[childId] = neighbours;
        if(graph[childId].size() == 1) {
            q.push(childId);
        }
    }
}

int main() {
    int m, n;
    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    removeSingleNodes();

    int counter = 0;
    for(auto node : graph) {
        if(node.second.size() > 1) {
            counter++;
        }
    }
    cout << counter;
    // int maxFriends = -1;
    // for (int i = 0; i < m; i++) {
    //     if(!visited[i])
    //         bfs(i);
    // }

    // for(auto i : isGoodFriend) {
    //     if(i.second == true && !visited2[i.first] == true) {
    //         int totalFriends = bfs2(i.first);
    //         maxFriends = max(totalFriends, maxFriends);
    //     }
    // }
    
    // cout << maxFriends;

    return 0;
}