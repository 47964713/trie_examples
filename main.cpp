#include <iostream>
#include <iostream>
#include <string>
#include "Trie.h"
using namespace std;
int main()
{
    Trie t;

    struct TrieNode *root = getNode();

    t.insert(root, "the");
    t.insert(root, "these");
    t.insert(root, "therefore");

    t.insert(root, "man");
    t.insert(root, "mantle");
    t.insert(root, "mall");

    t.search(root, "the")? cout << "Yes\n" : cout << "No\n";
    t.search(root, "there")? cout << "Yes\n" : cout << "No\n";
    t.search(root, "mant")? cout << "Yes\n" : cout << "No\n";
    t.search(root, "mantl")? cout << "Yes\n" : cout << "No\n";

    t.printAutoSuggestions(root, "the");
    t.printAutoSuggestions(root, "man");
    t.printAutoSuggestions(root, "an");

    return 0;
}