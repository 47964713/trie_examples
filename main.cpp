// Tim Olson
// 47964713

#include <iostream>
#include "Trie.h"
using namespace std;

int main()
{
    //the following line of code creates an instance of the trie
    Trie t;

    //this line of code instantiates the root node
    struct TrieNode *root = getNode();

    //the following insert statements are adding the string to the trie
    //these are the same words shown in the diagrams in the examples from the article
    t.insert(root, "cat");
    t.insert(root, "car");
    t.insert(root, "cars");
    t.insert(root, "she");
    t.insert(root, "shell");
    t.insert(root, "shear");



    //the following lines call the search function on the trie
    //the first line is the same as the example in the Medium post
    //the following examples show how only exact words that were entered into the trie are found in the search function, no partial words
    t.search(root, "she")? cout << "she: Yes\n" : cout << "she: No\n";
    t.search(root, "shel")? cout << "shel: Yes\n" : cout << "shel: No\n";
    t.search(root, "shell")? cout << "shell: Yes\n" : cout << "shell: No\n";
    t.search(root, "shelf")? cout << "shelf: Yes\n" : cout << "shelf: No\n";
    t.search(root, "shea")? cout << "shea: Yes\n" : cout << "shea: No\n";
    t.search(root, "shear")? cout << "shear: Yes\n" : cout << "shear: No\n";

    t.search(root, "ca")? cout << "ca: Yes\n" : cout << "ca: No\n";
    t.search(root, "car")? cout << "car: Yes\n" : cout << "car: No\n";
    t.search(root, "cars")? cout << "cars: Yes\n" : cout << "cars: No\n";
    t.search(root, "cat")? cout << "cat: Yes\n" : cout << "cat: No\n";
    t.search(root, "cats")? cout << "cats: Yes\n" : cout << "cats: No\n";








    //the following lines of code run the prefix search for auto suggestion as mentioned in the Medium post
    //the example testing the prefix "car" is the second example
    cout << endl << "words with prefix 'ca':" << endl;
    t.printAutoSuggestions(root, "ca");

    cout << endl << "words with prefix 'car':" << endl;
    t.printAutoSuggestions(root, "car");

    cout << endl << "words with prefix 'she':" << endl;
    t.printAutoSuggestions(root, "she");

// The following code is intended to be used as more examples for the uses and behavior of tries
// the examples written above mirror the examples covered in the medium post and so I have chosen to leave these out for the time being
//    t.insert(root, "when");
//    t.insert(root, "where");
//    t.insert(root, "wherever");
//    t.insert(root, "whether");
//    t.insert(root, "whole");
//    t.insert(root, "wholesome");
//    t.search(root, "wh")? cout << "wh: Yes\n" : cout << "wh: No\n";
//    t.search(root, "when")? cout << "when: Yes\n" : cout << "when: No\n";
//    t.search(root, "whe")? cout << "whe: Yes\n" : cout << "whe: No\n";
//    t.search(root, "where")? cout << "where: Yes\n" : cout << "where: No\n";
//    t.search(root, "wheres")? cout << "wheres: Yes\n" : cout << "wheres: No\n";
//    t.search(root, "wherever")? cout << "wherever: Yes\n" : cout << "wherever: No\n";
//    t.search(root, "whole")? cout << "whole: Yes\n" : cout << "whole: No\n";
//    t.search(root, "whale")? cout << "whale: Yes\n" : cout << "whale: No\n";
//    t.search(root, "wholesome")? cout << "wholesome: Yes\n" : cout << "wholesome: No\n";
//    cout << endl << "words with prefix 'wh':" << endl;
//    t.printAutoSuggestions(root, "wh");
//
//    cout << endl << "words with prefix 'who':" << endl;
//    t.printAutoSuggestions(root, "who");
//
//    cout << endl << "words with prefix 'where':" << endl;
//    t.printAutoSuggestions(root, "where");



    return 0;
}