#include <iostream>
#include <time.h>
#include <random>

using namespace std;

class algo
{
protected:
    
    const int s = 14;
    int arr[14];

public:
    algo()
    {
        cout << endl;
        char selection;
        do
        {
            cout << "\nSelect Algorithm\n" << endl;
            cout << "a. Bubble sort" << endl;
            cout << "b. Selection sort" << endl;
            cout << "c. Insertion sort" << endl;
            cout << "d. Merge sort" << endl;
            cout << "e. Quick sort" << endl;
            cout << "f. Counting sort" << endl;
            cout << "g. -- EXIT --" << endl;
            cin >> selection;
            select(selection);
        } while ((selection != 'g') && (selection = 'G'));
        cout << "\nGoodbye...";
    }

    void select(char n)
    {
        randomize_array();
        cout << "Randomizing array..." << endl;
        for (int i = 0; i < s; i++)
            cout << arr[i] << " ";
        cout << endl;

        if (n == 'a')
            // cout << " a" << endl;
            bubble_sort();
        else if (n == 'b')
            // cout<< " b" << endl;
            selection_sort();

        else if (n == 'c')
            // cout        << " c" << endl;
            insertion_sort();

        else if (n == 'd')
        // cout        << " d" << endl;
        {
            cout << "\nMerge sort\n"
            << endl;
            merge_sort(arr, 0, s - 1);
        }

        else if (n == 'e')
        { // cout        << " e" << endl;
    cout << "\nQuick sort\n"
    << endl;

    quick_sort(arr, 0, s - 1);
}

else if (n == 'f')
        {// cout        << " f" << endl;
    cout<<"\nCount sort\n"  ;
    count_sort(arr,s);
}
else
    return;
}
////////////////////////////////////////////////////////
//
//
//
//    functions
//
//
//
////////////////////////////////////////////////////////
void randomize_array()
{
        std::random_device rd;                         // obtain a random number from hardware
        std::mt19937 gen(rd());                        // seed the generator
        std::uniform_int_distribution<> distr(0, 100); // the range

        for (int i = 0; i < s; i++)
            arr[i] = distr(gen);

        return;
    }

    void swap(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    void merge(int arr[], int p, int q, int r)
    {

        int n1 = q - p + 1;
        int n2 = r - q;

        int L[n1], M[n2];

        for (int i = 0; i < n1; i++)
            L[i] = arr[p + i];
        for (int j = 0; j < n2; j++)
            M[j] = arr[q + 1 + j];

        // Maintain current index of sub-arrays and main array
        int i, j, k;
        i = 0;
        j = 0;
        k = p;

        // Until we reach either end of either L or M, pick larger among
        // elements L and M and place them in the correct position at A[p..r]
        while (i < n1 && j < n2)
        {
            if (L[i] <= M[j])
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = M[j];
                j++;
            }
            k++;
        }

        // When we run out of elements in either L or M,
        // pick up the remaining elements and put in A[p..r]
        while (i < n1)
        {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2)
        {
            arr[k] = M[j];
            j++;
            k++;
        }
        for (int i = 0; i < s; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    void heapify(int arr[], int n, int i) {
    // Find largest among root, left child and right child
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        
        if (left < n && arr[left] > arr[largest])
          largest = left;
      
      if (right < n && arr[right] > arr[largest])
          largest = right;
      
    // Swap and continue heapifying if root is not largest
      if (largest != i) {
          swap(&arr[i], &arr[largest]);
          for (int i = 0; i < s; i++)
              cout << arr[i] << " ";
          cout << endl;
          heapify(arr, n, largest);
      }
  }
  int partition(int array[], int low, int high)
  {

        // select the rightmost element as pivot
    int pivot = array[high];

        // pointer for greater element
    int i = (low - 1);

        // traverse each element of the array
        // compare them with the pivot
    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {

                // if element smaller than pivot is found
                // swap it with the greater element pointed by i
            i++;

                // swap element at i with element at j
            swap(&array[i], &array[j]);
        }
    }

        // swap pivot with the greater element at i
    swap(&array[i + 1], &array[high]);

        // return the partition point
    for (int i = 0; i < s; i++)
        cout << arr[i] << " ";
    cout << endl;
    return (i + 1);
}
////////////////////////////////////////////////////////
//
//
//
//      algorithms
//
//
//
////////////////////////////////////////////////////////
void bubble_sort()
{
    cout << "\nBubble sort\n"
    << endl;

        // loop to access each array element
    for (int step = 0; step < (s - 1); ++step)
    {

            // check if swapping occurs
        int swapped = 0;

            // loop to compare two elements
        for (int i = 0; i < (s - step - 1); ++i)
        {

                // compare two array elements
                // change > to < to sort in descending order
            if (arr[i] > arr[i + 1])
            {

                    // swapping occurs if elements
                    // are not in intended order
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;

                swapped = 1;
                for (int i = 0; i < s; i++)
                    cout << arr[i] << " ";
                cout << endl;
            }
        }

            // no swapping means the array is already sorted
            // so no need of further comparison
        if (swapped == 0)
            break;
    }
    return;
}
void selection_sort()
{
    cout << "\nSelection sort\n"
    << endl;

    for (int step = 0; step < s - 1; step++)
    {
        int min_idx = step;
        for (int i = step + 1; i < s; i++)
        {

                // To sort in descending order, change > to < in this line.
                // Select the minimum element in each loop.
            if (arr[i] < arr[min_idx])
                min_idx = i;
        }

        swap(&arr[min_idx], &arr[step]);
        for (int i = 0; i < s; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return;
}
void insertion_sort()
{
    cout << "\nInsertion sort\n"
    << endl;

    for (int step = 1; step < s; step++)
    {
        int key = arr[step];
        int j = step - 1;

        while (key < arr[j] && j >= 0)
        {
            arr[j + 1] = arr[j];
            --j;
            for (int i = 0; i < s; i++)
                cout << arr[i] << " ";
            cout << endl;
        }
        arr[j + 1] = key;
    }
    return;
}
void merge_sort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
void quick_sort(int arr[], int low, int high)
{

    if (low < high)
    {
            int pi = partition(arr, low, high);

        quick_sort(arr, low, pi - 1);

        quick_sort(arr, pi + 1, high);
    }
}
void count_sort(int arr[],int n)
{
      // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
  
  
  for (int i = n - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]);
      // Heapify root element to get highest element at root again
      heapify(arr, i, 0);
      for (int i = 0; i < s; i++)
        cout << arr[i] << " ";
    cout << endl;
}
}
};

int main()
{
    algo run;
    return 0;
}
