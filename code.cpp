#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

// Utility Functions
void printArray(const vector<int>& arr, const string& message = "") {
    if (!message.empty()) cout << message << ": ";
    for (int num : arr) cout << num << " ";
    cout << endl;
}

void visualizeProgress(const vector<int>& arr, int highlight1 = -1, int highlight2 = -1) {
    for (int i = 0; i < arr.size(); ++i) {
        if (i == highlight1 || i == highlight2) cout << "[" << arr[i] << "] ";
        else cout << arr[i] << " ";
    }
    cout << endl;
}

// --- Sorting Algorithms ---
void bubbleSortVisualizer(vector<int> arr) {
    cout << "\n--- Bubble Sort Visualization ---\n";
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            cout << "Comparing " << arr[j] << " and " << arr[j + 1] << ": ";
            visualizeProgress(arr, j, j + 1);
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                cout << "  Swapped: ";
                visualizeProgress(arr, j, j + 1);
            }
        }
        cout << "After pass " << i + 1 << ": ";
        printArray(arr);
    }
    cout << "\nSorted Array: ";
    printArray(arr);
}

void selectionSortVisualizer(vector<int> arr) {
    cout << "\n--- Selection Sort Visualization ---\n";
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            cout << "Comparing " << arr[j] << " and " << arr[minIdx] << ": ";
            visualizeProgress(arr, j, minIdx);
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
        cout << "Swapped " << arr[i] << " with " << arr[minIdx] << ": ";
        printArray(arr);
    }
    cout << "\nSorted Array: ";
    printArray(arr);
}

void insertionSortVisualizer(vector<int> arr) {
    cout << "\n--- Insertion Sort Visualization ---\n";
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        cout << "Inserting " << key << ": ";
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            visualizeProgress(arr, j + 1);
        }
        arr[j + 1] = key;
        printArray(arr);
    }
    cout << "\nSorted Array: ";
    printArray(arr);
}

void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int i = 0; i < n2; i++) R[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSortVisualizer(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSortVisualizer(arr, l, m);
        mergeSortVisualizer(arr, m + 1, r);
        merge(arr, l, m, r);
        cout << "Merged: ";
        printArray(arr);
    }
}

void quickSortVisualizer(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        cout << "Pivot " << pivot << " sorted: ";
        printArray(arr);

        quickSortVisualizer(arr, low, i);
        quickSortVisualizer(arr, i + 2, high);
    }
}

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSortVisualizer(vector<int> arr) {
    cout << "\n--- Heap Sort Visualization ---\n";
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
    cout << "Heapified array: ";
    printArray(arr);

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
        cout << "After removing max element: ";
        printArray(arr);
    }
    cout << "\nSorted Array: ";
    printArray(arr);
}

