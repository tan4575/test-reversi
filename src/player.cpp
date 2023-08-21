#include "player.h"
#include <iostream>
#include <algorithm> 
using namespace std;

static int myrandom (int i) { return std::rand()%i;}

struct Node {
    char data;
    struct Node* next;
};

/**
 * @brief create new node for link list
 * 
 * @param head_ref 
 * @param data 
 */
void push(struct Node** head_ref,char data)
{
    // allocate a new node in a heap using `malloc()` and set its data
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
 
    // set the `.next` pointer of the new node to point to ref node
    node->next = *(head_ref);

    // assign ref node with current node
    *(head_ref) = node;

}

/**
 * @brief print out the dat
 * 
 * @param head 
 */
void print_reverse_list(struct Node* head, vector<int> &data)
{
    // Base case 
    if (head == NULL)
       return;

    data.push_back(head->data);

    // print the list after head node
    print_reverse_list(head->next, data);

    // free the memory after print
    free(head);
}


/**
 * @brief Destroy the player::player object
 * 
 */
player::~player()
{

}

/**
 * @brief get x and y position
 * 
 * @param boardObj 
 * @return position_t 
 */
position_t player::input(algoMove_t* boardObj)
{
    position_t a = {-1,-1};
    int c;

    // if human
    if (getPlayer() == PLAYERTYPE::HUMAN)
    {
        a =  humanInput();
    }
    else{
        // AI
        cout << "Press enter to continue..." << endl;
        while ((c = getchar()) != '\n');
        a = AIInput(boardObj);
    }
    return a;
}

/**
 * @brief randomize all the potential steps o(n^2)
 * 
 * @param boardObj 
 * @return position_t 
 */
position_t player::AIInput(algoMove_t* boardObj){
    vi possibleMoves;
    position_t a = {-1,-1};
    srand(time(0));
    possibleMoves = _algo.pathFinding(boardObj);
    random_shuffle( possibleMoves.begin(), possibleMoves.end(), myrandom);
    if (possibleMoves.size() != 0)
    {
        for (auto &[x,y]: possibleMoves)
        {
            a.x = x;
            a.y = y;
            break;
        }
    }


    return a;
}

/**
 * @brief human input
 * 
 * @return position_t 
 */
position_t player::humanInput(){
    int c;
    string s = "";
    vector<int> data;
    Node *p = NULL;
    position_t a = {-1,-1};
    cout << "Type the x digit (0-7), with a space then the y digit (0-7)" << endl;
    cout << "For example, 0 0 will be the top left corner." << endl;
    while ((c = getchar()) != '\n')
    {
        if (c == ' ')
        {
            if (s.length() > 0)
            {
                push(&p,stoi(s));
            }
            s = "";
            continue;
        }
        else if (c > 0x39 || c < 0x29) continue;
        s += c;
    }
    if (s.length() > 0)
    {
        push(&p,stoi(s));
    }

    print_reverse_list(p,data);


    if (data.size() >= 2)
    {
        a.x = data[1];
        a.y = data[0];
    }

    return a;
}

/**
 * @brief Make movement
 * 
 * @param boardObj 
 * @param xI 
 * @param yI 
 * @return true 
 * @return false 
 */
bool player::makeMove(algoMove_t* boardObj, uint8_t xI, uint8_t yI)
{
    vi *tilesToFlip = new vi;
    tilesToFlip = _algo.getValidMove(boardObj,xI, yI);
    if (tilesToFlip == NULL)
    {
        delete tilesToFlip;
        return false;
    }
    for (auto &[x,y]: *tilesToFlip)
    {
        updateScore(boardObj,x,y);
        boardObj->board[x][y] = OTHELLO[(uint8_t)boardObj->tile];
    }
    updateScore(boardObj,xI,yI);
    boardObj->board[xI][yI] = OTHELLO[(uint8_t)boardObj->tile];
    delete tilesToFlip;
    return true;
}

/**
 * @brief update scores
 * 
 * @param boardObj 
 * @param x 
 * @param y 
 */
void player::updateScore(algoMove_t* boardObj, uint8_t x, uint8_t y)
{
    TILE openentTile = getOponentTile(boardObj->tile);
    if (boardObj->tile == TILE::X)
    {
        if (boardObj->board[x][y] != OTHELLO[(uint8_t)boardObj->tile])
            boardObj->xCount++;
        if (boardObj->board[x][y] == OTHELLO[(uint8_t)openentTile]){
            boardObj->oCount--;
        }
    }
    else{
        if (boardObj->board[x][y] != OTHELLO[(uint8_t)boardObj->tile])
            boardObj->oCount++;
        if (boardObj->board[x][y] == OTHELLO[(uint8_t)openentTile]){
            boardObj->xCount--;
        }
    }
}
/**
 * @brief get openet tile
 * 
 * @param t 
 * @return TILE 
 */
TILE player::getOponentTile(TILE t)
{
    if (t == TILE::X)
        return TILE::O;
    else
        return TILE::X;
}


/**
 * @brief update player tile
 * 
 * @param p1 
 * @return TILE 
 */
TILE player::updatePlayertile(const string p1)
{
    char t;
    string s;
    while (!(t == 'X' || t == 'O'))
    {
        cout << "Select " << p1 << " tile X or O." << endl;
        cin >> t;
        t = toupper(t);
        if (t == 'X')
        {
            tile = TILE::X;
        }
        else if (t == 'O')
        {
            tile = TILE::O;
        }
    }
    getchar();
    return tile;
}

/**
 * @brief set tile
 * 
 * @param t 
 */
void player::setTile(const TILE t){
    if (t == TILE::O)
        tile = TILE::X;
    else
        tile = TILE::O;
}
