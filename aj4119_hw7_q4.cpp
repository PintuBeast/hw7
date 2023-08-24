#include<iostream>
#include<string>
using namespace std;

string* createWordsArray(string sentence, int& outWordsArraySize);
string* createWordsArray(string sentence, int& outWordsArraySize)
{  
    int stringLength=sentence.length();
    int spacePosition=0, numWords=0, wordStartPosition=0,wordEndPosition=0;
    

    for(int i=0;i<stringLength;i++)
    {   
        if(sentence.find(" ",spacePosition+1)   == string::npos)
        {   numWords++;
            break;       
        }
        spacePosition=sentence.find(" ",spacePosition+1);
        spacePosition++;
        numWords++;
    }
    
    int wordCount=numWords;
    outWordsArraySize=numWords;
    string* stringArray=new string[wordCount];
    spacePosition=0, wordStartPosition=0,wordEndPosition=0;
    int wordCounter=0;
    for(int i=0;i<stringLength;i++)
    {   wordStartPosition=spacePosition;
        if(sentence.find(" ",spacePosition+1)   == string::npos)
        {   wordEndPosition=stringLength;
           // cout<<"\n"<<sentence.substr(wordStartPosition,wordEndPosition-wordStartPosition)<<"\n";
            stringArray[wordCounter++]=sentence.substr(wordStartPosition,wordEndPosition-wordStartPosition);
            break;       
        }
        spacePosition=sentence.find(" ",spacePosition+1);
        wordEndPosition=spacePosition;
        spacePosition++;
       // cout<<"start:"<<wordStartPosition<<" End:"<<wordEndPosition<<" spacePos: "<<spacePosition<<"\n";
        if(wordEndPosition>wordStartPosition)
        {
            //cout<<"\n"<<sentence.substr(wordStartPosition,wordEndPosition-wordStartPosition)<<"\n";
            stringArray[wordCounter++]=sentence.substr(wordStartPosition,wordEndPosition-wordStartPosition);
        }
        
    }
  



    return stringArray;
}



int main()
{   string line;
    cout<<"Please enter a string:\n";
    getline(cin,line);
    int outWordsArraySize;
    string* wordArray = createWordsArray(line,outWordsArraySize);
    cout<<"The number of words is: "<<outWordsArraySize<<"\n";    
    
    for(int i=0;i<outWordsArraySize;i++)
    {
        cout<<wordArray[i]<<"\n";
    } 
    return 0;
}