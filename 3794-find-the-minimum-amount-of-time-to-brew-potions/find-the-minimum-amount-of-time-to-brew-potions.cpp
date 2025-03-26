#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        int m = mana.size();

        // E_prev stores the finish times E[i, j-1] for the previous potion (j-1).
        // Initialize for the first potion (j=0). 
        // For j=0, S[0][0] = 0 since it's the very first task.
        vector<long long> E_prev(n, 0);
        long long current_sum_T_k0 = 0;
        for (int i = 0; i < n; ++i) {
            // Calculate time for wizard i on potion 0
            long long T_i0 = (long long)skill[i] * mana[0]; 
            current_sum_T_k0 += T_i0;
            // E[i][0] = S[0][0] + sum_{k=0 to i} T[k][0] = 0 + current_sum_T_k0
            E_prev[i] = current_sum_T_k0;
        }

        // Iterate through potions from the second one (j=1) to the last one (m-1)
        for (int j = 1; j < m; ++j) {
            
            // Calculate processing times T_kj and their prefix sums P_ij for the current potion j
            // P_ij[k] stores sum_{l=0 to k} T[l][j]
            vector<long long> P_ij(n, 0); 
            long long current_sum_T_kj = 0;
            for (int k = 0; k < n; ++k) {
                // Calculate time for wizard k on potion j
                long long T_kj_val = (long long)skill[k] * mana[j];
                current_sum_T_kj += T_kj_val;
                P_ij[k] = current_sum_T_kj;
            }

            // Calculate S_0j = max_{0 <= i < n} ( E[i][j-1] - P[i-1][j] )
            // Recall P[-1][j] is defined as 0.
            
            // Initialize max_val with the term for i=0: E[0][j-1] - P[-1][j] = E_prev[0] - 0
            long long max_val = E_prev[0]; 
            
            // Calculate the max for i from 1 to n-1
            for (int i = 1; i < n; ++i) {
                // P[i-1][j] is the prefix sum of processing times up to wizard i-1 for potion j.
                long long P_prev_idx_val = P_ij[i-1]; 
                long long current_val = E_prev[i] - P_prev_idx_val;
                max_val = max(max_val, current_val);
            }

            // The earliest start time for wizard 0 on potion j
            long long S_0j = max_val;
            
            // Calculate E_curr[i] = E[i][j] for the current potion j using E[i][j] = S[0][j] + P[i][j]
            // E_curr stores the finish times for the current potion j.
            vector<long long> E_curr(n, 0);
            for (int i = 0; i < n; ++i) {
                E_curr[i] = S_0j + P_ij[i];
            }

            // Update E_prev to E_curr for the next iteration (next potion)
            E_prev = E_curr;
        }

        // The final answer is the finish time of the last wizard (n-1) on the last potion (m-1).
        // This value is stored in E_prev[n-1] after the loop completes.
        return E_prev[n-1];
    }
};