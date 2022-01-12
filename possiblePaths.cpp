#include <bits/stdc++.h>

using namespace std;


bool isSafe(vector<vector<int> >grid, int i, int j, int n, int m)
{
    if((i >= 0 && i < m) && (j >= 0 && j < n))
    {
        return true;
    }
    return false;
}

void FindPaths(vector<vector<int> >grid, int i, int j, int n, int m, vector<int> &ans, vector<vector<int>> &out)
{
    if(i == n-1 && j == m-1)
    {
        //ans.push_back(grid[i][j]);
        out.push_back(ans);
    }
    
    if(isSafe(grid, i+1, j, m, n))
    {
        ans.push_back(grid[i+1][j]);
        FindPaths(grid, i+1, j, n, m, ans, out);
        ans.pop_back();
    }
    
    if(isSafe(grid, i, j+1, m, n))
    {
        ans.push_back(grid[i][j+1]);
        FindPaths(grid, i, j+1, n, m, ans, out);
        ans.pop_back();
    }
}

int main() {
      int n = 3 ,m =4;
      vector<vector<int> >grid{ {1,2,3,10},{4,5,6,11},{7,8,9,12}};
      vector<int>ans ;
      vector<vector<int>> out;
      ans.push_back(grid[0][0]);
      FindPaths(grid,0,0,n,m,ans,out); 
      
      for(auto i: out)
      {
          for(auto j:i)
          {
              cout<<j<<" ";
          }
          cout<<endl;
      }
    return 0;
}
