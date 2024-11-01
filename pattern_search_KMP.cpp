//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        void computelps(string pattern, int M, int lps[])
    {
        lps[0] = 0;
        int i = 1;
        int len = 0;
        while (i < M)
        {
            if (pattern[i] == pattern[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if (len != 0)
                {
                    len = lps[len - 1];
                }
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    vector<int> search(string pattern, string text)
    {
        int M = pattern.size();
        int N = text.size();
        int lps[M];
        computelps(pattern,M,lps);
        vector<int>v;
        int i,j;i=j=0;

        while((N-i)>=(M-j))
        {
            if(pattern[j]==text[i])
            {
                i++,j++;
            }
            if(j==M)
            {
                v.push_back(i+1-j);
                j=lps[j-1];
            }
            else if(i<N && pattern[j]!=text[i])
            {
                if(j!=0)
                {
                    j=lps[j-1];
                }
                else
                {
                    i++;
                }
            }

        }
        return v;
        // code here.
    }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends