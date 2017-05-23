#include<vector>
#include<unordered_map>
#include<string>

class Solution {
private:
        static const char* charset;
        static const char* HOST_NAME;
        static const int idIndex;
        int id = 0;
        std::unordered_map<std::string, std::string> longUrlShortUrl;
        std::vector<std::string> longUrls;

        std::string convetToBase62(int num){
                std::string base62 = "";
                while(num>0){
                        base62 += charset[num%62];
                        num /= 62;
                }
                return base62;
        }
        int convertBase62ToDecimal(std::string base62){
                int num = 0;
                for(int i=0; i<base62.length(); i++){
                        if(base62[i]<=57){
                                num = num*62 + base62[i] + 4;
                        }
                        else if(base62[i]<=90){
                                num = num*62 + base62[i] - 39;
                        }
                        else{
                                num = num*62 + base62[i] - 97;
                        }
                }
                return num;
        }
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(longUrlShortUrl.count(longUrl)){
                        return longUrlShortUrl[longUrl];
                }
                longUrls.push_back(longUrl);
                std::string shortUrl = HOST_NAME;
                shortUrl += convetToBase62(id++);
                longUrlShortUrl[longUrl] = shortUrl;
                return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        std::string base62 = shortUrl.substr(idIndex);
                int id = convertBase62ToDecimal(base62);
                if(id < longUrls.size()){
                        return longUrls[id];
                }
                return "";
    }
};

const char* Solution::charset = "abcdefghijklmnopqrsturwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
const char* Solution::HOST_NAME = "http://tinyurl.com/";
const int Solution::idIndex = 19;
