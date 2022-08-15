#include<iostream>
#include <string> 
using namespace std;

const int rows = 5;
const int cols = 6;
string path[rows][cols]; // declare a path matrix, it is a string matrix

int cost(int i, int j) {
  // i is the row, j is the column
  static int weight[rows][cols] = {
    {3,4,1,2,8,6},
    {6,1,8,2,7,4},
    {5,9,3,9,9,5},
    {8,4,1,3,2,6},
    {3,7,2,8,6,4}
  };
  static int memo[rows][cols] = { 0 }; // declare the static memo matrix
  if(memo[i][j]!=0){
		return memo[i][j];
	}
  // If the cost has already been calculated
  //return it.
  // base case (leftmost column)
  if (j == 0) {
  // update the base case path matrix
    path[i][0] = to_string(i);
    return weight[i][0];
  }
  // recursive call - cost(i, j) = weight[i][j] + min_cost(left/up/down-row_index, j-1)
  // all 3 type move, we have col_index - 1
  int left = cost(i, j-1); // move left, row_index doesn't change
  int up = cost((i+rows-1)%rows, j-1); // move up, (row_index + (rows-1)) % rows
  int down = cost((i+1)%rows, j-1); // move down, (row_index + 1) % rows
  
  // find the value of the shortest path through cell (i,j)
  int minCost = left;
  if (up < minCost){
    minCost = up;
  }
  if (down < minCost){
    minCost = down;
  }
  // update the path matrix
  if (minCost == left)
    path[i][j] = path[i][j-1] + to_string(i);
  else if (minCost ==up)
    path[i][j] = path[(i+rows-1)%rows][j-1] + to_string(i);
  else
    path[i][j] = path[(i+1)%rows][j-1] + to_string(i);
  
  memo[i][j] = weight[i][j]+ minCost;
  minCost = memo[i][j];

  return minCost;
}//end of cost function


int main() {
  int ex[rows];
  int rowIndex = 0; // initial the rowIndex
  // get the shortest path out of each cell on the right
  for (int i = 0; i < rows; i++) {
    ex[i] = cost(i, cols - 1); // call recursive function to get the shortestpath for each exit
    // store the row index
    rowIndex = i;
  }
  // now find the smallest of them
  int minCost = ex[0];
  // …some code goes here
  // for-loop
  for( int i=0; i<rows; i++){
        if(ex[i]<minCost){
            minCost=ex[i];
        }
    }
  cout << "The sortest path is of length " << minCost << endl;
  cout << "The rows of the path from left to right are " << path[rowIndex][cols - 1] <<endl;
  
  return 0;
}
