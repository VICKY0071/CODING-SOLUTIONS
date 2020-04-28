int squareSolution(vector<vector<bool>> a){
    //basic O(n ^ 2) solution 
    int dc[] = {-1, 1, 0, 0};
    int dr[] = {0, 0, -1, 1};
    int rr, cc;
    int result = 0;
    for(int i = 0;i<a.size();i++){
        for(int j = 0;j<a[i].size();j++){
            if(a[i][j] == false)    continue;
            else{
                for(int x = 0;x < 4;++x){
                    rr = i + dr[x];
                    cc = j + dc[x];
                    
                    if(rr >= a.size() || cc >= a[0].size() || rr < 0 || cc < 0 || a[rr][cc] == false){
                        result++;
                        continue;
                    }
                }
            }
        }
    }
    return result;
}

int bfs(vector<vector<bool>> a){
    //bfs solution...
    //complexity is O(time to find the first true block) + O(no of true blocks)
    //average cases would be much better than an O(n ^ 2) solution...
    int start = - 1;
    int end = -1;
    int dc[] = {-1, 1, 0, 0};
    int dr[] = {0, 0, -1, 1};
    vector<vector<bool>> visited(a.size(), vector<bool>(a[0].size(), false));
    int rr, cc;
    int result = 0;
    for(int i = 0;i<a.size();i++){
        for(int j = 0;j<a[i].size();j++){
            if(a[i][j] == true){
                start = i;
                end = j;
                break;
            }
        }
        if(start != -1 && end != -1)    break;
    }
    list<pair<int, int>> queue;
    queue.push_back({start, end});
    visited[start][end] = true;
    pair<int ,int> temp;
    while(!queue.empty()){
        temp = queue.front();
        queue.pop_front();
        int x = temp.first;
        int y = temp.second;
        if(a[x][y] == false)    continue;
        for(int i = 0;i<4;i++){
            rr = x + dr[i];
            cc = y + dc[i];
            

            if(rr < 0 || cc < 0 || rr >= a.size() || cc >= a[0].size() || a[rr][cc] == false){
                result++;
                continue;
            }
            if(visited[rr][cc]){
                continue;
            }
            visited[rr][cc] = true;
            queue.push_back({rr, cc});
        }
    }queue.clear();
    return result;
}

int polygonPerimeter(std::vector<std::vector<bool>> matrix) {
    return bfs(matrix);
}   