// Sorting Menu
void sortingAlgorithmsMenu() {
    while (true) {
        cout << "\n--- Sorting Algorithms ---\n";
        cout << "1. Bubble Sort\n";
        cout << "2. Selection Sort\n";
        cout << "3. Insertion Sort\n";
        cout << "4. Merge Sort\n";
        cout << "5. Quick Sort\n";
        cout << "6. Heap Sort\n";
        cout << "7. Back to Main Menu\n";
        cout << "Choose an algorithm: ";
        int choice;
        cin >> choice;

        // If the user chooses 7, return to the main menu
        if (choice == 7) {
            return;  // Exit the sorting algorithms menu and go back to the main menu
        }

        int n;
        vector<int> arr;

        cout << "Enter array size: ";
        cin >> n;
        cout << "Enter " << n << " elements:\n";
        for (int i = 0; i < n; ++i) {
            int num;
            cin >> num;
            arr.push_back(num);
        }

        switch (choice) {
            case 1:
                bubbleSortVisualizer(arr);
                break;
            case 2:
                selectionSortVisualizer(arr);
                break;
            case 3:
                insertionSortVisualizer(arr);
                break;
            case 4:
                mergeSortVisualizer(arr, 0, arr.size() - 1);
                break;
            case 5:
                quickSortVisualizer(arr, 0, arr.size() - 1);
                break;
            case 6:
                heapSortVisualizer(arr);
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}


// --- Graph Algorithms ---
void bfsVisualizer(const vector<vector<int>>& graph, int start) {
    cout << "\n--- BFS Visualization ---\n";
    int V = graph.size();
    vector<bool> visited(V, false);  // Marks if the node has been visited
    queue<int> q;                    // Queue for BFS
    q.push(start);
    visited[start] = true;

    cout << "Visited Nodes: ";
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";  // Print the current node being processed

        // Show the node being processed and its neighbors
        cout << "\nProcessing Node " << u << " with neighbors: ";
        for (int v : graph[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
                cout << v << " ";  // Visualize the neighbor being added to the queue
            }
        }
        cout << endl;  // End of current node processing
    }
    cout << endl;
}


void dfsUtil(const vector<vector<int>>& graph, int v, vector<bool>& visited) {
    visited[v] = true;
    cout << v << " ";

    // Visualize the node being processed
    cout << "\nProcessing Node " << v << " with neighbors: ";
    for (int i : graph[v]) {
        if (!visited[i]) {
            cout << i << " "; // Visualize the neighbor being visited
            dfsUtil(graph, i, visited);
        }
    }
    cout << endl;  // End of current DFS node processing
}

void dfsVisualizer(const vector<vector<int>>& graph, int start) {
    cout << "\n--- DFS Visualization ---\n";
    int V = graph.size();
    vector<bool> visited(V, false);
    cout << "Visited Nodes: ";
    dfsUtil(graph, start, visited);
    cout << endl;
}

void dijkstraVisualizer(const vector<vector<pair<int, int>>>& graph, int start, int destination) {
    cout << "\n--- Dijkstra's Algorithm Visualization ---\n";
    int V = graph.size();
    vector<int> dist(V, INT_MAX);      // Stores the shortest distance to each vertex
    vector<bool> visited(V, false);   // Marks if the node has been visited
    vector<int> prev(V, -1);          // Previous node in the shortest path

    dist[start] = 0;  // Distance to the source node is 0

    // Priority queue to process nodes with the smallest distance first
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});  // {distance, node}

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        // Show the node being processed and its neighbors
        cout << "\nProcessing Node " << u << " with current distances:\n";
        for (auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                prev[v] = u;  // Update the previous node for the path
                pq.push({dist[v], v});
                cout << "  Distance to node " << v << " updated to " << dist[v] << endl;
            }
        }

        // Display the current state of distances
        cout << "Current distances: ";
        for (int i = 0; i < V; i++) {
            cout << "Node " << i << ": " << dist[i] << " ";
        }
        cout << endl;
    }

    // If destination is reachable, display the shortest path
    if (dist[destination] == INT_MAX) {
        cout << "\nNo path exists from source " << start << " to destination " << destination << endl;
        return;
    }

    // Reconstruct the path from source to destination
    stack<int> path;
    for (int v = destination; v != -1; v = prev[v]) {
        path.push(v);
    }

    cout << "\nShortest path from node " << start << " to node " << destination << ": ";
    while (!path.empty()) {
        cout << path.top() << " ";
        path.pop();
    }
    cout << "\nTotal distance: " << dist[destination] << endl;
}


void primsVisualizer(const vector<vector<pair<int, int>>>& graph, int V) {
    cout << "\n--- Prim's Algorithm Visualization ---\n";
    vector<int> parent(V, -1);
    vector<int> key(V, INT_MAX);
    vector<bool> inMST(V, false);
    key[0] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = -1;
        for (int i = 0; i < V; i++) {
            if (!inMST[i] && (u == -1 || key[i] < key[u])) {
                u = i;
            }
        }
        inMST[u] = true;

        // Show the node being added to MST and its neighbors being considered
        cout << "\nIncluding node " << u << " in MST with current MST edges:\n";
        for (auto edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                cout << "Edge " << u << " - " << v << " with weight " << weight << " is added to MST.\n";
            }
        }

        cout << "Current MST: ";
        for (int i = 0; i < V; i++) {
            if (parent[i] != -1)
                cout << parent[i] << " - " << i << " ";
        }
        cout << endl;
    }

    cout << "Final MST edges with weights:\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << "   " << key[i] << endl;
    }
}


