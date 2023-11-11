#include <string>
#include <vector>


using namespace std;

int ret = 1000000000;

int backtracking(int r, int c, int count, vector<vector<bool>> visited, vector<string> board){
    
    if(board[r][c] == 'G')
        return count;
    
    int rsize = board.size();
    int csize = board[0].size();
  
    for(int i = 0; i < 4; i++){
        int nr = r;
        int nc = c;
        if(i == 0){
            nr = r;
            for(nc = c; nc < csize; nc++){
                if(nc == csize - 1)
                    break;
                
                if(board[nr][nc + 1] == 'D')
                    break;
            }
        }
        else if(i == 1){
            nc = c;
            for(nr = r; nr < rsize; nr++){
                if(nr == rsize - 1)
                    break;
                
                if(board[nr + 1][nc] == 'D')
                    break;
            }
        }
        else if(i == 2){
            nr = r;
            for(nc = c; nc >= 0; nc--){
                if(nc == 0)
                    break;
                
                if(board[nr][nc - 1] == 'D')
                    break;
            }
        }
        else if(i == 3){
            nc = c;
            for(nr = r; nr >= 0; nr--){
                if(nr == 0)
                    break;
                
                if(board[nr - 1][nc] == 'D')
                    break;
            }
        }
        if(visited[nr][nc] == false || (nr != r && nc != c)){
            visited[nr][nc] = true;
            ret = min(ret, backtracking(nr, nc, count + 1, visited, board));
            visited[nr][nc] = false;
        }
    }
    return ret;
}

int solution(vector<string> board) {
    int answer = 0;
    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
    
    int rsize = board.size();
    int csize = board[0].size();
    for(int i = 0; i < rsize; i++){
        for(int j = 0; j < csize; j++){
            if(board[i][j] == 'R'){
                visited[i][j] = true;
                answer = backtracking(i, j, 0, visited, board);
                break;
            }
        }
    }
    
    if(answer == 1000000000)
        return -1;
    
    return answer;
}
