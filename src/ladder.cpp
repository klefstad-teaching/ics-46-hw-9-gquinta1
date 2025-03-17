#include "ladder.h"

using namespace std;
void error(string word1, string word2, string msg){
    cout << word1 << word2 << msg<< endl;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d){  
    return is_adjacent == true && d==1;
}

bool is_adjacent(const string& word1, const string& word2){
    int differ_count = 0;
    if ( word1.length() == word2.length()){
        for (int i = 0; i<length; i++){
            if (word1[i] != word2[i]){
                differ_count++;
                }
        }
        return differ_count <=1;
    }

    if (word1.length != word2.length){
        differ_count++;
    }
    return differ_count<=1;
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list){
    vector<string> ladder_queue;
    ladder_queue.push(begin_word);
    set<string> visited;
    visited.insert(begin_word);
    while (!ladder_queue.empty()){
        ladder = ladder_queue.pop_front();
        last_word = ladder.back();
        for (string word : word_list){
            if (is_adjacent(end_word, word)){
                if (visited.find(word) != visited.end()){
                    visited.insert(word);
                    new_ladder = ladder;
                    new_ladder.push_back(word);
                    if (word==end_word){
                        return new_ladder;
                    }
                    ladder_queue.push(new_ladder);
                }
            }
        }
    }
    vector<string> null_ladder;
    return null_ladder;
}

void load_words(set<string> & word_list, const string& file_name){


}

void print_word_ladder(const vector<string>& ladder){
    for (string word: ladder){
        cout << word<< "words.txt";
    }
}

void verify_word_ladder(){
    set<string> word_list;
    load_words(word_list, )
}