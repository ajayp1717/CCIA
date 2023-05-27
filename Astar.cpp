#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

// Define the goal state
const vector<int> goalState = {1, 2, 3, 4, 5, 6, 7, 8, 0};

// Define the possible moves (up, down, left, right)
const vector<int> moves = {-3, 3, -1, 1};

// Define a structure to represent a state
struct State {
    vector<int> puzzle;
    int cost;
    int heuristic;
    int depth;
    int index;

    State(const vector<int>& p, int c, int h, int d, int i)
        : puzzle(p), cost(c), heuristic(h), depth(d), index(i) {}

    bool operator<(const State& other) const {
        return cost + heuristic > other.cost + other.heuristic;
    }
};

// Calculate the Manhattan distance heuristic for a given state
int calculateHeuristic(const vector<int>& puzzle) {
    int heuristic = 0;
    for (int i = 0; i < 9; i++) {
        if (puzzle[i] != 0) {
            int rowDiff = abs(i / 3 - (puzzle[i] - 1) / 3);
            int colDiff = abs(i % 3 - (puzzle[i] - 1) % 3);
            heuristic += rowDiff + colDiff;
        }
    }
    return heuristic;
}

// Check if a state is valid (within the puzzle boundaries)
bool isValidState(int x, int y) {
    return x >= 0 && x < 3 && y >= 0 && y < 3;
}

// Apply a move to a given state and return the resulting state
State applyMove(const State& currentState, int move) {
    vector<int> newPuzzle = currentState.puzzle;
    int zeroIndex = currentState.index;
    int newX = zeroIndex / 3 + move / 3;
    int newY = zeroIndex % 3 + move % 3;

    swap(newPuzzle[zeroIndex], newPuzzle[newX * 3 + newY]);

    return State(newPuzzle, currentState.cost + 1, calculateHeuristic(newPuzzle), currentState.depth + 1, newX * 3 + newY);
}

// Generate the successors of a given state
vector<State> generateSuccessors(const State& currentState) {
    vector<State> successors;

    for (int move : moves) {
        int newX = currentState.index / 3 + move / 3;
        int newY = currentState.index % 3 + move % 3;

        if (isValidState(newX, newY)) {
            successors.push_back(applyMove(currentState, move));
        }
    }

    return successors;
}

// Perform the A* search algorithm
void aStar(const vector<int>& initialState) {
    priority_queue<State> openList;
    map<vector<int>, bool> visited;
    map<vector<int>, int> gScore;

    // Initialize the start state
    int heuristic = calculateHeuristic(initialState);
    State startState(initialState, 0, heuristic, 0, find(initialState.begin(), initialState.end(), 0) - initialState.begin());
    openList.push(startState);
    gScore[initialState] = 0;

    while (!openList.empty()) {
        State currentState = openList.top();
        openList.pop();

        visited[currentState.puzzle] = true;

        // Check if the current state is the goal state
        if (currentState.puzzle == goalState) {
            cout << "Goal state found!" << endl;
            cout << "Cost: " << currentState.cost << endl;
            cout << "Depth: " << currentState.depth << endl;
            return;
        }

        vector<State> successors = generateSuccessors(currentState);
        for (const auto& successor : successors) {
            if (!visited[successor.puzzle] || successor.cost < gScore[successor.puzzle]) {
                gScore[successor.puzzle] = successor.cost;
                openList.push(successor);
            }
        }
    }

    // If the open list is empty and the goal state is not found, no solution exists
    cout << "No solution found!" << endl;
}

int main() {
    vector<int> initialState;
    cout << "Enter the initial state of the puzzle (0 represents the blank tile):" << endl;
    for (int i = 0; i < 9; i++) {
        int tile;
        cin >> tile;
        initialState.push_back(tile);
    }

    aStar(initialState);

    return 0;
}



// The code begins by including the necessary header files and defining some constants. It includes <iostream> for input/output, <vector> for working with vectors, <map> for working with maps, <queue> for the priority queue, and <cmath> for the abs function. It also defines the goal state of the puzzle and the possible moves.

// Next, a State struct is defined to represent a state of the puzzle. It contains the puzzle configuration, the cost, the heuristic value, the depth, and the index of the empty tile (0).

// The calculateHeuristic function is defined to calculate the Manhattan distance heuristic for a given puzzle state. It iterates through the puzzle and calculates the row and column differences between the current tile and its goal position. It returns the sum of these differences as the heuristic value.

// The isValidState function checks if a given position (x, y) is valid within the puzzle boundaries. It returns true if the position is valid and false otherwise.

// The applyMove function takes a current state and a move and applies the move to the state, returning the resulting state. It creates a copy of the current puzzle, finds the new position of the empty tile, and swaps the empty tile with the tile at the new position. It then creates a new state with the updated puzzle, cost, heuristic value, depth, and index of the empty tile.

// The generateSuccessors function takes a current state and generates all possible successor states. It iterates through the possible moves and applies each move to the current state using the applyMove function. It adds each resulting state to a vector of successors.

// The aStar function performs the A* search algorithm. It initializes a priority queue to store the open list of states, a map to keep track of visited states, and a map to store the cost of reaching each state.

// The code prompts the user to enter the initial state of the puzzle. The user provides the puzzle configuration as nine integers representing the tiles of the puzzle, with 0 representing the empty tile.

// The initial state is created and added to the open list with a cost of 0 and the calculated heuristic value. The cost of reaching the initial state is set to 0 in the gScore map.

// The main loop of the A* algorithm begins. While the open list is not empty, the algorithm selects the state with the lowest total cost (cost + heuristic) from the open list.

// If the selected state is the goal state (the puzzle configuration matches the goal state), the algorithm terminates and prints the cost and depth of the solution.

// If the selected state is not the goal state, the algorithm generates the successors of the selected state using the generateSuccessors function.

// For each successor, the algorithm checks if it has been visited before or if it has a lower cost to reach it. If it is a new state or has a lower cost, the cost in the gScore map is updated and the successor is added to the open list.

// If no solution is found and the open list becomes empty, the algorithm prints a "No solution found!" message.

// The main function prompts the user to enter the initial state, calls the aStar function with the initial state, and then terminates.

// The code uses the A* search algorithm to find the optimal solution for the 8-puzzle problem. It employs heuristics to estimate the cost of reaching the goal state and uses a priority queue to prioritize states with lower costs. By exploring the state space efficiently, it finds the shortest path to the goal state.
