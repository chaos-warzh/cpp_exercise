#include <iostream>
#include <cstdio>
#include <cstdint>
#include <cassert>
#include <vector>
#include <cstring>

#define ARG_WRONG "[ERROR]: Illegal argument for command ls!\n"

#define BYTES_PER_SEC 512
#define BPS (BYTES_PER_SEC)

#define IMG_KB 1440
#define IMG_SIZE (1024 * IMG_KB)
#define MAX_CTT (1024 * 16)

#define byte uint8_t
typedef unsigned int u;

using namespace std;

void out(const char *s) {
  printf("%s", s);
}

void err(const char *s) {
  out(s);
  exit(1);
}

class Fat12Sys {
  private:
  byte _db[IMG_SIZE];

  enum node_type {
    DIR,
    FL,
  };

  class _node {
    public:
    string name;
    node_type type;
    _node * dad;
    vector<_node *> sons;
    u son_dirs = 0;
    u son_files = 0;
    char *ctt = new char[MAX_CTT]{};
    u ctt_sz = 0;
  };

  void readSector(byte *bf, u sec_no, u bias, u len) { // [sec_first + bias, sec_first + bias + len)
    memcpy(bf, _db + sec_no * BPS + bias, len);
    // debug:
    out((char *)bf);
    assert(memcmp(bf, (_db + sec_no * BPS + bias), len) == 0);
  }


  public:

  Fat12Sys(char *path) {
    FILE *fp = fopen(path, "r");
    if (fp == nullptr) {
      err("fat file no found\n");

    } else {
      size_t count = fread(_db, 1, IMG_SIZE, fp);
      fclose(fp);
      if (count < IMG_SIZE) { // error
        err("fat file open error\n");
      }

    }
  }
};

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
