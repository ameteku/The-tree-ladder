
#include "filtering.h"

//function for asking user for words to be used
//precond: prompt for first word and second word with same length
//user entered word is passed to main program for processing
void asking( string &currentWord, string & targetWord)
{
    bool samelength =false;
    cout<< "Enter the original word\n";
    cin>>currentWord;
    while(samelength!=true)
    {
        cout<<"Enter the desired word of same length\n";
        cin>>targetWord;

        if(currentWord.length()==targetWord.length() && currentWord!= targetWord)
        samelength=true;
        else
        {
            cout<<"Not same length\n";
        };

    };

};

//function for finding filtering all the possible words and bringing out the word ladder
//precond: the target word, dictionary set and starting words are passed
//postcond: prints out the tree or returns false if no tree found
bool findword(string targetword, string start, set<string> & dict)
{
    //var declaration
    string currentword = "";
    int numOfFalse=0;
    bool found;
    set<string> :: iterator itr= dict.begin();

    //base case
    if(targetword==start)
    {
        cout<<start<<endl; //print the last word found
        return true;
    }


       for(;itr!=dict.end(); itr++)
        {
            numOfFalse=0;
            currentword=*itr; //set current word to the word in iterator

            for(int counter=0; counter<start.length() && numOfFalse<2; counter++) //loop for checking difference in letters
            {
                if(currentword[counter]!=start[counter])
                    numOfFalse++;
            }
            //cout<<currentword<<" "<<numOfFalse<<endl;

            if(numOfFalse==1) //checking if only one letter is different
            {

                dict.erase(start); //word is one letter different, remomve from library


                found= findword(targetword, currentword,dict); //pass the word as new starting word
                if(found) //if function returns tru for found, wor dis printed out
                {
                    cout<<start<<endl;
                    return true;
                }
            }
        }

        if(!found)
        {
            return false;
        }

}



