#include<iostream>
#include<vector>
using namespace std;

int arraySearch(int[], int, int );

int arraySearch(int arr[], int arrSize,int element)
{

}

int* createArray(string, int&);
int* createArray(string combinedString,int& numIntegers)
{
    int stringLength=combinedString.length();
    int spacePosition=0, numWords=0, wordStartPosition=0,wordEndPosition=0;
    

    for(int i=0;i<stringLength;i++)
    {   
        if(combinedString.find(" ",spacePosition+1)   == string::npos)
        {   
            break;       
        }
        spacePosition=combinedString.find(" ",spacePosition+1);
        spacePosition++;
        numWords++;
    }
    
    int wordCount=numWords;
    numIntegers=wordCount;
    
    int* intArray=new int[wordCount];
    spacePosition=0, wordStartPosition=0,wordEndPosition=0;
    int wordCounter=0;
    for(int i=0;i<stringLength;i++)
    {   wordStartPosition=spacePosition;
        if(combinedString.find(" ",spacePosition+1)   == string::npos)
        {   wordEndPosition=stringLength;
          //  cout<<"a "<<combinedString.substr(wordStartPosition,wordEndPosition-wordStartPosition)<<"\n";
          //  intArray[wordCounter++]=stoi(combinedString.substr(wordStartPosition,wordEndPosition-wordStartPosition));
            break;       
        }
        spacePosition=combinedString.find(" ",spacePosition+1);
        wordEndPosition=spacePosition;
        spacePosition++;
       // cout<<"start:"<<wordStartPosition<<" End:"<<wordEndPosition<<" spacePos: "<<spacePosition<<"\n";
        if(wordEndPosition>wordStartPosition)
        {
           // cout<<"b "<<combinedString.substr(wordStartPosition,wordEndPosition-wordStartPosition)<<"\n";
            intArray[wordCounter++]=stoi(combinedString.substr(wordStartPosition,wordEndPosition-wordStartPosition));
        }
        
    }
  

    return intArray;
}

int vectorSearch(vector<int> , int );

int main()
{   string combinedString="";
     string inputString="";
    cout<<"Please Enter a sequence of positive integers, each in a separate line.\nEnd your input by typing -1.\n";
    while(inputString[0]!='-')
    {
        cin>>inputString;
        if(inputString[0] !='-')
        {
            combinedString+=inputString+" ";
        }
    }
    cout<<"\nThe input is :"<<combinedString;
    int numIntegers;
    int* arr= createArray(combinedString,numIntegers);
    cout<<"The integers are\n";
    for(int i=0;i<numIntegers;i++)
    {
        cout<<arr[i]<<"\n";
    }

    int elementToSearch;

    cout<<"Please enter a number you want to search:\n";
    cin>>elementToSearch;




    return 0;
}