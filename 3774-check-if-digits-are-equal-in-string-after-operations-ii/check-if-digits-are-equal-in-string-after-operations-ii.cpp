class Solution {
public:

int nCrModpDP(int n, int r, int p) 
{ 
    int C[r+1]; 
    memset(C, 0, sizeof(C)); 
  
    C[0] = 1;

    for (int i = 1; i <= n; i++) 
    { 
        for (int j = min(i, r); j > 0; j--) 
  
            C[j] = (C[j] + C[j-1])%p; 
    } 
    return C[r]; 
} 
  

    int nCrModpLucas(int n, int r, int p) 
{ 
   if (r==0) 
      return 1; 
  
   int ni = n%p, ri = r%p; 
   return (nCrModpLucas(n/p, r/p, p) * 
           nCrModpDP(ni, ri, p)) % p; 
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