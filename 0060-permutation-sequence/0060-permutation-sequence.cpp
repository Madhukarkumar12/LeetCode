class Solution {
public:
    // void solve(vector<string>& ans,string& s,int index){
    //     // base case needed....
    //      if(index >= s.size()){
    //         ans.push_back(s);
    //         return;
    //      } 

    //      for(int i=index;i<s.size();i++){
    //         swap(s[i],s[index]);
    //         solve(ans,s,index+1);
    //         // backtracking hoga.....
    //         swap(s[i],s[index]);
    //      }
    // }

    string getPermutation(int n, int k) {
        // vector<string>ans;
        // string s;
        // for(int i=1;i<=n;i++){
        //      s.push_back(i+'0');
        // }
        // solve(ans,s,0);
        // // sorting...
        // sort(ans.begin(),ans.end());
        // return ans[k-1];
        string ans="";
        vector<int>members;
        int fact=1;
        for(int i=1;i<n;i++){
            fact=fact * i;
            members.push_back(i);
        }
        members.push_back(n);
        k=k-1;
        // continues chalta rahega but breakage laga die hain....
        while(true){
            ans=ans+to_string(members[k/fact]);
            members.erase(members.begin()+k/fact);
            if(members.size()==0) break;
            k=k % fact;
            fact=fact / members.size();

        }

        return ans;

    }
};