#include<string>
#include<string.h>

std::string minWindow(std::string s, std::string t) {
	bool mp[128];
	memset(mp, 0, sizeof(mp));
	int count[128];
	memset(count, 0, sizeof(count));
	for(int i=0; i<t.size(); i++){
		mp[t[i]]=1;
		count[t[i]]++;
	}
	int i=0, j=0, c=0;
	int minStart=0, minLen=s.size();
	for(j=0; j<s.size(); j++){
		if(mp[s[j]]){
			if(count[s[j]]>0)
				c++;
			count[s[j]]--;
		}
		if(c==t.size())
			break;
	}
	while(i<j&&(!mp[s[i]]||count[s[i]]<0)){
		if(mp[s[i]])
			count[s[i]]++;
		i++;
	}
	if(c==t.size()){
		minLen=j-i+1;
		minStart=i;
		j++;
	}
	else
		return "";
	while(j<s.size()){
		if(mp[s[j]]){
			count[s[j]]--;
		}
		while(i<j&&(!mp[s[i]]||count[s[i]]<0)){
			if(mp[s[i]])
				count[s[i]]++;
			i++;
		}
		if(j-i<minLen){
			minLen=j-i+1;
			minStart=i;
		}
		j++;
	}
	return s.substr(minStart, minLen);
}
