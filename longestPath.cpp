//Link : https://www.geeksforgeeks.org/longest-possible-route-in-a-matrix-with-hurdles/

#include <bits/stdc++.h>

using namespace std;

#define R 3
#define C 10

//int ans = 0;

bool isSafe(int mat[R][C], int i, int j, int m, int n, int visited[R][C])
{
    if((i>=0 && i<R) && (j>=0 && j<C) && mat[i][j] == 1 && visited[i][j] == 0)
        return true;
    return false;
}

void solve(int mat[R][C], int i, int j, int m, int n, int count, int visited[R][C], int &ans)
{
    if(i == m && j == n)
    {
           // cout<<count;
        if(count > ans)
        {
            ans = count;
        }
        return;
    }
    
    visited[i][j] = 1;
    
    if(isSafe(mat, i+1, j, m, n, visited))
    {
        count++;
        solve(mat, i+1, j, m, n, count, visited, ans);
        count--;
    }
    
    if(isSafe(mat, i-1, j, m, n, visited))
    {
        count++;
        solve(mat, i-1, j, m, n, count, visited, ans);
        count--;
    }
    
    if(isSafe(mat, i, j+1, m, n, visited))
    {
        count++;
        solve(mat, i, j+1, m, n, count, visited, ans);
        count--;
    }
    
    if(isSafe(mat, i, j-1, m, n, visited))
    {
        count++;
        solve(mat, i, j-1, m, n, count, visited, ans);
        count--;
    }
    
    visited[i][j] = 0;
}

void findLongestPath(int mat[R][C], int i, int j, int m, int n, int visited[R][C], int &ans)
{
    int count = 0;
    
    solve(mat, i, j, m, n, count, visited,ans);
    
    cout<<ans;
}

int main()
{
    int mat[R][C] = { { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
                      { 1, 1, 0, 1, 1, 0, 1, 1, 0, 1 },
                      { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } };
                      
    int visited[R][C] = {0};
    
    int ans = 0;
 
    findLongestPath(mat, 0, 0, 1, 7, visited, ans);
    
    //cout<<ans;
    
    return 0;
}
