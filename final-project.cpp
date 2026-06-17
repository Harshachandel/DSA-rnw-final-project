#include <iostream>
#include <vector>
using namespace std;

// ================= LINKED LIST =================

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

Node* head = NULL;

// Insert at end
void insertNode(int value) {
    Node* newNode = new Node(value);

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Display Linked List
void displayList() {
    if (head == NULL) {
        cout << "Linked List is empty.\n";
        return;
    }

    Node* temp = head;

    cout << "Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// ================= MERGE SORT =================

void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp;

    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right) {
        if (arr[i] < arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }

    while (i <= mid)
        temp.push_back(arr[i++]);

    while (j <= right)
        temp.push_back(arr[j++]);

    for (int i = left; i <= right; i++) {
        arr[i] = temp[i - left];
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// ================= QUICK SORT =================

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// ================= BINARY SEARCH =================

int binarySearch(vector<int>& arr, int key) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

// Display Array
void displayArray(vector<int>& arr) {
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}

// ================= MAIN MENU =================

int main() {
    int choice;

    vector<int> arr;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Insert into Linked List\n";
        cout << "2. Display Linked List\n";
        cout << "3. Enter Array\n";
        cout << "4. Merge Sort\n";
        cout << "5. Quick Sort\n";
        cout << "6. Binary Search\n";
        cout << "7. Display Array\n";
        cout << "8. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            int value;
            cout << "Enter value: ";
            cin >> value;
            insertNode(value);
            break;
        }

        case 2:
            displayList();
            break;

        case 3: {
            arr.clear();

            int n, x;
            cout << "Enter number of elements: ";
            cin >> n;

            cout << "Enter elements:\n";
            for (int i = 0; i < n; i++) {
                cin >> x;
                arr.push_back(x);
            }
            break;
        }

        case 4:
            if (!arr.empty()) {
                mergeSort(arr, 0, arr.size() - 1);
                cout << "Array sorted using Merge Sort.\n";
            }
            else
                cout << "Enter array first.\n";
            break;

        case 5:
            if (!arr.empty()) {
                quickSort(arr, 0, arr.size() - 1);
                cout << "Array sorted using Quick Sort.\n";
            }
            else
                cout << "Enter array first.\n";
            break;

        case 6: {
            if (arr.empty()) {
                cout << "Enter array first.\n";
                break;
            }

            int key;
            cout << "Enter value to search: ";
            cin >> key;

            int pos = binarySearch(arr, key);

            if (pos != -1)
                cout << "Element found at index " << pos << endl;
            else
                cout << "Element not found.\n";

            break;
        }

        case 7:
            displayArray(arr);
            break;

        case 8:
            cout << "Program Ended.\n";
            break;

        default:
            cout << "Invalid Choice.\n";
        }

    } while (choice != 8);

    return 0;
}