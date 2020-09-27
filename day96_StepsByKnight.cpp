/*
 * =====================================================================================
 *
 *       Filename:  day96_StepsByKnight.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/24/2020 09:50:14 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Saurabh Bhartia (SB), s.bhartia.sb98@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

#define SIZE 20

bool check(int i, int j, int N)
{
    if(i >= 0 && i < N && j >= 0 && j < N)
    {
        return true;
    }
    return false;
}

int minSteps(int mat[SIZE][SIZE], int N, int sti, int stj, int edi, int edj){

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
        {
            mat[i][j] = -1;
        }
    }

    mat[sti][stj] = 0;

    queue<pair<int, int>> q;
    q.push({sti, stj});

    while(q.empty() == false){

        auto curr = q.front();

        int i = curr.first;
        int j = curr.second;

        if(check(i-2, j+1, N) == true && mat[i-2][j+1] == -1){
            mat[i-2][j+1] = mat[i][j] + 1;
            q.push({i-2, j+1});
        }

        if(check(i-1, j+2, N) == true && mat[i-1][j+2] == -1){
            mat[i-1][j+2] = mat[i][j] + 1;
            q.push({i-1, j+2});
        }

        if(check(i+1, j+2, N) == true && mat[i+1][j+2] == -1){
            mat[i+1][j+2] = mat[i][j] + 1;
            q.push({i+1, j+2});
        }

        if(check(i+2, j+1, N) == true && mat[i+2][j+1] == -1){
            mat[i+2][j+1] = mat[i][j] + 1;
            q.push({i+2, j+1});
        }

        if(check(i+2, j-1, N) == true && mat[i+2][j-1] == -1){
            mat[i+2][j-1] = mat[i][j] + 1;
            q.push({i+2, j-1});
        }

        if(check(i+1, j-2, N) == true && mat[i+1][j-2] == -1){
            mat[i+1][j-2] = mat[i][j] + 1;
            q.push({i+1, j-2});
        }

        if(check(i-1, j-2, N) == true && mat[i-1][j-2] == -1){
            mat[i-1][j-2] = mat[i][j] + 1;
            q.push({i-1, j-2});
        }

        if(check(i-2, j-1, N) == true && mat[i-2][j-1] == -1){
            mat[i-2][j-1] = mat[i][j] + 1;
            q.push({i-2, j-1});
        }


        q.pop();
    }

    return mat[edi][edj];
}

int main() {
    int T;
    cin >> T;

    while(T--) {
        int N;
        cin >> N;

        int mat[SIZE][SIZE];

        int sti, stj;
        cin >> sti >> stj;

        int edi, edj;
        cin >> edi >> edj;

        cout << minSteps(mat, N, sti-1, stj-1, edi-1, edj-1) << endl;

    }

    return 0;
}

