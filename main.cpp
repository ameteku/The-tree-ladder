/*
Name: Michael Ameteku

Date: 9/19/2020

Purpose: the word ladder

pseudo code lv1: find one word with just one non matching letter to the current word.
                 if there is a difference of just one continue to find next difference of 1 letter
                 once word is found, return all words found
*/
#include <iostream>
#include <set>
#include <fstream>

 // header file
#include "filtering.h"


using namespace std;




int main()
{
     //variables
    string file = "Dictionary.txt"; //dictionary file name
    ifstream in;
    string testWord;
    string currentWord;
    string targetWord;
   set<string> Dictionary;//set declaration
   set<string>  :: iterator itr;
    bool found;
    bool notend = true;

while(notend)
{
        //asking user for words
        asking(currentWord, targetWord);


        // loop for pushing all words of same size into  usefulwords dynamic array
        cout<<"running please wait\n";
        in.open(file); // opening the file
        for(;!in.eof();)
        {
            testWord="";
            getline(in, testWord);
            if(testWord.length()==currentWord.length())
            {
                Dictionary.insert(testWord);
            }

        }

        cout<<"word count " <<Dictionary.size()<<endl; //just giving all available words to choose from
        in.close();


       if(!findword(currentWord,targetWord,Dictionary)) // if the tree does not work, it is ended
          cout<<"not found";
}


    return 0;
}
