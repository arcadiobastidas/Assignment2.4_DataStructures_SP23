#include <iostream>

using namespace  std;

//Prototypes
const int MAX_SIZE = 8; // Max Size of the array

void getValues(int anArray[], int size); // accepts values for the array by user input
void merge(int theArray[], int first, int mid, int last); //merge function to be called by mergeSort
void displayValues(int anArray[], int size); //displays values entered by the user
void searchValue(int anArray[]); // searches for an specific number withing the array.
int binarySearch(const int anArray[], int first, int last, int target); // search for a value within the array
void mergeSort(int anArray[], int first, int last); // sorts the array un ascending order

int main()
{
    
    int x[MAX_SIZE];//initialize array of integers x;
    int anOption; //initilize option picker for user
    
//begin loop   
do
{
    cout << "\nPlease enter an option from the list below: \n";
    cout << "1 - Enter values for an array of 8 numbers\n";
    cout << "2 - Sort Array in Ascending Order\n";
    cout << "3 - Search for a value within the array\n";
    cout << "4 - Display Array values. \n";
    cout << "5 - Exit Program. \n";
    cout << "Your choice: ";

    cin >> anOption; //get user input for case picker

    switch (anOption)
    {
    case 1:
        getValues(x,MAX_SIZE);
        displayValues(x, MAX_SIZE);
        cout << endl;
        continue;
        
    case 2:
        cin.ignore();
        mergeSort(x,0,MAX_SIZE-1);
        cout << "Array was sorted\n";
        break;
    case 3:
        searchValue(x);
        cout << endl;
        break;

    case 4:displayValues(x, MAX_SIZE);
        cout << endl;
        break;
    case 5:
        cout<< "Good Bye!!!";
        exit(0);
    default:
        cout << "Enter a valid value!";
        break;
        
    }
    
}
while (anOption<=5);
    
      return 0;
}

void getValues(int anArray[], int size)
{
    cout << "Please enter "<< size <<" integer numbers for the array: \n";

    for(int i = 0; i < size; i++)
    {
        cout << "Enter value #"<< i + 1 << " :";
        cin >> anArray[i];
    }
}

void searchValue(int anArray[])
{
    int target;
    cout << "Please enter value to find: ";
    cin >> target;
    if(binarySearch(anArray,0, MAX_SIZE-1,target) > -1)
    {
        cout <<  "Value found at index: " << binarySearch(anArray,0, MAX_SIZE-1,target);
    }
    else
    {
        cout << "Value not found.";
    }
}


void merge(int theArray[], int first, int mid, int last)
{
    int tempArray[MAX_SIZE]; // Temporary array
    // Initialize the local indices to indicate the subarrays
    int first1 = first; // Beginning of first subarray
    int last1 = mid; // End of first subarray
    int first2 = mid + 1; // Beginning of second subarray
    int last2 = last; // End of second subarray
    // While both subarrays are not empty, copy the
    // smaller item into the temporary array
    int index = first1; // Next available location in tempArray
    while ((first1 <= last1) && (first2 <= last2))
    {
        // At this point, tempArray[first..index-1] is in order
        if (theArray[first1] <= theArray[first2])
        {
            tempArray[index] = theArray[first1];
            first1++;
        }
        else
        {
            tempArray[index] = theArray[first2];
            first2++;
        } // end if
        index++;
    } // end while
    // Finish off the first subarray, if necessary
    while (first1 <= last1)
    {
        // At this point, tempArray[first..index-1] is in order
        tempArray[index] = theArray[first1];
        first1++;
        index++;
    } // end while
    // Finish off the second subarray, if necessary
    while (first2 <= last2)
    {
        // At this point, tempArray[first..index-1] is in order
        tempArray[index] = theArray[first2];
        first2++;
        index++;
    } // end for
    // Copy the result back into the original array
    for (index = first; index <= last; index++)
        theArray[index] =tempArray[index];
} // end merge


int binarySearch( const int anArray[], int first, int last, int target)
{
    int index;
    if (first > last)
        index = -1; // target not in original array
    else
    {
        // If target is in anArray,
        // anArray[first] <= target <= anArray[last]
        int mid = first + (last - first) / 2;
        if (target == anArray[mid])
            index = mid; // target found at anArray[mid]
        else if (target < anArray[mid])
            // Point X
            index = binarySearch(anArray, first, mid - 1, target);
        else
            // Point Y
            index = binarySearch(anArray, mid + 1, last, target);
    } // end if
    return index;
} // end binarySearch

void displayValues(int anArray[], int size)
{
    cout << "Array values are: ";
    for(int i = 0; i < size; i++ )
    {
        cout<< anArray[i] << "\t";
    }
}

void mergeSort(int anArray[], int first, int last)
{
    if (first < last)
    {
        // Sort each half
        int mid = first + (last - first) / 2; // Index of midpoint
        // Sort left half theArray[first..mid]
        mergeSort(anArray, first, mid);
        // Sort right half theArray[mid+1..last]
        mergeSort(anArray, mid + 1, last);
        // Merge the two halves
        merge(anArray, first, mid, last);
    } // end if
} // end mergeSort