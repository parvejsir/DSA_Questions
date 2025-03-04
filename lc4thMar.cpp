#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        bool checkPowersOfThree(int n) {
            int maxPossiblePower=0;
            while(pow(3,maxPossiblePower)<=n){
                maxPossiblePower++;
            }
            while(n>0){
                if(pow(3,maxPossiblePower)<=n)n-=pow(3,maxPossiblePower);
                if(pow(3,maxPossiblePower)<=n)return false;
                maxPossiblePower--;
            }
            return true;
        }
    };

class Solution {
    public:
        vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
            int m=mat.size();
            int n=mat[0].size();
            vector<vector<int>> vis(m,vector<int>(n,0));
            vector<vector<int>> dis(m,vector<int>(n,0));
            //store{(row,col),distanceOfZero}
            queue<pair<pair<int,int>,int>> q;
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(mat[i][j]==0){
                        q.push({{i,j},0});
                        vis[i][j]=1;
                    }else{
                        vis[i][j]=0;
                    }
                }
            }
            int delrow[]={-1,0,+1,0};
            int delcol[]={0,+1,0,-1};
            while(!q.empty()){
                int row=q.front().first.first;
                int col=q.front().first.second;
                int steps=q.front().second;
                q.pop();
                dis[row][col]=steps;
                //neighbour check and traverse
                for(int i=0;i<4;i++){
                    int newrow=row+delrow[i];
                    int newcol=col+delcol[i];
                    if(newrow>=0 && newrow<m && newcol>=0&& newcol<n && vis[newrow][newcol]==0){
                        vis[newrow][newcol]=1;
                        q.push({{newrow,newcol},steps+1});
                    }
                }
            }
          return dis;
        }
    };

    class Solution {
        public:
            void dfs(int row,int col,vector<vector<char>>& board,vector<vector<int>> &vis){
                vis[row][col]=1;
                int n=board.size();
                int m=board[0].size();
                int drow[]={-1,0,1,0};
                int dcol[]={0,1,0,-1};
                for(int i=0;i<4;i++){
                   int nrow=row+drow[i];
                   int ncol=col+dcol[i];
                   if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && vis[nrow][ncol]==0 && board[nrow][ncol]=='O'){
                    dfs(nrow,ncol,board,vis);
                   }
        
                }
            }
            void solve(vector<vector<char>>& board) {
                int n=board.size();
                int m=board[0].size();
                vector<vector<int>> vis(n,vector<int>(m,0));
        
        
            for(int j=0;j<m;j++){
                    //first row 0s check dfs
                    if(vis[0][j]==0 && board[0][j]=='O'){
                        dfs(0,j,board,vis);
                    }
                    //last row 0s check dfs
                    if(vis[n-1][j]==0 && board[n-1][j]=='O'){
                        dfs(n-1,j,board,vis);
                    }
                }
        
            for(int i=0;i<n;i++){
                    //first col 0s check dfs
                    if(vis[i][0]==0 && board[i][0]=='O'){
                        dfs(i,0,board,vis);
                    }
                    //last row 0s check dfs
                    if(vis[i][m-1]==0 && board[i][m-1]=='O'){
                        dfs(i,m-1,board,vis);
                    }
                }
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(board[i][j]=='O' && vis[i][j]!=1){
                        board[i][j]='X';
                    }
                }
            }  
            }
        };
    