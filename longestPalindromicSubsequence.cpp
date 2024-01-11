class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size() ; 
        int n2 = text2.size() ;
       // vector <vector <int>> dp(n1+1 , vector<int>(n2 +1,0));
        //return solve(n1-1,n2-1,text1,text2,dp) ;
        vector <int> prev(n2+1,0) , curr(n2+1,0) ;
        for(int i=0 ; i<n1 ; i++) 
         prev[0] =0;
        // for(int i=0;i<n2;i++)
        //   dp[0][i] = 0;

        for(int ind1 =1 ; ind1 <= n1 ;ind1 ++ ){
            for(int ind2 = 1; ind2 <= n2 ;ind2 ++){
                if(text1[ind1-1]==text2[ind2-1]) curr[ind2] =1+prev[ind2-1] ;
                else
               curr[ind2] = 0+max(prev[ind2],curr[ind2-1]);
            }
            prev = curr;
        }
        return prev[n2] ;
    }
    int longestPalindromeSubseq(string s) {
        string r = "" ;
        for(int i=s.size()-1 ;i>=0 ; i--)
          r += s[i] ;
        
         return longestCommonSubsequence(s,r) ;

    }
};
