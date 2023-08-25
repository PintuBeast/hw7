#include<iostream>
using namespace std;

int* findMissing(int[], int , int&);

int* findMissing(int arr[], int n , int& resArrSize)
{ 
    int* integerArray = new int[n + 1];
  
  
    for(int i = 0 ; i < (n + 1) ; i++)     //initilizing all elements to zero
    {
        integerArray[i] = 0;
    }
    for(int i = 0 ; i < n ; i++) 
    {
        integerArray[arr[i]] = 1;
    }
    int numMissingIntegers = 0;
    for(int i = 0 ; i < (n+1) ; i++) 
    { 
        if(integerArray[i] == 0)
        {
            numMissingIntegers++;
        }
    }
    resArrSize = numMissingIntegers;
    int* resArr = new int[numMissingIntegers];
    int count = 0;
    for(int i = 0 ; i < (n+1) ; i++) 
    { 
        if(integerArray[i] == 0)
        {
            resArr[count++] = i;
        }
    }
    delete integerArray;

return resArr;

}
int main()
{
    int arrSize;
    cout<<"Please enter the size of the array:\n";
    cin>>arrSize;
    cout<<"Please enter the elements in the array(press return key to enter each element)\n";
    int* arr = new int[arrSize];
    for(int i = 0 ; i < arrSize ; i++)
    {
        cin>>arr[i];
    }
    int resArrSize;
    int* resArr = findMissing(arr, arrSize, resArrSize);
    cout<<"The number of missing integers: "<<resArrSize<<"\n";
    for(int i = 0 ; i < resArrSize ; i++)
    {
        cout<<resArr[i]<<" ";
    } 
    delete arr; 
    return 0;
}