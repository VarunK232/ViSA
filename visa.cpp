#include <bits/stdc++.h>
#include <time.h>
#include <random>

using namespace std;

class algo
{
protected:
    int arr[10];
    const int s = 10;

public:
    algo()
    {
        cout << endl;
        char selection;
        do
        {
            cout << "\nSelect Algorithm\n"
                 << endl;
            cout << "a. Bubble sort" << endl;
            cout << "b. Selection sort" << endl;
            cout << "c. Insertion sort" << endl;
            cout << "d. Merge sort" << endl;
            cout << "e. Quicksort" << endl;
            cout << "f. Countingsort" << endl;
            cout << "g. -- EXIT --sort" << endl;
            cin >> selection;
            select(selection);
        } while ((selection != 'g') && (selection = 'G'));
        cout << "\nGoodbye...";
    }

    void select(char n)
    {
        randomize_array();
        cout << "Randomizing array..." << endl;
        for (int i = 0; i < 10; i++)
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
            merge_sort();

        else if (n == 'e')
            // cout        << " e" << endl;
            quick_sort();
        else if (n == 'f')
            // cout        << " f" << endl;
            count_sort();
        else
            return;
    }

    void randomize_array()
    {
        std::random_device rd;                         // obtain a random number from hardware
        std::mt19937 gen(rd());                        // seed the generator
        std::uniform_int_distribution<> distr(0, 100); // the range

        for (int i = 0; i < 10; i++)
            arr[i] = distr(gen);

        return;
    }

    void swap(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    void bubble_sort()
    {
        cout << "\nBubble\n"
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
                    for (int i = 0; i < 10; i++)
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
        cout << "\nSelection\n"
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
            for (int i = 0; i < 10; i++)
                cout << arr[i] << " ";
            cout << endl;
        }
        return;
    }
    void insertion_sort()
    {
        cout << "\nInsertion\n"
             << endl;

        for (int step = 1; step < s; step++)
        {
            int key = arr[step];
            int j = step - 1;

            // Compare key with each element on the left of it until an element smaller than
            // it is found.
            // For descending order, change key<array[j] to key>array[j].
            while (key < arr[j] && j >= 0)
            {
                arr[j + 1] = arr[j];
                --j;
                for (int i = 0; i < 10; i++)
                    cout << arr[i] << " ";
                cout << endl;
            }
            arr[j + 1] = key;
        }
        return;
    }
    void merge_sort()
    {
        cout << "\nMerge\n"
             << endl;

        return;
    }
    void quick_sort()
    {
        cout << "\nQuick\n"
             << endl;

        return;
    }
    void count_sort()
    {
        cout << "\nCounting\n"
             << endl;
        return;
    }
};

int main()
{
    algo run;
    return 0;
}