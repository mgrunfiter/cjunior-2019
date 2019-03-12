#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include "range.h"
#include "profiler.h"

using namespace std;

int main()
{
    {

    Profiler x("all");
    fstream inpute("D:\\develop\\cjunior-2019\\untitled4\\input.txt");

    vector<string> strs;
    map<string, int> words;

    string tmp;
    {
        Profiler t("read");
        while (inpute >> tmp)
        {
            strs.push_back(tmp);
            words[tmp]++;
        }
    }

    vector<pair<string, int>> vec_words;


    for (auto w : words)
    {
        vec_words.push_back(w);
    }

    sort(vec_words.begin(), vec_words.end(), [](auto r, auto l){
      return r.second > l.second;
    });


    for (auto w : Range(vec_words, 10))
//    for (auto w : vec_words)
    {
        cout << w.first << " " << w.second << endl;
    }
    cout << endl;
    }

    return 0;
}
