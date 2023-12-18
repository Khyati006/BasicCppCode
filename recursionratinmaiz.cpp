#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
class Solution{
    private:
    bool isSafe(int x, int y,int n, vector<vector<int>>visited,vector<vector<int>>&m){
        //write to condition that where we are moving is in the grid and we are not visited it before
        if((x>=0 && x<n) && (y>=0 && x<n) && visited[x][y]==0 && m[x][y]==1){
            return true;
        }
        else{
            return false;
        }
    }
    void solve(vector<vector<int>>&m,int n,vector<string>&ans,int x,int y,vector<vector<int>>visited,string path){
        
        //you have reached x,y here


        //base case-you have reach the destination
        if(x==n-1 && y==n-1){
            ans.push_back(path);
            return;
        }

        visited[x][y]=1;
        //Now we have four choises to go as down left right up
        //now if we go down
        int newx=x+1;
        int newy=y;
        if(isSafe(newx,newy,n,visited,m)){
            path.push_back('D');
            solve(m,n,ans,newx,newy,visited,path);
            path.pop_back();//here we are backtracking as there can be another root so remove the D that we are inserted;
        }
        //left
        int newx=x;
        int newy=y-1;
        if(isSafe(newx,newy,n,visited,m)){
            path.push_back('L');
            solve(m,n,ans,newx,newy,visited,path);
            path.pop_back();//here we are backtracking as there can be another root so remove the D that we are inserted;
        }
        //right
        int newx=x;
        int newy=y+1;
        if(isSafe(newx,newy,n,visited,m)){
            path.push_back('R');
            solve(m,n,ans,newx,newy,visited,path);
            path.pop_back();//here we are backtracking as
        }
        //up
        int newx=x-1;
        int newy=y;
        if(isSafe(newx,newy,n,visited,m)){
            path.push_back('U');
            solve(m,n,ans,newx,newy,visited,path);
            path.pop_back();//here we are backtracking as
        }

        visited[x][y]=0;
    }
    public:
    vector<string>findpath(vector<vector<int>>&m,int n){
        vector<string>ans;

        //agar starting point hi zero hai toh source pe hi nahi ja sakte so return ans
        if(m[0][0]==0){
            return ans;
        }
        int srcx=0;
        int srcy=0;

        //create a visited vector
        vector<vector<int>>visited=m;
        //initialize with zero
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                visited[i][j]=0;
            }
        }
        string path="";
        solve(m,n,ans,srcx,srcy,visited,path);
        sort(ans.begin(),ans.end());

    }
};
int main(){
    
    return 0;
}