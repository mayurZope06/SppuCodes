// Write a function template for selection sort that inputs, sorts and outputs an integer array and 
// a float array.

#include <iostream>
using namespace std;
template <class T>
class Sort
{
    public:
        T v[50];
        int n;
        void accept()
        {
            cout<<"Enter number of elements: "<<endl;
            cin>>n;
            cout<<"Enter the elements: "<<endl;
            for (int i = 0; i < n; i++)
                cin>>v[i];
        }
        void selectionSort ()
        {
            T temp;
            for (int i = 0; i < n - 1; i++)
            {
                int minIndex = i;
                for (int j = i + 1; j < n; j++)
                {
                    if (v[j] < v[minIndex])
                        minIndex = j;
                }
                temp = v[i];
                v[i] = v[minIndex];
                v[minIndex] = temp;
            }
        }
        void display ()
        {
            for (int i = 0; i < n; i++)
                cout<<v[i]<<" ";
        }
};
int main()
{
    int choice;
    char ch;
    Sort<int> s1;
    Sort<float> s2;
    cout<<"******SELECTION SORT*******"<<endl;
    do {
        cout << "------ Sorting of integer and float arrays ------" << endl;
        cout << "1. For int array." << endl;
        cout << "2. For float array." << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            s1.accept();
            s1.selectionSort();
            cout << "Sorted elements are: " << endl;
            s1.display();
            break;
        case 2:
            s2.accept();
            s2.selectionSort();
            cout << "Sorted elements are: " << endl;
            s2.display();
            break;
        default:
            cout << "Invalid choice! Please choose 1 or 2." << endl;
        }
        do {
            cout << "\nDo you want to continue? (y/n): ";
            cin >> ch;
            ch = tolower(ch); 
            if (ch != 'y' && ch != 'n') {
                cout << "Invalid input! Please enter 'y' for yes or 'n' for no." << endl;
            }
        } while (ch != 'y' && ch != 'n');  

    } while (ch == 'y');  
    
    return 0;
}

// OR


#include <iostream>
using namespace std;

// Template function for selection sort
template <typename T>
void selectionSort(T arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        // Find the minimum element in the unsorted portion of the array
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first element
        T temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

// Helper function to print the array
template <typename T>
void printArray(T arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Test with integer array
    int intArr[100];
    int size;
    cout << "Enter size of Int Array: ";
    cin >> size;
    cout << "Enter int Array Elements:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> intArr[i];
    }
    cout << "Original Integer Array: ";
    printArray(intArr, size);
    selectionSort(intArr, size);
    cout << "Sorted Integer Array: ";
    printArray(intArr, size);

    // Test with float array
    float floatArr[100];
    int fsize;
    cout << "Enter size of Float Array: ";
    cin >> fsize; // Use the correct variable `fsize` here
    cout << "Enter float Array Elements:" << endl;
    for (int i = 0; i < fsize; i++) {
        cin >> floatArr[i];
    }
    cout << "Original Float Array: ";
    printArray(floatArr, fsize);
    selectionSort(floatArr, fsize);
    cout << "Sorted Float Array: ";
    printArray(floatArr, fsize);

    return 0;
}
