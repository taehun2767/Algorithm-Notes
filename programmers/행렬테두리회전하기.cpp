#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<int>> board;

vector<vector<int>> makeBoard(int rows, int columns){
    vector<vector<int>> board(rows+1, vector<int>(columns+1));
    for(int i = 1; i <= rows; i++)
    {
        for(int j = 1; j <= columns; j++)
        {
            board[i][j] = columns * (i - 1) + j;
        }
    }
    return board;
}

int rotate(vector<int> query, vector<vector<int>> &board){
    int prev, cur, min;
    int x1 = query[0];
    int y1 = query[1];
    int x2 = query[2];
    int y2 = query[3];
    
    prev = board[x1+1][y1];
    min = prev;
    
    for(int y = y1; y <= y2; y++){
        cur = board[x1][y];
        board[x1][y] = prev;
        if(cur < min)
            min = cur;
        prev = cur;
    }
    
    for(int x = x1 + 1; x <= x2; x++){
        cur = board[x][y2];
        board[x][y2] = prev;
        if(cur < min)
            min = cur;
        prev = cur;
    }

    for(int y = y2 - 1; y >= y1; y--){
        cur = board[x2][y];
        board[x2][y] = prev;
        if(cur < min)
            min = cur;
        prev = cur;
    }
    
    for(int x = x2 - 1; x >= x1; x--){
        cur = board[x][y1];
        board[x][y1] = prev;
        if(cur < min)
            min = cur;
        prev = cur; 
        
    }
    
    return min;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    board = makeBoard(rows, columns);

    for(auto q : queries){
        int min = rotate(q, board);
        answer.push_back(min);
    }
    
    return answer;
}
