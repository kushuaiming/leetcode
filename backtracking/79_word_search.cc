#include <iostream>
#include <string>
#include <vector>

const std::vector<std::vector<int>> directions = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool Dfs(std::vector<std::vector<char>>& board,
         std::vector<std::vector<bool>>& is_visited, const std::string& word,
         int i, int j, int k) {
  if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
      k >= word.size()) {
    return false;
  }
  if (is_visited[i][j] || board[i][j] != word[k]) {
    return false;
  }
  if (board[i][j] == word[k] && k == word.size() - 1) {
    return true;
  }
  is_visited[i][j] = true;
  for (const auto& direction : directions) {
    if (Dfs(board, is_visited, word, i + direction[0], j + direction[1],
            k + 1)) {
      return true;
    }
  }
  is_visited[i][j] = false;
  return false;
}

bool Exist(std::vector<std::vector<char>>& board, const std::string& word) {
  int m = board.size();
  int n = board[0].size();
  std::vector<std::vector<bool>> is_visited(m, std::vector<bool>(n, false));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (Dfs(board, is_visited, word, i, j, 0)) {
        return true;
      }
    }
  }
  return false;
}

int main(int argc, char* argv[]) {
  std::vector<std::vector<char>> board = {
      {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
  std::string word = "ABCCED";
  std::cout << Exist(board, word) << std::endl;
  return 0;
}
