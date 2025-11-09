#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

#define X 0
#define Y 1

class Scan
{
public:
    int len;
    int **data;
    Scan(int length, int **arr)
    {
        len = length;
        data = arr;
    }
};

Scan JSONtoScan(string json)
{
    int width = 3;
    int height = -1;
    for (int i = 0; i < json.size(); i++)
    {
        if (json[i] == '[')
        {
            height++;
        }
    }

    int **board = new int *[height];
    for (int a = 0; a < height; ++a)
        board[a] = new int[width];

    int row = -2;
    int col = 0;
    string temp = "";
    for (int i = 0; i < json.size(); i++)
    {
        if (json[i] == '[')
        {
            row++;
            col = 0;
            temp = "";
        }
        else if (json[i] == ',')
        {
            if (temp != "")
            {
                board[row][col] = stoi(temp);
                temp = "";
            }
            col++;
        }
        else if (json[i] == ']')
        {
            if (temp != "")
            {
                board[row][col] = stoi(temp);
                temp = "";
            }
        }
        else if (json[i] == ' ')
        {
        }
        else
        {
            temp += json[i];
        }
    }
    return Scan(height, board);
}

int getMax(int **array, int len, int index)
{ // index tells us if we are looking at the x or the y part
    int max = array[0][index];
    for (int i = 1; i < len; i++)
        if (array[i][index] > max)
            max = array[i][index];
    return max;
}

void countingSort(int **array, int size, int place, int index)
{
    const int max = 10;
    int **output = new int *[size];
    int count[max];

    for (int i = 0; i < max; ++i)
        count[i] = 0;

    // Calculate count of elements
    for (int i = 0; i < size; i++)
        count[(array[i][index] / place) % 10]++;

    // Calculate cumulative count
    for (int i = 1; i < max; i++)
        count[i] += count[i - 1];

    // Place the elements in sorted order
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(array[i][index] / place) % 10] - 1] = array[i];
        count[(array[i][index] / place) % 10]--;
    }

    for (int i = 0; i < size; i++)
        array[i] = output[i];
}

void radixsort(int **array, int size, int index)
{
    // Get maximum element
    int max = getMax(array, size, index);

    // Apply counting sort to sort elements based on place value.
    for (int place = 1; max / place > 0; place *= 10)
        countingSort(array, size, place, index);
}

int **scanToBoard(Scan input, int numRows, int numCols)
{
    int **board = new int *[numRows];
    for (int b = 0; b < numRows; ++b)
        board[b] = new int[numCols];
    // generate list sorted by y, smallest to largest
    radixsort(input.data, input.len, Y);
    // fill the board row by row
    for (int i = 0; i < input.len; i += numCols)
    {
        int curRow = i / numCols;
        int **temp = new int *[numCols];
        for (int j = 0; j < numCols; j++)
        {
            temp[j] = input.data[j + i];
        }
        radixsort(temp, numCols, X);
        // copy this row into the board
        for (int a = 0; a < numCols; a++)
            board[curRow][a] = temp[a][2];
    }
    return board;
}

string boardToJSON(int **board, int numRows, int numCols)
{
    // convert 2D board to JSON string
    string output = "[";
    for (int row = 0; row < numRows; row++)
    {
        output += "[";
        for (int col = 0; col < numCols; col++)
        {
            output += to_string(board[row][col]);
            output += ",";
        }
        output[output.length() - 1] = ']';
        output += ",";
    }
    output[output.length() - 1] = ']';
    return output;
}

int main(int argc, char *argv[])
{
    Scan scan = JSONtoScan(argv[1]);
    int numRows = stoi(argv[2]);
    int numCols = stoi(argv[3]);

    int **board = scanToBoard(scan, numRows, numCols);

    cout << boardToJSON(board, numRows, numCols);
}