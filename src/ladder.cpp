#include "ladder.h"

using namespace std;
void error(string word1, string word2, string msg){
    cout << word1 << word2 << msg<< endl;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d){  
    return is_adjacent(str1, str2) == true && d==1;
}

bool is_adjacent(const string& word1, const string& word2){
    int differ_count = 0;
    if ( word1.length() == word2.length()){
        for (int i = 0; i<word1.length(); i++){
            if (word1[i] != word2[i]){
                differ_count++;
                }
        }
        return differ_count <=1;
    }
    int smaller_len = min(word1.length(), word2.length());
    int bigger_len = max(word1.length(), word2.length());

    string small;
    string big;

    if (word1.length() == smaller_len){
        small = word1;
        big = word2;
    }
    else{
        big = word1;
        small = word2;
    }

    int i=0;
    int j=0;
    while (i < smaller_len && j < bigger_len){
        if (small[i] != big[j]){
            differ_count++;
            ++j;
        }
        else{
            i++;
            j++;
        }
    }

    return differ_count<=1;
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list){
    queue<vector<string>> ladder_queue;
    ladder_queue.push({begin_word});
    set<string> visited;
    visited.insert(begin_word);
    while (!ladder_queue.empty()){
        vector<string> ladder = ladder_queue.front();
        ladder_queue.pop();
        string last_word = ladder.back();
        for (string word : word_list){
            if (is_adjacent(last_word, word)){
                if (visited.find(word) == visited.end()){
                    visited.insert(word);
                    vector<string> new_ladder = ladder;
                    new_ladder.push_back(word);
                    if (word==end_word){
                        return new_ladder;
                    }
                    ladder_queue.push(new_ladder);
                }
            }
        }
    }
    vector<string> null_ladder = {};
    return null_ladder;
}

void load_words(set<string> & word_list, const string& file_name){
    ifstream file(file_name);
    if (!file){
        throw runtime_error("Unable to find input file");
    }
    string word;
    while(file >> word){
        word_list.insert(word);
    }

}

void print_word_ladder(const vector<string>& ladder){
    if(ladder.empty()){
        cout << "Not found"<< endl;
        return;
    }
    for (string word: ladder){
        cout << word<< " ";
    }
    cout << endl;
}

void verify_word_ladder(){
    set<string> word_list;
    load_words(word_list, "src/words.txt");
    cout << generate_word_ladder("cat", "dog", word_list).size()<<endl;
}