class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for (int rows = 0; rows < m; rows++) {
            if (grid[rows][0] == 0) {
                for (int cols = 0; cols < n; cols++) {
                    if (grid[rows][cols] == 0)
                        grid[rows][cols] = 1;
                    else
                        grid[rows][cols] = 0;
                }
            }
        }

        for (int cols = 1; cols < n; cols++) {
            int noz = 0; // n(1)
            int noo = 0; // n(0)
            for (int rows = 0; rows < m; rows++) {
                if (grid[rows][cols] == 0)
                    noz++;
                else
                    noo++;
            }
            if (noz > noo) {
                for (int rows = 0; rows < m; rows++) {
                    grid[rows][cols] =
                        1 -
                        grid[rows]
                            [cols];
                }
            }
        }

        int score = 0;
        for (int rows = 0; rows < m; rows++) {
            int binaryScore = 1;
            for (int cols = n - 1; cols >= 0; cols--) {
                score += grid[rows][cols] * binaryScore;
                binaryScore *= 2;
            }
        }

        return score;
    }
};