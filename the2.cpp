// Cem Orsel, 2018

#include <cstring>
#include <vector>
#include <set>
#include <fstream>
#include <iostream>

unsigned int* matrix;
unsigned int matrixSize[2];
const char* INPUT_FILE = "./the1.inp";
const unsigned int MAX_LINE_SIZE = 50;

void readFile(void)
{
  std::fstream file(INPUT_FILE, std::ios_base::in);
  if (!file.is_open())
    abort();

  char line[MAX_LINE_SIZE];

  // Get number of rows and columns
  memset(line, 0, MAX_LINE_SIZE);
  file.getline(line, MAX_LINE_SIZE);
  if (sscanf("%u %u", matrixSize[0], matrixSize[1]) < 2)
    abort();

  // Allocate memory for matrix
  matrix = new unsigned int* [matrixSize[0]];
  for (int i = 0; i < matrixSize[0]; i++)
  {
    matrix[i] = new unsigned int [matrixSize[1]];
  }

  // Fill the matrix
  for (int i = 0; i < matrixSize[0]; i++)
  {
    memset(line, 0, MAX_LINE_SIZE);
    file.getline(line, MAX_LINE_SIZE);
    char token[MAX_LINE_SIZE] = strtok(line, " ");
    unsigned int j = 0;
    matrix[i][j] = atoi(token);
    while (token = strtok(token, " "))
    {
      matrix[i][++j] = atoi(token);
    }
  }
}

void printMatrix(void)
{
  for (int i = 0; i < matrixSize[0]; i++)
  {
    std::cout << std::endl;
    for (int j = 0; j < matrixSize[1]; j++)
    {
      std::cout << matrix[i][j]; 
    }
  }
}

int main(int argc, char* argv[])
{
  readFile();
  printMatrix();
  return 0; 
}
