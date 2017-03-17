using namespace std;

/******************************************************************************
* get to the right place or die.                                             *
******************************************************************************/
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

