
//318878956 - MAYA DAHAN
//312276215 - AVIV SOFER

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

double avgCompar1 = 0, avgCompar2 = 0, avgCompar3 = 0;

// First function - Search1 (O(n))
int Search1(int V[], int m, int x) {
    for (int i = 0; i < m; ++i)
    {
        avgCompar1++;
        if (V[i] == x)
        {
            return i; // Return the index
        }
        if (V[i] == 0)
        {
            return -1; // x not found
        }
    }
}

// Second function - Search2 (O(logm))
int Search2(int V[], int m, int x) {
    int left = 0, right = m - 1;
    while (left <= right)
    {
        avgCompar2++;
        int mid = (right + left) / 2;
        if (V[mid] == x) {
            return mid; // Return the index
        }
        if (V[mid] < x) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1; // x not found
}

// A third function - Search3 (O(logn))
int Search3(int V[], int m, int x) {

    // search the first zero
    int firstZero = 1;
    while (firstZero < m && V[firstZero] < x && V[firstZero] != 0)
    {
        firstZero *= 2;
    }

    // find x in range
    int left = 0, right = firstZero - 1;
    while (left <= right)
    {
        avgCompar3++;
        int mid = (right + left) / 2;
        if (V[mid] == x) {
            return mid; // Return the index
        }
        else if (V[mid] < x) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1; // x not found
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


int main() {
    srand(time(NULL));
    const int m = 1000; // Array size

    // Run the three search algorithms and measure comparisons
    const int numTests = 200;

    for (int test = 0; test < numTests; ++test)
    {
        int* arr = new int[m];
        const int n = rand() % 101 + 150; // Random n in range [150, 250]

        for (int i = 0; i < n; ++i)
        {
            arr[i] = rand() + 1; // Random not zero
        }

        for (int i = n; i < m; ++i)
        {
            arr[i] = 0;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[i] < arr[j])
                {
                    swap(arr[i], arr[j]);
                }
            }
        }

        int x = rand() + 1; // Random not zero

        Search1(arr, m, x);
        Search2(arr, m, x);
        Search3(arr, m, x);
    }

    // Calculate average indices
    avgCompar1 /= numTests;
    avgCompar2 /= numTests;
    avgCompar3 /= numTests;

    // Print results
    cout << "150 <= n <= 250\n";
    cout << "Search1: " << avgCompar1 << endl;
    cout << "Search2: " << avgCompar2 << endl;
    cout << "Search3: " << avgCompar3 << endl;

    return 0;
}
