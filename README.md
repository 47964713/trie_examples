
### Tim Olson
# Trie Example Code



This project reflects sample code and example code used in the research and exploration of tries written about in my Medium post titled "A Dive Into Tries", the link to the post will be linked in this ReadMe once the article is published. The program itself explores an option in the implementation of a trie. There are many different ways to implement such a trie, I found this one the easiest to follow when first getting to know about the data structure

In this implementation, there are three main functions to begin experimenting and exploring how tries work

1. Insert: this function takes the root node and a string as paramters. Functionally this method takes the string parameter and adds each character of the string into the trie. 
It then flags the last node visited (corresponding to the last character in the string) by setting the boolean variable (EndOfWord) to true
   
2. Search: this function takes the root and a string query as parameters. This function traverses the trie one character at a time. If the traversal is successful this means that the traversal is able to reach the last character of the string, and the final node visited 
has also been marked as true in the boolean variable EndOfWord. The result of this function is a true/false boolean
   
3. printAutoSuggestions: this function also takes the root node and a string as parameters. The string parameter should be a prefix so that the function can return all words that begin with the queried string.
This function utilizes two other functions implemented in Trie.h to traverse through the trie and find all of the words containing the prefix exhaustively. The result of this function is a list of all words that contain the queried prefix
   
## Usage
This code is intended to be used as a reference and hands-on guide to understanding tries for someone who has never worked with this data structure before. The code in the `Trie.h` file does not need to be changed in order to learn more about the data strucutre, 
but I encourage you to look at the examples and try to visualize how everything is working. Change the words in the inserts, searches, and prefix search if you wish, or add on to them to see how tries may behave differently when more data is added to the set. Additional examples and test code is written in main but commented out at the moment, feel free to uncomment the code if you wish to add more, it is commented out at the moment to reflect only the examples that I went over in the Medium post.




### Work Cited for Code:
* Tries and Auto-completion, Geeks for Geeks -- https://www.geeksforgeeks.org/auto-complete-feature-using-trie/

* Advantages of Trie, Geeks for Geeks -- https://www.geeksforgeeks.org/advantages-trie-data-structure/

* Applications of Trie, Brilliant Learning -- https://brilliant.org/wiki/tries/#applications
  
* Trie | (Insert and Search), Geeks for Geeks -- https://www.geeksforgeeks.org/trie-insert-and-search/