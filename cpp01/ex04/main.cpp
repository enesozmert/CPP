#include <iostream>
#include <fstream>
#include <string>

int checkArgException(int argc)
{
  if (argc != 4)
  {
    std::cout << "Invalid arg count" << std::endl;
    return (-1);
  }
  return (1);
}
int readFileException(std::fstream &stream)
{
  if (!stream)
  {
    std::cout << "Couldn't open input file. Try Again!" << std::endl;
    return (-1);
  }
  return (1);
}

int readFile(std::fstream &stream, std::string filename)
{
  stream.open(filename.c_str(), std::ios::in);
  return (0);
}

int writeFileException(std::fstream &stream)
{
  if (!stream)
  {
    std::cout << "Couldn't open input file. Try Again!" << std::endl;
    return (-1);
  }
  return (1);
}

int writeFile(std::fstream &stream, std::string filename)
{
  stream.open(filename.c_str(), std::ios::out);
  return (0);
}

int main(int argc, char **argv)
{
  std::string filename;
  std::string filename_replace;
  std::fstream readStream;
  std::fstream writeStream;
  std::string s1;
  std::string s2;
  int i;
  int j;

  if (checkArgException(argc) == -1)
    return (-1);

  filename = argv[1];
  filename_replace = filename;
  filename_replace.append(".replace");

  s1 = argv[2];
  s2 = argv[3];
  readFile(*)
}