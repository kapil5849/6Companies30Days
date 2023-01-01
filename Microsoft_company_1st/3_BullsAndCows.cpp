// 299. Bulls and Cows...


class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        int cntb=0,cntc=0;
        map<int,int> mpp1;
        map<int,int> mpp2;
        for(int i=0;i<n;i++){
            if(secret[i]==guess[i]){
                cntb++;
            }
            else{
                mpp1[secret[i]-'0']++;
                mpp2[guess[i]-'0']++;
            }
        }
        for(auto it:mpp1){
            if(mpp2.find(it.first)!=mpp2.end()){
                cntc+=min(it.second,mpp2[it.first]);
            }
        }
        return to_string(cntb)+"A"+to_string(cntc)+"B";
    }
};
