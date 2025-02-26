class Solution {
public:
    int modInverse(int a, int mod) {
        for (int i = 1; i < mod; i++) {
            if ((a * i) % mod == 1) return i;
        }
        return 1;
    }

int nCrModpDP(int n, int r, int p) 
{ 
    // The array C is going to store last row of 
    // pascal triangle at the end. And last entry 
    // of last row is nCr 
    int C[r+1]; 
    memset(C, 0, sizeof(C)); 
  
    C[0] = 1; // Top row of Pascal Triangle 
  
    // One by constructs remaining rows of Pascal 
    // Triangle from top to bottom 
    for (int i = 1; i <= n; i++) 
    { 
        // Fill entries of current row using previous 
        // row values 
        for (int j = min(i, r); j > 0; j--) 
  
            // nCj = (n-1)Cj + (n-1)C(j-1); 
            C[j] = (C[j] + C[j-1])%p; 
    } 
    return C[r]; 
} 
  

    int nCrModpLucas(int n, int r, int p) 
{ 
   // Base case 
   if (r==0) 
      return 1; 
  
   // Compute last digits of n and r in base p 
   int ni = n%p, ri = r%p; 
  
   // Compute result for last digits computed above, and 
   // for remaining digits.  Multiply the two results and 
   // compute the result of multiplication in modulo p. 
   return (nCrModpLucas(n/p, r/p, p) * // Last digits of n and r 
           nCrModpDP(ni, ri, p)) % p;  // Remaining digits 
} 

    

    bool hasSameDigits(string s) {
        int n = s.length();
        cout << n << endl;
        n -= 2;
        vector<long long> dp_mod2(n+1,0);
        vector<long long> dp_mod5(n+1,0);
        for(int k = 0;k <= n;k++) {
            dp_mod2[k] = nCrModpLucas(n, k, 2);
            dp_mod5[k] = nCrModpLucas(n, k, 5);
        }
        long long d1 = 0,d2 = 0;
        int size = s.length();
        int j = 0;
        for(int i = 0;i < size-1;i++) {
            int weight = 5 * dp_mod2[j] + 6 * dp_mod5[j];
            d1 += (s[i] - '0') * weight;
            d1 %= 10;
            j++;
        }
        j = 0;
        for(int i = 1;i < size;i++) {
            int weight = 5 * dp_mod2[j] + 6 * dp_mod5[j];
            d2 += (s[i] - '0') * weight;
            d2 %= 10;
            j++;
        }
        return d1 == d2;
    }
};