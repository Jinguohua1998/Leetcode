#include <vector>
#include <iostream>

using namespace std;

int min(int x, int y);

vector<int> PrintMatrix(vector<vector<int>>& matrix) {
    if(matrix.size() == 0)
        return{};
    int rows = matrix.size();
    int cols = matrix[0].size();
    int start = 0;
    vector<int> values;
    for(int start = 0; start < min((cols+1)/2, (rows+1)/2); ++start){
        int maxCol = cols-start-1;
        int maxRow = rows-start-1;
        for(int i = start; i <= maxCol; ++i)
            values.push_back(matrix[start][i]);
        for(int i = start+1; i <= maxRow; ++i)
            values.push_back(matrix[i][maxCol]);
        if(start < maxRow){
            for(int i = maxCol-1; i >= start; --i)
                values.push_back(matrix[maxRow][i]);
        }
        if(start < maxCol){
            for(int i = maxRow-1; i > start; --i)
                values.push_back(matrix[i][start]);
        }
    }
    return values;
}

int min(int x, int y){
    return x < y ? x : y;
}

int main(){
    vector<vector<int>> v{{1,2,3},{1,2,3}};
    cout << v.size() << endl;
    cout << v[0].size();
}


