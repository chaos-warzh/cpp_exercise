//
// Created by DELL on 2024/11/9.
//

#include <cstdio>
#include <cstdint>

int directions[6][3] = {
  {1, 0, 0},
  {-1, 0, 0},
  {0, 1, 0},
  {0, -1, 0},
  {0, 0, 1},
  {0, 0, -1}
};

#define N 600
#define STAR 7
#define QUEST 8

typedef struct mc {
  uint8_t map : 4;
  uint8_t count : 3;
  uint8_t bias : 1;
} mc;

mc map_count[N][N][N];

int isValid(int x, int y, int z, int n) {
  return x >= 0 && x < n && y >= 0 && y < n && z >= 0 && z < n;
}

void calculateMines(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        if (map_count[i][j][k].map == STAR || map_count[i][j][k].map == QUEST) {
          for (int d = 0; d < 6; d++) {
            int nx = i + directions[d][0];
            int ny = j + directions[d][1];
            int nz = k + directions[d][2];
            if (isValid(nx, ny, nz, n)) {
              if (map_count[i][j][k].map == QUEST) {
                map_count[nx][ny][nz].bias++;
              } else {
              	map_count[nx][ny][nz].count++;
			  }
            }
          }
        }
      }
    }
  }
}


int main() {
  int n;
  scanf("%d", &n);


  int questionMarkPos[3] = {-1, -1, -1};

  getchar();

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        char ch = getchar();
        if (ch == '?') {
          questionMarkPos[0] = i;
          questionMarkPos[1] = j;
          questionMarkPos[2] = k;
          map_count[i][j][k].map = QUEST;
        } else if (ch == '*') {
          map_count[i][j][k].map = STAR;
        } else {
          map_count[i][j][k].map = ch - '0';
        }
      }
    }
  }

  int validNoMine = 1;
  int invalidCoords[n][3];
  int invalidCount = 0;

  calculateMines(n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        if (map_count[i][j][k].map <= 6) {
          int expectedMines = map_count[i][j][k].map;
          int actualMines = map_count[i][j][k].count;
          if (actualMines != expectedMines) {
            validNoMine = 0;
            if (!(i == questionMarkPos[0] && j == questionMarkPos[1] && k == questionMarkPos[2])) {
              invalidCoords[invalidCount][0] = i + 1;
              invalidCoords[invalidCount][1] = j + 1;
              invalidCoords[invalidCount][2] = k + 1;
              invalidCount++;
            }
          }
        }
      }
    }
  }

  if (validNoMine) {
    printf("valid\n%d\n", map_count[questionMarkPos[0]][questionMarkPos[1]][questionMarkPos[2]].count);
    return 0;
  }

  int validWithMine = 1;
  invalidCount = 0;  
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        if (map_count[i][j][k].map <= 6) {
          int expectedMines = map_count[i][j][k].map;
          int actualMines = map_count[i][j][k].count + map_count[i][j][k].bias;
          if (actualMines != expectedMines) {
            validWithMine = 0;
            invalidCoords[invalidCount][0] = i + 1;
            invalidCoords[invalidCount][1] = j + 1;
            invalidCoords[invalidCount][2] = k + 1;
            invalidCount++;
          }
        }
      }
    }
  }


  if (validWithMine) {
    printf("valid\n*\n");
  } else {
    printf("invalid\n");
    for (int i = 0; i < invalidCount; i++) {
      printf("%d %d %d\n", invalidCoords[i][0], invalidCoords[i][1], invalidCoords[i][2]);
    }
  }

  return 0;
}
