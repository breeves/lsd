#include <iostream>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <getopt.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>



using namespace std;
string idir;

int isDirectory(const char *path) {
  struct stat statbuf;
  if (stat(path, &statbuf) != 0)
    return 0;
  return S_ISDIR(statbuf.st_mode);
}

/******************************************************************************
* get to the right place or die.                                             *
******************************************************************************/
void changeDir(string dir)
{
  int d = chdir(dir.c_str());

  if (d < 0) {
    cout << "Invalid directory : " << dir << endl;
    exit(2);
  }
}

/******************************************************************************
* Is not a Dot Directory
******************************************************************************/
int isNotDotdir(string dirname)
{
  if (dirname == "." || dirname == "..") {
    return 0;
  } else { return 1;}
}


/******************************************************************************
* Main
******************************************************************************/
int main(  int argc, char *argv[] )
{
  DIR *dir = NULL;
  struct dirent *drnt = NULL;
  int count = 0;
  int dcount = 0;

  if (argc == 2) {
    idir = argv[1];
  } else { 
    idir = "."; 
  }

  changeDir(idir);

  dir = opendir(".");
  if(dir)
  {
    while(drnt = readdir(dir))
    {
      if (isDirectory(drnt->d_name) && isNotDotdir(drnt->d_name)) {
        cout << "<DIR>";
        cout << " : " << drnt->d_name << "\n";
        dcount++;
      } else {
        count++;
      }
    }
    closedir(dir);

  }
  else
  {
    cout << "Can not open directory : " << idir << endl;
  }

  cout << dcount << " Directory(s)\n";
  cout << abs(count - dcount) << " File(s)\n";
  //cout << idir << endl;

  return 0;
}
