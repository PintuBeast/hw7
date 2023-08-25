#include<iostream>
using namespace std;


int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr);
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);


int* getPosNums1(int* arr, int arrSize, int& outPosArrSize)
{
    outPosArrSize = 0;
    for(int i = 0 ; i < arrSize ; i++)
    {
        if(arr[i] > 0)
        {
            outPosArrSize++;
        }
    }
    int* newArr = new int[outPosArrSize];
    
    int positiveCounter = 0;
    for(int i = 0 ; i < arrSize ; i++)
    {
        if(arr[i] > 0)
        {
            newArr[positiveCounter++] = arr[i];
        }
    }
    return newArr;

}

int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr)
{   
   
    *outPosArrSizePtr = 0;
    for(int i = 0 ; i < arrSize ; i++)
    {
        if(arr[i] > 0)
        {
           (*outPosArrSizePtr)++;
        }
    }
    
    int* newArr = new int[*outPosArrSizePtr];
    
    int positiveCounter = 0;
    for(int i = 0 ; i < arrSize ; i++)
    {
        if(arr[i] > 0)
        {
            newArr[positiveCounter++] = arr[i];
        }
    }
    
    return newArr;
    

}

void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize)
{
    outPosArrSize = 0;
    for(int i = 0 ; i < arrSize ; i++)
    {
        if(arr[i] > 0)
        {
            outPosArrSize++;
        }
    }
    outPosArr = new int[outPosArrSize];
    
    int positiveCounter = 0;
    for(int i = 0 ; i < arrSize ; i++)
    {
        if(arr[i] > 0)
        {
            outPosArr[positiveCounter++] = arr[i];
        }
    }
        

}

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr)
{
    *outPosArrSizePtr = 0;
    for(int i = 0 ; i < arrSize ; i++)
    {
        if(arr[i] > 0)
        {
           *(outPosArrSizePtr)++;
        }
    }
    outPosArrPtr = new int*;
    *outPosArrPtr = new int[*outPosArrSizePtr];
    
    int positiveCounter = 0;
    for(int i = 0 ; i < arrSize ; i++)
    {
        if(arr[i] > 0)
        {
            *(*outPosArrPtr + (positiveCounter++)) = arr[i];
            cout<<*(*outPosArrPtr + (positiveCounter - 1))<<" ";
          
        }
    }    
}

void printArray(int* ,int);

void printArray(int* arr ,int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        cout<<arr[i]<<" ";
    }
}



int main()
{
    const int ARR_SIZE = 6;
    int outPosArrSize;
    
    int arr[]={3,-1,-3,0,6,4};
    int* outArray1 = getPosNums1(arr, ARR_SIZE, outPosArrSize);
    cout<<"########  GetPosNum1 output  #######\n";
    printArray(outArray1,outPosArrSize);
    
    cout<<"\n";

    int* outArray2 = getPosNums2(arr, ARR_SIZE, &outPosArrSize);
    cout<<"########  GetPosNum2 output  #######\n";
    printArray(outArray2,outPosArrSize);

    cout<<"\n";

    int* outPosArr;
    getPosNums3(arr, ARR_SIZE, outPosArr, outPosArrSize);
    cout<<"########  GetPosNum3 output  #######\n";
    printArray(outPosArr,outPosArrSize);

    cout<<"\n";
    
    int* outPosArrPtr;
    cout<<"########  GetPosNum4 output  #######\n";
    getPosNums4(arr, ARR_SIZE, &outPosArrPtr, &outPosArrSize);
    
    

    return 0;
}