void graphAlgorithmsMenu() {
    while (true) {
        cout << "\n--- Graph Algorithms ---\n";
        cout << "1. BFS\n";
        cout << "2. DFS\n";
        cout << "3. Dijkstra's Algorithm\n";
        cout << "4. Prim's Algorithm\n";
        cout << "5. Back to Main Menu\n";
        cout << "Choose an algorithm: ";
        int choice;
        cin >> choice;

        // If the user chooses 5, return to the main menu
        if (choice == 5) {
            return;  // Exit the graph algorithms menu and go back to the main menu
        }

        int V, E;
        cout << "Enter number of vertices: ";
        cin >> V;
        vector<vector<int>> graph(V); // Unweighted graph
        vector<vector<pair<int, int>>> weightedGraph(V); // Weighted graph for algorithms like Dijkstra and Prim's

        cout << "Enter number of edges: ";
        cin >> E;

        // Unweighted graph edges (for BFS, DFS)
        cout << "Enter edges (u v) for unweighted graph:\n";
        for (int i = 0; i < E; ++i) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u); // For undirected graph
        }

        // Weighted graph edges (for Dijkstra, Prim's)
        cout << "Enter edges (u v weight) for weighted graph:\n";
        for (int i = 0; i < E; ++i) {
            int u, v, weight;
            cin >> u >> v >> weight;
            weightedGraph[u].emplace_back(v, weight);
            weightedGraph[v].emplace_back(u, weight); // For undirected graph
        }

        int start, destination;
        cout << "Enter start node: ";
        cin >> start;

        // Only ask for destination for Dijkstra's Algorithm
        destination = -1;
        if (choice == 3) { // Dijkstra's Algorithm requires destination
            cout << "Enter destination node: ";
            cin >> destination;
        }

        switch (choice) {
            case 1:
                bfsVisualizer(graph, start);
                break;
            case 2:
                dfsVisualizer(graph, start);
                break;
            case 3:
                dijkstraVisualizer(weightedGraph, start, destination);  // Pass both source and destination
                break;
            case 4:
                primsVisualizer(weightedGraph, V);
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}


// --- Array-Based Algorithms ---
void kadanesAlgorithmVisualizer(const vector<int>& arr) {
    cout << "\n--- Kadane's Algorithm Visualization ---\n";
    int maxCurrent = 0, maxGlobal = INT_MIN;
    for (int num : arr) {
        maxCurrent = max(num, maxCurrent + num);
        maxGlobal = max(maxGlobal, maxCurrent);
        cout << "Processing: " << num << ", Current Max: " << maxCurrent << ", Global Max: " << maxGlobal << endl;
    }
    cout << "Maximum Subarray Sum: " << maxGlobal << endl;
}

void arrayAlgorithmsMenu() {
    while (true) {
        cout << "\n--- Array-Based Algorithms ---\n";
        cout << "1. Kadane's Algorithm\n";
        cout << "2. Back to Main Menu\n";
        cout << "Choose an algorithm: ";
        int choice;
        cin >> choice;

        // If the user chooses 2 (Back to Main Menu), return to the main menu
        if (choice == 2) {
            return;  // Exit the array algorithms menu and go back to the main menu
        }

        int n;
        vector<int> arr;

        cout << "Enter array size: ";
        cin >> n;
        cout << "Enter " << n << " elements:\n";
        for (int i = 0; i < n; ++i) {
            int num;
            cin >> num;
            arr.push_back(num);
        }

        switch (choice) {
            case 1:
                kadanesAlgorithmVisualizer(arr);
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}


// --- Main Menu ---
int main() {
    while (true) {
        cout << "\n=== Algorithm Visualizer ===\n";
        cout << "1. Sorting Algorithms\n";
        cout << "2. Graph Algorithms\n";
        cout << "3. Array-Based Algorithms\n";
        cout << "4. Exit\n";
        cout << "Choose a category: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                sortingAlgorithmsMenu();
                break;
            case 2:
                graphAlgorithmsMenu();
                break;
            case 3:
                arrayAlgorithmsMenu();
                break;
            case 4:
                cout << "Exiting Algorithm Visualizer. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}