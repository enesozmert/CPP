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
  std::string aux;
  char c;
  int i;
  int j;

  i = 0;
  j = 0;
  if (checkArgException(argc) == -1)
    return (-1);
  filename = argv[1];
  filename_replace = filename;
  filename_replace.append(".replace");
  s1 = argv[2];
  s2 = argv[3];
  readFile(readStream, filename);
  readFileException(readStream);
  while (!readStream.eof())
  {
    if (j == 0)
      readStream >> std::noskipws >> c;
    else
      j = 0;
    if (readStream.eof())
      break;
    if (c == s1.c_str()[0])
    {
      aux = "";
      aux.append(1, c);
      i = 1;
      while (i < (int)s1.length() && !readStream.eof())
      {
        readStream >> std::noskipws >> c;
        if (c != s1.c_str()[i])
        {
          j = 1;
          break;
        }
        aux.append(1, c);
        i++;
        std::cout << i << std::endl;
      }
      if (i == (int)s1.length())
        writeStream << s2;
      else
        writeStream << aux;
    }
    else
      writeStream << c;
  }
}