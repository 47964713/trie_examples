// Tim Olson
// 47964713

//The following website were used to aid writing the implementation of the trie
//Tries and Auto-completion, Geeks for Geeks -- https://www.geeksforgeeks.org/auto-complete-feature-using-trie/
//Advantages of Trie, Geeks for Geeks -- https://www.geeksforgeeks.org/advantages-trie-data-structure/
//Applications of Trie, Brilliant Learning -- https://brilliant.org/wiki/tries/#applications
//Trie | (Insert and Search), Geeks for Geeks -- https://www.geeksforgeeks.org/trie-insert-and-search/

using namespace std;


// Converts key current character into index
// use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

const int alphabet = 26;

// trie node
struct TrieNode
{
    struct TrieNode *children[alphabet];

    // this boolean is a flag indicating the end of a word
    bool isWordEnd;
};


// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
    struct TrieNode *pNode = new TrieNode;
    pNode->isWordEnd = false;

    for (int i = 0; i < alphabet; i++)
        pNode->children[i] = NULL;

    return pNode;
}

class Trie {

public:

    Trie() = default;

    // If not present, inserts key into trie. If the key is prefix of trie node, just marks leaf node
    void insert(struct TrieNode *root, const string key) {
        struct TrieNode *trav = root;

        for (int level = 0; level < key.length(); level++) {
            int index = CHAR_TO_INDEX(key[level]);
            if (!trav->children[index])
                trav->children[index] = getNode();

            trav = trav->children[index];
        }

        // mark last node as end of word
        trav->isWordEnd = true;
    }

    // Returns true if key is found in trie, else false
    bool search(struct TrieNode *root, const string key) {
        struct TrieNode *trav = root;
        int length = key.length();

        for (int level = 0; level < length; level++) {
            int index = CHAR_TO_INDEX(key[level]);

            if (!trav->children[index])
                return false;

            trav = trav->children[index];
        }

        return (trav != NULL && trav->isWordEnd);
    }

// Returns 0 if current node has a child, If all children are NULL, return 1.
    bool isLastNode(struct TrieNode *root) {
        for (int i = 0; i < alphabet; i++)
            if (root->children[i])
                return 0;
        return 1;
    }

    // Recursive function to print auto-suggestions for given node.
    void suggestionsRec(struct TrieNode *root, string currPrefix) {
        // found a string in Trie with the given prefix
        if (root->isWordEnd) {
            cout << currPrefix;
            cout << endl;
        }

        // All children struct node pointers are NULL
        if (isLastNode(root))
            return;

        for (int i = 0; i < alphabet; i++) {
            if (root->children[i]) {
                // append current character to currPrefix string
                currPrefix.push_back(97 + i);

                // recur over the rest
                suggestionsRec(root->children[i], currPrefix);
                // remove last character
                currPrefix.pop_back();
            }
        }
    }

    // print suggestions for given query prefix.
    int printAutoSuggestions(TrieNode *root, const string query) {
        struct TrieNode *trav = root;

        // Check if prefix is present and find the node (of last level) with last character of given string.
        int level;
        int n = query.length();
        for (level = 0; level < n; level++) {
            int index = CHAR_TO_INDEX(query[level]);

            // no string in the Trie has this prefix
            if (!trav->children[index])
                return 0;

            trav = trav->children[index];
        }

        // If prefix is present as a word.
        bool isWord = (trav->isWordEnd == true);

        // If prefix is last node of tree (has no children)
        bool isLast = isLastNode(trav);

        // If prefix is present as a word, but there is no subtree below the last matching node.
        if (isWord && isLast) {
            cout << query << endl;
            return -1;
        }

        //Looking for words past the last node
        if (!isLast) {
            string prefix = query;
            suggestionsRec(trav, prefix);
            return 1;
        }
    }


};
