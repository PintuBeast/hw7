#include<iostream>
#include<string>
using namespace std;
const int BIG_A = 65, SMALL_A = 97, SMALL_Z = 97, BIG_Z = 122, NUM_ALPHABETS = 26;
int small[NUM_ALPHABETS], caps[NUM_ALPHABETS];
void initialiseLettersArray();
void initialiseLettersArray()
{
    for(int i = 0 ; i < NUM_ALPHABETS ; i++)
    {
        caps[i] = 0; 
        small[i] = 0;
    }

}

void identifyLetters(string word);
void identifyLetters(string word)
{
    int wordLength = word.length();
   // cout<<"word: "<<word<<"\n";
    int asciVal;
    for(int i = 0 ; i < wordLength ; i++)
    {
        asciVal = (int) word[i];
        if(asciVal >= 97)
        {
            small[asciVal - SMALL_A]++;
        }
        else
        {
            caps[asciVal - SMALL_A]++;

        }

    }
    
}

void printLetters();
void printLetters()
{
    for(int i = 0 ; i < NUM_ALPHABETS ; i++)
    {
        if(( small[i] + caps[i] ) > 0)
        {
            cout<< (small[i] + caps[i]) <<"\t"<< (char) (SMALL_A + i)<< "\n";
        }
    }


}

int parseWords(string line);
int parseWords(string line)
{
    int stringLength = line.length(),wordCount = 0;
    bool isWord = false;
    string word = "";
    
    //cout<<"string Length: "<<stringLength<<"\n";
    for(int i = 0 ; i < stringLength ; i++)
    {   int x = (int) line[i];
        if( (x >= BIG_A && x <= BIG_Z) || (x >= SMALL_A && x <= SMALL_Z) )
        {
            isWord = true;
            word += x;
        }
        else
        {
            if(isWord == true)
            {
                identifyLetters(word);
                wordCount++;
                isWord = false;
                word = "";
            }
        }
        if(i == stringLength-1)
        {      
            if(isWord == true)
            {
                identifyLetters(word);
                wordCount++;
                isWord = false;
                word = "";
            }


        }
    }
    return wordCount;

}

int main()
{
    string line;
    cout<<"Please enter a string:\n";
    getline(cin,line);
    void initialiseLettersArray();
    int wordCount = parseWords(line);
    cout<<wordCount<< " words\n";
    printLetters();
    return 0;
}