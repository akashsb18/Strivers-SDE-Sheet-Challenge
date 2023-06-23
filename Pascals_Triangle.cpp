#include <bits/stdc++.h>

vector<vector<long long int>> printPascal(int n) 

{

        vector<vector<long long>> ans; 

        for(int i = 0; i < n; i++) { 
            vector<long long> temp(i+1); 

            temp[0] = 1;
            for(int j = 1; j < i; j++) {
                temp[j] = ans[i-1][j-1] + ans[i-1][j];
            }
            if(i != 0) {
                temp[i] = 1;
            }

            ans.push_back(temp);
        }

        return ans;

}