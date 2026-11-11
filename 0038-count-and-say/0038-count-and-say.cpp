class Solution {
public:
    string countAndSay(int n) {
        // string p = to_string(n);
        string str ="1";
        for(int i=1;i<n;i++){
            string str2 ="";
            int count =1;
            for(int j=0;j<str.size();j++){
                if(j+1 == str.size() || str[j]!=str[j+1]){
                str2+=to_string(count);
                str2+=str[j];
                count=1;
                }else{
                    count++;
                }
            }
            str = str2;
        }
        return str;
    }
};