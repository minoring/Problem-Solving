#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Structure {
    bool hasPillar;
    bool hasBeam;

    Structure() : hasPillar(false), hasBeam(false) {}
};

bool canConstruct(const vector<int> &frame,
                  const vector<vector<Structure>> &grid) {
    int x = frame[0];
    int y = frame[1];
    bool isBeam = frame[2];

    int n = grid.size(); // Differ from n.
    if (isBeam) {
        if (grid[x][y - 1].hasPillar || grid[x + 1][y - 1].hasPillar ||
            ((x > 0 && grid[x - 1][y].hasBeam) &&
             (x + 1 < n && grid[x + 1][y].hasBeam))) {
            return true;
        }
        return false;
    } else {
        if (y == 0 || (x > 0 && grid[x - 1][y].hasBeam) || grid[x][y].hasBeam ||
            grid[x][y - 1].hasPillar) {
            return true;
        }
        return false;
    }
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;

    vector<vector<Structure>> grid(n + 1, vector<Structure>(n + 1));

    for (vector<int> &frame : build_frame) {
        int x = frame[0];
        int y = frame[1];
        bool isBeam = frame[2];
        bool isConstruct = frame[3];

        if (isConstruct) {
            if (canConstruct(frame, grid)) {
                if (isBeam) {
                    grid[x][y].hasBeam = true;
                } else {
                    grid[x][y].hasPillar = true;
                }
            }
        } else {
            if (isBeam) {
                grid[x][y].hasBeam = false;
                bool canDelete = true;

                if (grid[x][y].hasPillar) {
                    vector<int> tempFrame;
                    tempFrame.push_back(x);
                    tempFrame.push_back(y);
                    tempFrame.push_back(0);

                    if (!canConstruct(tempFrame, grid)) {
                        canDelete = false;
                    }
                }

                if (x < n && grid[x + 1][y].hasPillar) {
                    vector<int> tempFrame;
                    tempFrame.push_back(x + 1);
                    tempFrame.push_back(y);
                    tempFrame.push_back(0);

                    if (!canConstruct(tempFrame, grid)) {
                        canDelete = false;
                    }
                }

                if (x > 0 && grid[x - 1][y].hasBeam) {
                    vector<int> tempFrame;
                    tempFrame.push_back(x - 1);
                    tempFrame.push_back(y);
                    tempFrame.push_back(1);

                    if (!canConstruct(tempFrame, grid)) {
                        canDelete = false;
                    }
                }

                if (x < n && grid[x + 1][y].hasBeam) {
                    vector<int> tempFrame;
                    tempFrame.push_back(x + 1);
                    tempFrame.push_back(y);
                    tempFrame.push_back(1);

                    if (!canConstruct(tempFrame, grid)) {
                        canDelete = false;
                    }
                }

                if (!canDelete) {
                    grid[x][y].hasBeam = true;
                }
            } else {
                grid[x][y].hasPillar = false;
                bool canDelete = true;

                if (y < n && grid[x][y + 1].hasPillar) {
                    vector<int> tempFrame;
                    tempFrame.push_back(x);
                    tempFrame.push_back(y + 1);
                    tempFrame.push_back(0);

                    if (!canConstruct(tempFrame, grid)) {
                        canDelete = false;
                    }
                }

                if (y < n && x > 0 && grid[x - 1][y + 1].hasBeam) {
                    vector<int> tempFrame;
                    tempFrame.push_back(x - 1);
                    tempFrame.push_back(y + 1);
                    tempFrame.push_back(1);

                    if (!canConstruct(tempFrame, grid)) {
                        canDelete = false;
                    }
                }

                if (y < n && grid[x][y + 1].hasBeam) {
                    vector<int> tempFrame;
                    tempFrame.push_back(x);
                    tempFrame.push_back(y + 1);
                    tempFrame.push_back(1);

                    if (!canConstruct(tempFrame, grid)) {
                        canDelete = false;
                    }
                }

                if (!canDelete) {
                    grid[x][y].hasPillar = true;
                }
            }
        }
    }

    for (int x = 0; x < n + 1; ++x) {
        for (int y = 0; y < n + 1; ++y) {
            if (grid[x][y].hasPillar) {
                vector<int> temp;
                temp.push_back(x);
                temp.push_back(y);
                temp.push_back(0);
                answer.push_back(temp);
            }
            if (grid[x][y].hasBeam) {
                vector<int> temp;
                temp.push_back(x);
                temp.push_back(y);
                temp.push_back(1);
                answer.push_back(temp);
            }
        }
    }
    return answer;
}
