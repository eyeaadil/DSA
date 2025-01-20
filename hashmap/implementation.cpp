#include<iostream>
#include<map>
#include<unordered_map>

using namespace std;

int main(){
    unordered_map<string, int> mp;

    // Insertion 

    // method 1
    pair<string, int> p = make_pair("adil", 3);
    mp.insert(p);

    // method 2
    pair<string, int> pair2("MD", 2);
    mp.insert(pair2);

    // method 3
    mp["hero"] = 4;

    // mp["hero"] = 6;
    // In the first case, a new entry is created for "hero"
    // In the second case, it updates the initial value

    // Searching
    // method 1
    cout << mp["hero"] << endl;

    // method 2
    cout << mp.at("hero") << endl;

    // With the help of at(), accessing a key that is not present will show an error
    // cout << mp.at("chin-tapak-dam-dam") << endl;
    // But in this case, it creates a new entry and assigns zero to that entry
    cout << mp["chin-tapak-dam-dam"] << endl;

    // size
    cout << mp.size() << endl;

    // check presence of an entry corresponding to any particular key
    cout << mp.count("bro") << endl;

    // erase
    mp.erase("hero");

    cout << mp.size() << endl;

    // accessing all map entries
    for(auto i : mp){
        cout << i.first << " " << i.second << endl;
    }

    // accessing all the elements of the map using an iterator
    unordered_map<string, int>::iterator it = mp.begin();

    while(it != mp.end()){
        cout << it->first << " " << it->second << endl;
        it++;
    }

    return 0;
}
