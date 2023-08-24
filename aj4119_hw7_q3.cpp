#include<iostream>
using namespace std;

void oddsKeepEvensFlip(int arr[], int arrSize);
const int TWO=2, ONE=1;
void printArray(int arr[],  int arrSize);
void oddsKeepEvensFlip(int arr[], int arrSize)
{
    int *oddArray=new int[arrSize];
    int *evenArray=new int[arrSize];
    for(int i=0;i<arrSize;i++)
    {
        oddArray[i]=TWO;
        evenArray[i]=ONE;
    }
    int oddCount=0,evenCount=0;
    for(int i=0;i<arrSize;i++)
    { 
        if(arr[i] % 2 == 0)
        {
            evenArray[evenCount++]=arr[i];
        }
        else
        {
            oddArray[oddCount++]=arr[i];

        }
    }


    for(int i=0;i<arrSize;i++)
    {
        if(i<oddCount)
        { 
            if(oddArray[i] % 2 != 0)
            {
                arr[i]=oddArray[i];
            }

        }
        else 
        {
            if(evenArray[arrSize-i-1] % 2 == 0)
            {
                arr[i]=evenArray[arrSize-i-1];
            }
        }
    }
    
}


int main()
{
    int arrSize;
    cout<<"Enter the array Size: ";
    cin>>arrSize;
    int* arr=new int[arrSize];
    cout<<"Enter the array of integers: \n";
    for(int i=0;i<arrSize;i++)
    {
        cin>>arr[i];
    }
    oddsKeepEvensFlip(arr,arrSize);
    cout<<"\nThe array after processing\n";
        for(int i=0;i<arrSize;i++)
    {
        cout<<arr[i]<<" ";
    }


    return 0;
}