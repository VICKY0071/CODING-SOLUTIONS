

int countClouds(std::vector<std::vector<char>> skyMap) {
    if(skyMap.empty())  return 0;
    int result = 0;
    int dc[4] = {-1, 1, 0, 0};
    int dr[4] = {0, 0, -1, 1};
    int r, c, rr, cc;
    vector<vector<bool>> vis(skyMap.size(), vector<bool>(skyMap[0].size(), false));
    list<pair<int, int>> queue;
    for(int i= 0;i<skyMap.size();i++){
        for(int j= 0;j<skyMap[i].size();j++){
            if(skyMap[i][j] == '1' && vis[i][j] == false){
                result++;
                queue.push_back({i, j});
                vis[i][j] = true;
                while(!queue.empty()){
                    pair<int, int> temp = queue.front();
                    r = temp.first;
                    c = temp.second;
                    queue.pop_front();
                    for(int a = 0;a < 4;a++){
                        rr = r + dr[a];
                        cc = c + dc[a];
                        if(rr < 0 || cc < 0 || rr > skyMap.size() - 1 || cc > skyMap[0].size() - 1 || vis[rr][cc] || skyMap[rr][cc] == '0'){
                            continue;
                        }
                        vis[rr][cc] = true;
                        queue.push_back({rr, cc});
                    }
                }
            }
        }
    }
    return result;
}
