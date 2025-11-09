#include <iostream>
using namespace std;

#define B 0
#define R 1
#define Y 2
#define W 3
#define CHICKEN 0
#define COW 1
#define PIG 2
#define SHEEP 3

// [ID][color][animal]
int cnt[93][4][4] = {
    //0 and 1 are unused ID's
    { {}, {}, {}, {} }, //0
    { {}, {}, {}, {} }, //1

    // {chicken, cow, pig, sheep}
    
//      BLUE        RED      YELLOW       WILD
    { {0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {1,0,0,0} }, //2
    { {0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,1,0,0} },
    { {0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,1,0} },
    { {2,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0} }, //5
    { {0,2,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0} },
    { {0,0,2,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0} },
    { {1,1,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0} },
    { {0,1,1,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0} },
    { {1,0,1,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0} }, //10
    {{-1,-1,0,0},{0,0,0,0}, {0,0,0,0}, {0,0,0,0} },
    {{0,-1,-1,0},{0,0,0,0}, {0,0,0,0}, {0,0,0,0} },
    {{-1,0,-1,0},{0,0,0,0}, {0,0,0,0}, {0,0,0,0} },
    { {0,0,0,0}, {1,0,0,0}, {1,0,0,0}, {0,0,0,0} },
    { {1,0,0,0}, {1,0,0,0}, {0,0,0,0}, {0,0,0,0} }, //15
    { {1,0,0,0}, {0,0,0,0}, {1,0,0,0}, {0,0,0,0} },
    { {0,1,0,0}, {0,0,0,0}, {0,1,0,0}, {0,0,0,0} },
    { {0,0,0,0}, {0,1,0,0}, {0,1,0,0}, {0,0,0,0} },
    { {0,1,0,0}, {0,1,0,0}, {0,0,0,0}, {0,0,0,0} },
    { {0,0,0,0}, {0,0,1,0}, {0,0,1,0}, {0,0,0,0} }, //20
    { {0,0,1,0}, {0,0,1,0}, {0,0,0,0}, {0,0,0,0} },
    { {0,0,1,0}, {0,0,0,0}, {0,0,1,0}, {0,0,0,0} },
    { {0,0,0,0},{-1,-1,0,0},{0,0,0,0}, {0,0,0,0} },
    { {0,0,0,0},{0,-1,-1,0},{0,0,0,0}, {0,0,0,0} },
    { {0,0,0,0},{-1,0,-1,0},{0,0,0,0}, {0,0,0,0} }, //25
    { {0,0,0,0}, {2,0,0,0}, {0,0,0,0}, {0,0,0,0} },
    { {0,0,0,0}, {0,2,0,0}, {0,0,0,0}, {0,0,0,0} },
    { {0,0,0,0}, {0,0,2,0}, {0,0,0,0}, {0,0,0,0} },
    { {0,0,0,0}, {0,1,1,0}, {0,0,0,0}, {0,0,0,0} },
    { {0,0,0,0}, {1,0,1,0}, {0,0,0,0}, {0,0,0,0} }, //30
    { {0,0,0,0}, {1,1,0,0}, {0,0,0,0}, {0,0,0,0} },
    { {0,0,0,0}, {0,0,0,0}, {0,0,0,2}, {0,0,0,0} },
    { {0,0,0,2}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0} },
    { {0,0,0,0}, {0,0,0,2}, {0,0,0,0}, {0,0,0,0} },
    { {0,0,0,1}, {0,0,0,0}, {0,0,0,1}, {0,0,0,0} }, //35
    { {0,0,0,1}, {0,0,0,1}, {0,0,0,0}, {0,0,0,0} },
    { {0,0,0,0}, {0,0,0,1}, {0,0,0,1}, {0,0,0,0} },
    { {0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {2,0,0,0} },
    { {0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,2,0,0} },
    { {0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,2,0} }, //40
    { {0,0,0,0}, {0,0,0,0}, {0,0,0,0},{-1,-1,0,0}},
    { {0,0,0,0}, {0,0,0,0}, {0,0,0,0},{0,-1,-1,0}},
    { {0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {-1,0,0,0}},
    { {0,0,0,0}, {0,0,0,0}, {0,0,0,0},{-1,0,-1,0}},
    { {0,0,0,0}, {0,0,0,0}, {0,2,0,0}, {0,0,0,0} }, //45
    { {0,0,0,0}, {0,0,0,0}, {0,0,2,0}, {0,0,0,0} },
    { {0,0,0,0}, {0,0,0,0}, {0,1,1,0}, {0,0,0,0} },
    { {0,0,0,0}, {0,0,0,0}, {1,0,1,0}, {0,0,0,0} },
    { {0,0,0,0}, {0,0,0,0}, {1,1,0,0}, {0,0,0,0} },
    { {0,0,0,0}, {0,0,0,0},{-1,-1,0,0},{0,0,0,0} }, //50
    { {0,0,0,0}, {0,0,0,0},{0,-1,-1,0},{0,0,0,0} },
    { {0,0,0,0}, {0,0,0,0},{-1,0,-1,0},{0,0,0,0} },
    { {0,0,1,0}, {1,0,0,0}, {0,1,0,0}, {0,0,0,0} },
    { {1,0,0,0}, {0,1,0,0}, {0,0,1,0}, {0,0,0,0} },
    { {0,1,0,0}, {0,0,1,0}, {1,0,0,0}, {0,0,0,0} }, //55
    { {1,0,0,0}, {0,0,1,0}, {0,1,0,0}, {0,0,0,0} },
    { {0,0,1,0}, {0,1,0,0}, {1,0,0,0}, {0,0,0,0} },
    { {0,1,0,0}, {1,0,0,0}, {0,0,1,0}, {0,0,0,0} },
    { {0,0,1,0}, {0,1,0,0}, {1,0,0,0}, {0,0,0,0} },
    { {0,1,0,0}, {1,0,0,0}, {0,0,1,0}, {0,0,0,0} }, //60
    { {1,0,0,0}, {0,0,1,0}, {0,1,0,0}, {0,0,0,0} },
    { {0,1,0,0}, {1,0,0,0}, {0,0,1,0}, {0,0,0,0} },
    { {1,0,0,0}, {0,0,1,0}, {0,1,0,0}, {0,0,0,0} },
    { {0,0,1,0}, {0,1,0,0}, {1,0,0,0}, {0,0,0,0} },
    { {0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {1,1,1,0} }, //65
    { {1,1,1,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0} },
    { {1,0,0,0}, {1,0,0,0}, {1,0,0,0}, {0,0,0,0} },
    { {0,1,0,0}, {0,1,0,0}, {0,1,0,0}, {0,0,0,0} },
    { {0,0,1,0}, {0,0,1,0}, {0,0,1,0}, {0,0,0,0} },
    { {0,0,0,0}, {1,1,1,0}, {0,0,0,0}, {0,0,0,0} }, //70
    { {0,0,0,0}, {0,0,0,3}, {0,0,0,0}, {0,0,0,0} },
    { {0,0,0,3}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0} },
    { {0,0,0,0}, {0,0,0,0}, {0,0,0,3}, {0,0,0,0} },
    { {0,0,0,1}, {0,0,0,1}, {0,0,0,1}, {0,0,0,0} },
    { {0,0,0,-3},{0,0,0,0}, {0,0,0,0}, {0,0,0,0} }, //75
    { {0,0,0,0}, {0,0,0,-3},{0,0,0,0}, {0,0,0,0} },
    { {0,0,0,0}, {0,0,0,0}, {0,0,0,-3},{0,0,0,0} },
    { {0,0,0,-1},{0,0,0,-1},{0,0,0,-1},{0,0,0,0} },
    { {0,0,0,0}, {0,0,0,0}, {1,1,1,0}, {0,0,0,0} },
    { {0,0,0,0}, {0,1,0,0}, {0,0,0,-1},{0,0,0,0} }, //80
    { {0,0,0,-1},{0,0,0,0}, {1,0,0,0}, {0,0,0,0} },
    { {0,0,1,0}, {0,0,0,-1},{0,0,0,0}, {0,0,0,0} },
    { {0,0,0,0}, {0,0,0,0}, {0,0,-1,0},{1,0,0,0} },
    { {0,0,0,0}, {-1,0,0,0},{0,0,0,0}, {0,1,0,0} },
    { {0,-1,0,0},{0,0,0,0}, {0,0,0,0}, {0,0,1,0} }, //85
    { {0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0} },
    { {0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0} },
    { {0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0} },
    { {0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0} },
    { {0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0} }, //90
    { {0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0} },
    { {0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0} }, //92
};

void printSum(int sum, int color, int animal);

class Board
{
private:
    int width;
    int height;
    int** board;
    int*** colorMult;
public:
    Board(int** bo, int wid, int hei)
    {
        this->setBoard(bo, wid, hei);
    }
    Board(int** bo)
    {
        this->setBoard(bo);
    }
    int getSum(int color, int animal);
    void setBoard(int** bo, int wid, int hei);
    void setBoard(int** bo)
    {
        setBoard(bo, 4, 4);
    }
};

void Board::setBoard(int** bo, int wid, int hei)
{
    this->width = wid;
    this->height = hei;
    this->board = new int*[hei];
    for(int a = 0; a < hei; ++a)
        board[a] = new int[wid];
    this->colorMult = new int**[hei];
    for(int a = 0; a < hei; ++a)
        colorMult[a] = new int*[wid];

    for(int i=0; i<wid; i++)
        for(int j=0; j<hei; j++)
            board[j][i] = bo[j][i];
    for(int i=0; i<wid; i++)
        for(int j=0; j<hei; j++)
        {
            colorMult[j][i] = new int[4];
            for(int k=0; k<4; k++)
                colorMult[j][i][k]=1;
        }
    
    for(int i=0; i<wid; i++)
        for(int j=0; j<hei; j++)
        {
            if(board[j][i] == 86) //if card is wild row*2
                for(int k=0; k<wid; k++)
                    colorMult[j][k][W]*=2;
            if(board[j][i] == 87) //if card is wild col*2
                for(int k=0; k<hei; k++)
                    colorMult[k][i][W]*=2;
            if(board[j][i] == 88) //if card is wild row*-1
                for(int k=0; k<wid; k++)
                    colorMult[j][k][W]*=-1;
            if(board[j][i] == 89) //if card is wild col*-1
                for(int k=0; k<hei; k++)
                    colorMult[k][i][W]*=-1;
            if(board[j][i] == 90) //if card is blue col*3
                for(int k=0; k<hei; k++)
                    colorMult[k][i][B]*=3;
            if(board[j][i] == 91) //if card is red col*3
                for(int k=0; k<hei; k++)
                    colorMult[k][i][R]*=3;
            if(board[j][i] == 92) //if card is yellow col*3
                for(int k=0; k<hei; k++)
                    colorMult[k][i][Y]*=3;
        }
}

//returns sum (including wilds)
//set color to W if looking for a specific animal, set animal to SHEEP if looking for a specific color
int Board::getSum(int color, int animal)
{
    int sum = 0;

    //we are looking for only a specific animal
    if(color == W) //animal can't be sheep
    {
        for(int col=0; col<width; col++)
            for(int row=0; row<height; row++)
            {
                for(int l = 0; l<3; l++)
                    sum += cnt[board[row][col]][l][animal] * colorMult[row][col][l] * colorMult[row][col][W]; //every color except wild
                sum += cnt[board[row][col]][W][animal] * colorMult[row][col][W]; //wild
            }
        return sum;
    }
    //we are looking for a only a specific color:
    if(animal == SHEEP) //(color can't be wild)
    {
        for(int col=0; col<width; col++)
            for(int row=0; row<height; row++)
            {
                for(int l = 0; l<4; l++)
                {
                    sum += cnt[board[row][col]][color][l] * colorMult[row][col][color] * colorMult[row][col][W]; //every animal that's the given color
                    sum += cnt[board[row][col]][W][l] * colorMult[row][col][W]; //every animal that's wild
                }
            }
        return sum;
    }

    
    for(int col=0; col<width; col++)
        for(int row=0; row<height; row++)
        {
            sum += (cnt[board[row][col]][color][animal] + cnt[board[row][col]][W][animal] + cnt[board[row][col]][color][SHEEP]) * colorMult[row][col][color] * colorMult[row][col][W];
        }
    printSum(sum, color, animal);
    return sum;
}

void printSum(int sum, int color, int animal)
{
    cout << sum << " ";
    switch(color)
    {
    case B:
        cout << "Blue ";
        break;
    case R:
        cout << "Red ";
        break;
    case Y:
        cout << "Yellow ";
        break;
    case W:
        cout << "Total ";
        break;
    }
    switch(animal)
    {
    case CHICKEN:
        cout << ((sum-1)?"Chickens":"Chicken");
        break;
    case COW:
        cout << ((sum-1)?"Cows":"Cow");
        break;
    case PIG:
        cout << ((sum-1)?"Pigs":"Pig");
        break;
    case SHEEP:
        cout << ((sum-1)?"Animals":"Animal");
        break;
    }
    cout << endl;
}


int main(int argc, char* argv[])
{
    int newBoard[4][4] = {
        {33,37,15,90},
        {9,8,81,40},
        {56,13,91,77},
        {18,11,2,35}
    };
    int** bd = new int*[4];
    for(int a = 0; a < 4; ++a)
        bd[a] = new int[4];
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            bd[j][i] = newBoard[j][i];
    
    Board board1 = Board(bd);
    board1.getSum(B, COW);
    return 0;
}

