#include<iostream>
#include<vector>
#include<string>
using namespace std;

void arraySearch(int[], int, int );

void arraySearch(int arr[], int arrSize,int element)
{
    string indexList="";
    int indexCount=0;
    for(int i=0;i<arrSize;i++)
    {
        if(arr[i]==element )
        {
            if(indexCount==0)
            {
                indexList += to_string(i+1);
            }
            else
            {
                indexList+=", "+to_string(i+1);

            }
            indexCount++;
        }
    }
    if(indexCount==0)
    {
        cout<<element<<" does not show in the sequence";
    }
    else
    {
        cout<<element<<" shows in line "<<indexList;
    }

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

void vectorSearch(vector<int> , int );
void vectorSearch(vector<int> sequenceVector , int element)
{
    
    
    string indexList="";
    int indexCount=0;

    for(int i=0;i<sequenceVector.size();i++)
    {
        if(sequenceVector[i]==element)
        {
            if(indexCount==0)
            {
                indexList += to_string(i+1);
            }
            else
            {
                indexList+=", "+to_string(i+1);

            }
            indexCount++;
        }
    }

    if(indexCount==0)
    {
        cout<<element<<" does not show in the sequence";
    }
    else
    {
        cout<<element<<" shows in line "<<indexList;
    }

}

void main1()
{  cout<<"\n\n#### METHOD-1 ####\n\n";
    string combinedString="";
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
   // cout<<"\nThe input is :"<<combinedString;
    int numIntegers;
    int* arr= createArray(combinedString,numIntegers);
    int elementToSearch;
    cout<<"\nPlease enter a number you want to search:\n";
    cin>>elementToSearch;
    arraySearch(arr,numIntegers,elementToSearch);

}

void main2()
{
    cout<<"\n\n#### METHOD-2 ####\n\n";
    vector<int> sequenceVector;
    int input=0;
    cout<<"Please Enter a sequence of positive integers, each in a separate line.\nEnd your input by typing -1.\n";
    while(input!=-1)
    {
        cin>>input;
        if(input != -1)
        {
            sequenceVector.push_back(input);
        }
    }
    cout<<"The integers are\n";
    for(int i=0;i<sequenceVector.size();i++)
    {
        cout<<sequenceVector[i]<<"\n";

    }
    int elementToSearch;
    cout<<"\nPlease enter a number you want to search:\n";
    cin>>elementToSearch;
    vectorSearch(sequenceVector,elementToSearch);

}
int main()
{  
    //main1();
    main2();
     
    return 0;
}