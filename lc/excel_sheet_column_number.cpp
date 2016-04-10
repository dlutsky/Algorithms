#include<string>

int titleToNumber(std::string s) {
	int num = 0;
	for(int i=0; i<s.size(); i++){
		num = num*26+s[i]-'A'+1;
	}
	return num;
}
