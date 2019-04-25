#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>
#include<bitset>

using namespace std;

/*
Given a paragraph and a list of banned words, return the most frequent word that is not in the list of banned words. 
It is guaranteed there is at least one word that isn't banned, and that the answer is unique.

Words in the list of banned words are given in lowercase, and free of punctuation. 
Words in the paragraph are not case sensitive. The answer is in lowercase.
*/

/**
 * @param paragraph: 
 * @param banned: 
 * @return: nothing
 */
string mostCommonWord(string &paragraph, vector<string> &banned) {
    // 
    pair<string,int> result("",0);
    if(paragraph.empty()) return result.first;
    
    std::transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower);
    
    for(auto & c : paragraph){
        if(!isLetter(c)){
            c = ' ';
        }
    }
    
    set<string> bannedDict;
    
    for(auto word : banned){
        bannedDict.insert(word);
    }
    
    vector<string> words = split(paragraph);
    

    
    map<string,int>dict;
    
    for(auto item : words){
        if(bannedDict.find(item)==bannedDict.end()){
            dict[item]++;
            if(dict[item]>result.second){
                result.first = item;
                result.second = dict[item];
            }
        }
    }
    
    return result.first;
}


vector<string> split(string paragrah){
    vector<string> result;
        
    stringstream ss;
    
    ss<<paragrah;
    string temp;
    
    while(ss>>temp){
        result.push_back(temp);
    }
    
    return result;
    
}

bool isLetter(char input){
    return input>='a' && input<='z';
}