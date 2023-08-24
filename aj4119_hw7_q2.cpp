#include<iostream>
#include<string>
using namespace std;


const int BIG_A=65,SMALL_A=97, SMALL_Z=97,BIG_Z=122, NUM_ALPHABETS=26;
int small[NUM_ALPHABETS], caps[NUM_ALPHABETS];

void getLetterDistribution(string line, int letterArray[]);


bool isAnagram(string line1, string line2);
bool isAnagram(string line1, string line2)
{
    bool isAnagram=true;
    int letterArray1[NUM_ALPHABETS],letterArray2[NUM_ALPHABETS];
    getLetterDistribution(line1,letterArray1);
    getLetterDistribution(line2,letterArray2);

    for(int i =0;i<NUM_ALPHABETS;i++)
    {
        if(letterArray1[i]!=letterArray2[i])
        {
            isAnagram=false;
            break;
        }

    }
    return isAnagram;
}
void initialiseLettersArray();
void identifyLetters(string word);

void parseWords(string line);

void getLetterDistribution(string line, int letterArray[])
{
    initialiseLettersArray();
    parseWords(line);
    for(int i=0;i<NUM_ALPHABETS;i++)
    {
        letterArray[i]=small[i]+caps[i];
    }

}





void initialiseLettersArray()
{
    for(int i=0;i<NUM_ALPHABETS;i++)
    {
        caps[i]=0; 
        small[i]=0;
    }

}


void identifyLetters(string word)
{
    int wordLength= word.length();
    int asciVal;
    for(int i=0;i<wordLength;i++)
    {
        asciVal = (int) word[i];
        if(asciVal>=97)
        {
            small[asciVal-SMALL_A]++;
        }
        else
        {
            caps[asciVal-SMALL_A]++;

        }

    }
    
}



void parseWords(string line)
{
    int stringLength= line.length(),wordCount=0;
    bool isWord=false;
    string word="";
    
    //cout<<"string Length: "<<stringLength<<"\n";
    for(int i=0;i<stringLength;i++)
    {   int x = (int) line[i];
        if( (x >= BIG_A && x <= BIG_Z) || (x >= SMALL_A && x <= SMALL_Z) )
        {
            isWord=true;
            word+=x;
        }
        else
        {
            if(isWord == true)
            {
                identifyLetters(word);
                wordCount++;
                isWord=false;
                word="";
            }
        }
        if(i == stringLength-1)
        {      
            if(isWord == true)
            {
                identifyLetters(word);
                wordCount++;
                isWord=false;
                word="";
            }


        }
    }
    

}




int main()
{
    string line1,line2;
    cout<<"Please enter string-1:\n";
    getline(cin,line1);
    cout<<"Please enter string-2:\n";
    getline(cin,line2);
    bool isAna ;
    isAna = isAnagram(line1,line2);
    if(isAna == true)
    {
        cout<<"The two strings are Anagrams.";
    }
    else
    {
        cout<<"The two strings are Not Anagrams.";

    }

    return 0;
}