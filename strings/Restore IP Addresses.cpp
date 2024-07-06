/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=A0E8YGCAfEE
    Company Tags                : Meta
    Leetcode Link               : https://leetcode.com/problems/restore-ip-addresses/
*/

class Solution {
public:
    int n;
    vector<string> result;
    
    bool isValid(string str) {
        if(str[0] == '0')
            return false;
        
        int val = stoi(str);
        
        return val <= 255;
    }
    
    void solve(string& s, int idx, int part, string curr) {
        if(idx == n && part == 4) {
            result.push_back(curr.substr(0, curr.length()-1));
            return;
        }
        
        if(idx+1 <= n)
            solve(s, idx+1, part+1, curr + s.substr(idx, 1) + ".");
        
        if(idx+2 <= n && isValid(s.substr(idx, 2))) {
            solve(s, idx+2, part+1, curr + s.substr(idx, 2) + ".");
        }
        
        if(idx+3 <= n && isValid(s.substr(idx, 3))) {
            solve(s, idx+3, part+1, curr + s.substr(idx, 3) + ".");
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        result.clear();
        
        n = s.length();
        
        if(n > 12)
          return result;
      
        int part = 0;
        string curr = "";
        
        solve(s, 0, part, curr);
        return result;
        
    }
};

// ----------------------------------------- JAVA CODE ------------------------------------------------------------------------------------//

class Solution {
    public List<String> restoreIpAddresses(String s) {
        List<String> res = new ArrayList<>();
        int n = s.length();

        if (n > 12 || n < 4) {
            return res;
        }

        solve(s, 0, 0, res, "");
        return res;
    }

    public void solve(String s, int idx, int parts, List<String> res, String curr) {
        int n = s.length();

        if (idx == n && parts == 4) {
            // Remove the last dot before adding to the result
            res.add(curr.substring(0, curr.length() - 1));
            return;
        }

        // If there are too many parts or we've gone beyond the length of the string
        if (parts >= 4 || idx >= n) {
            return;
        }

        // Try length 1
        if (idx + 1 <= n) {
            solve(s, idx + 1, parts + 1, res, curr + s.substring(idx, idx + 1) + ".");
        }

        // Try length 2
        if (idx + 2 <= n && isValid(s.substring(idx, idx + 2))) {
            solve(s, idx + 2, parts + 1, res, curr + s.substring(idx, idx + 2) + ".");
        }

        // Try length 3
        if (idx + 3 <= n && isValid(s.substring(idx, idx + 3))) {
            solve(s, idx + 3, parts + 1, res, curr + s.substring(idx, idx + 3) + ".");
        }
    }

    public boolean isValid(String str) {
        if (str.length() > 1 && str.charAt(0) == '0') {
            return false; // Leading zeros are not allowed except for "0"
        }

        int value = Integer.parseInt(str);
        return value >= 0 && value <= 255;
    }
}
