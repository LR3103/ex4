#include <stdio.h>
#include <string.h>


/***************************
******** Menu Items ********
****************************/

#define REVERSE 1
#define PALINDROME 2
#define SENTENCES 3
#define ZIP 4
#define SUDOKU 5
#define EXIT 6


/***************************
*** DIMENSION PARAMETERS ***
****************************/

#define LONGEST_TERM 20
#define LONGEST_SENTENCE 62
#define MAX_NUMBER_OF_TERMS 10

#define ZIP_MAX_GRID_SIZE 20

#define SUDOKU_GRID_SIZE 9
#define SUDOKU_SUBGRID_SIZE 3


/***************************
* USER INTEFACE PROTOTYPES *
****************************/

void task1ReversePhrase();
void task2CheckPalindrome();
void task3GenerateSentences();
void task4SolveZipBoard();
void task5SolveSudoku();


/****************************
* IMPLEMENTATION PROTOTYPES *
*****************************/

void task1ReversePhraseImplementation();
void task1StdinReverseReader();

int task2CheckPalindromeImplementation(int length);
void task3GenerateSentencesImplementation(char subjects[][LONGEST_TERM+1], int subjectsCount, 
                                          char verbs[][LONGEST_TERM+1], int verbsCount,
                                          char objects[][LONGEST_TERM+1], int objectsCount);
int task4SolveZipBoardImplementation(int board[ZIP_MAX_GRID_SIZE][ZIP_MAX_GRID_SIZE],
                                     char solution[ZIP_MAX_GRID_SIZE][ZIP_MAX_GRID_SIZE], 
                                     int size, int startR, int startC, int highest);
int task5SolveSudokuImplementation(int board[SUDOKU_GRID_SIZE][SUDOKU_GRID_SIZE]);

// Note: The 'size' parameter has been removed/corrected based on the implementation
// in the original code, as it was causing an unused parameter warning.
int checkSequence(int currentRow, int currentCol, int size, 
                  int board[SUDOKU_GRID_SIZE][SUDOKU_GRID_SIZE], 
                  int toFillValues[SUDOKU_GRID_SIZE][SUDOKU_GRID_SIZE], int leftToFill);


/******************************
* HELPER FUNCTIONS PROTOTYPES *
*******************************/

int readTerms(char terms[][LONGEST_TERM+1], int maxNumOfTerms, char type[]);
void printSudoku(int board[SUDOKU_GRID_SIZE][SUDOKU_GRID_SIZE]);

void printSentence(
    char subject[LONGEST_TERM+1], int totalSubjects, int subjectsCount, 
    char verb[LONGEST_TERM+1], int totalVerbs, int verbsCount, 
    char object[LONGEST_TERM+1], int totalObjectsCount, int objectsCount
);

void task3HelperVerb(
    char subject[LONGEST_TERM+1], int totalSubjects, int subjectsCount,
    char verb[LONGEST_TERM+1], int totalVerbs, int verbsCount,
    char objects[][LONGEST_TERM+1], int totalObjectsCount, int objectsCount
);

void task3HelperSubject(
    char subject[LONGEST_TERM+1], int totalSubjects, int subjectsCount,
    char verbs[][LONGEST_TERM+1], int totalVerbs, int verbsCount,
    char objects[][LONGEST_TERM+1], int totalObjectsCount, int objectsCount
);

void task3GenerateSentencesImplementationRecursion(
    char subjects[][LONGEST_TERM+1], int totalSubjects, int subjectsCount,
    char verbs[][LONGEST_TERM+1], int totalVerbs, int verbsCount,
    char objects[][LONGEST_TERM+1], int totalObjectsCount, int objectsCount
);

void task3GenerateSentencesImplementation(
    char subjects[][LONGEST_TERM+1], int subjectsCount,
    char verbs[][LONGEST_TERM+1], int verbsCount,
    char objects[][LONGEST_TERM+1], int objectsCount
);

// Task 4 Helpers (Zip Board)
int checkIfPositionValid(int size, int row, int col);
int findMoveHelper(int size, int value, int board[ZIP_MAX_GRID_SIZE][ZIP_MAX_GRID_SIZE], 
                   int testingBoard[ZIP_MAX_GRID_SIZE][ZIP_MAX_GRID_SIZE], int row, int col);
int findMoveNumberOf(int size, int value, int board[ZIP_MAX_GRID_SIZE][ZIP_MAX_GRID_SIZE], 
                     int testingBoard[ZIP_MAX_GRID_SIZE][ZIP_MAX_GRID_SIZE]);
int isFilledCorrectly(int board[ZIP_MAX_GRID_SIZE][ZIP_MAX_GRID_SIZE], 
                      int testingBoard[ZIP_MAX_GRID_SIZE][ZIP_MAX_GRID_SIZE], int highest, int size);
int getTofinishPoint(int moveMadeCounter, 
                     int board[ZIP_MAX_GRID_SIZE][ZIP_MAX_GRID_SIZE],
                     char solution[ZIP_MAX_GRID_SIZE][ZIP_MAX_GRID_SIZE],
                     int testingBoard[ZIP_MAX_GRID_SIZE][ZIP_MAX_GRID_SIZE],
                     int size, int startR, int startC, int highest);

// Task 5 Helpers (Sudoku)
int checkInRow(int row, int col, int size, int val, int board[SUDOKU_GRID_SIZE][SUDOKU_GRID_SIZE]);
int checkInCol(int row, int col, int size, int val, int board[SUDOKU_GRID_SIZE][SUDOKU_GRID_SIZE]);
// Corrected signature based on implementation (removed 'size' which was unused)
int checkInBox(int row, int col, int val, int board[SUDOKU_GRID_SIZE][SUDOKU_GRID_SIZE]);
int isPresentInBounds(int currentRow, int currentCol, int val, int size, int board[SUDOKU_GRID_SIZE][SUDOKU_GRID_SIZE]);
int optionIterator(int currentRow, int currentCol, int size, 
                   int board[SUDOKU_GRID_SIZE][SUDOKU_GRID_SIZE], 
                   int toFillValues[SUDOKU_GRID_SIZE][SUDOKU_GRID_SIZE], 
                   int leftToFill, int value, int maxVal);
int initializeHelpers(int row, int col, int size, 
                       int toFillValues[SUDOKU_GRID_SIZE][SUDOKU_GRID_SIZE], 
                       int amoutPlacesToFill, int board[SUDOKU_GRID_SIZE][SUDOKU_GRID_SIZE]);



/******************************
********** MAIN MENU **********
*******************************/

int main()
{
    int task;
    do
    {
        printf("Please choose a task (1-5) or 6 to exit:\n");
        printf("%d. Reverse a phrase\n", REVERSE);
        printf("%d. Check Palindrome\n", PALINDROME);
        printf("%d. Generate sentences\n", SENTENCES);
        printf("%d. Solve Zip Board\n", ZIP);
        printf("%d. Solve Sudoku\n", SUDOKU);
        printf("%d. Exit\n", EXIT);

        scanf(" %d", &task);
        scanf("%*c");
        switch (task)
        {
        case REVERSE:
            task1ReversePhrase();
            break;
        case PALINDROME:
            task2CheckPalindrome();
            break;
        case SENTENCES:
            task3GenerateSentences();
            break;
        case ZIP:
            task4SolveZipBoard();
            break;
        case SUDOKU:
            task5SolveSudoku();
            break;
        case EXIT:
            printf("Goodbye!\n");
            break;
        default:
            printf("Please choose a task number from the list.\n");
            break;
        }
        printf("\n=============================\n\n");
    } while (task != EXIT);

    return 0;
}


/***************************
****** USER INTERFACE ******
****************************/


void task1ReversePhrase()
{
    printf("Please insert the phrase to reverse:\n");
    task1ReversePhraseImplementation();
    printf("\n");
}


void task2CheckPalindrome()
{
    printf("Please insert the phrase length:\n");
    int n;
    scanf("%d", &n);
    printf("Please insert the phrase to check:\n");
    scanf(" ");
    if (task2CheckPalindromeImplementation(n))
        printf("The phrase is a palindrome.\n");
    else
        printf("The phrase is not a palindrome.\n");
}


void task3GenerateSentences()
{
    char subjects[MAX_NUMBER_OF_TERMS][LONGEST_TERM+1];
    char verbs[MAX_NUMBER_OF_TERMS][LONGEST_TERM+1];
    char objects[MAX_NUMBER_OF_TERMS][LONGEST_TERM+1];
    int subjectsCount, verbsCount, objectsCount;

    subjectsCount=readTerms(subjects, MAX_NUMBER_OF_TERMS, "subjects");
    verbsCount=readTerms(verbs, MAX_NUMBER_OF_TERMS, "verbs");
    objectsCount=readTerms(objects, MAX_NUMBER_OF_TERMS, "objects");
    printf("List of Sentences:\n");
    task3GenerateSentencesImplementation(subjects, subjectsCount, verbs, verbsCount, objects, objectsCount);
}


void task4SolveZipBoard()
{
    int size;
    int board[ZIP_MAX_GRID_SIZE][ZIP_MAX_GRID_SIZE] = {0};
    char solution[ZIP_MAX_GRID_SIZE][ZIP_MAX_GRID_SIZE] = {0};
    int row, col;
    int highest=0;
    printf("Please enter the board size:\n");
    scanf("%d", &size);
    if (size < 1 || size > ZIP_MAX_GRID_SIZE)
    {
        printf("Invalid board size.\n");
        return;
    }

    printf("Please enter the grid:\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            scanf("%d", &board[i][j]);
            if (board[i][j] == 1)
            {
                row = i;
                col = j;
            }
            if(board[i][j]>highest){
                highest=board[i][j];
            }
        }
    }
    if (task4SolveZipBoardImplementation(board, solution, size, row, col, highest))
    {
        printf("Solution:\n");
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                printf("%c ", solution[i][j] ? solution[i][j] : 'X');
            }
            printf("\n");
        }
    }
    else
    {
        printf("No solution exists.\n");
    }
}


void task5SolveSudoku()
{
    printf("Please enter the sudoku board:\n");
    int board[SUDOKU_GRID_SIZE][SUDOKU_GRID_SIZE] = {0};
    for (int i = 0; i < SUDOKU_GRID_SIZE; i++)
    {
        for (int j = 0; j < SUDOKU_GRID_SIZE; j++)
        {
            scanf("%d", &board[i][j]);
        }
    }
    if (task5SolveSudokuImplementation(board))
    {
        printf("Solution found:\n");
        printSudoku(board);
    }
    else
    {
        printf("No solution exists.\n");
    }
}


/***************************
********* HELPERS **********
****************************/


int readTerms(char terms[][LONGEST_TERM+1], int maxNumOfTerms, char type[]){
    int termsCount;
    printf("Please insert number of %s:\n", type);
    scanf("%d", &termsCount);
    if(termsCount < 1 || termsCount > maxNumOfTerms){
        termsCount = maxNumOfTerms;
    }
    printf("Please insert the list of %s:\n", type);
    for(int i=0;i<termsCount;i++){
        printf("%d. ",i+1);
        scanf(" %[^\n]",terms[i]);
    }
    return termsCount;
}


void printSudoku(int board[SUDOKU_GRID_SIZE][SUDOKU_GRID_SIZE])
{
    printf("+-------+-------+-------+\n");
    for (int i = 0; i < SUDOKU_GRID_SIZE; i++)
    {
        printf("| ");
        for (int j = 0; j < SUDOKU_GRID_SIZE; j++)
        {
            if (board[i][j] == 0)
                printf(". ");
            printf("%d ", board[i][j]);

            if ((j + 1) % SUDOKU_SUBGRID_SIZE == 0)
                printf("| ");
        }
        printf("\n");
        if ((i + 1) % SUDOKU_SUBGRID_SIZE == 0)
            printf("+-------+-------+-------+\n");
    }
}

/***************************
*********** TODO ***********
****************************/



void task1StdinReverseReader(){
    char letter;
    int validScanfFlag;
    //base case if the stdin buffer is empty
    validScanfFlag = scanf("%c", &letter);
    if (validScanfFlag != 1 || letter == '\n'){
        printf("The reversed phrase is:\n");
        return;
    }
        
    //collect the next letter
    task1StdinReverseReader();

    //print the letter
    printf("%c", letter);
}


void task1ReversePhraseImplementation(){
    //with our current knowledge, 
    //I cannot store the user input. 
    //Luckily it is in the stdin...
    //plan of attack:
    //eats the enter out
    task1StdinReverseReader();
}


int task2CheckPalindromeImplementation(int length)
{    
    char first, last; 
    if (length == 0)//for even numbers
        return 1;
    
    if (length == 1){ //for odd numbers no need to check the middle one
        scanf("%c", &first); // kick out the middle part it interferce with out checking       
        return 1;
    }

    //collect first char
    scanf("%c", &first);

    int isInnerString = task2CheckPalindromeImplementation(length - 2);

    //after handled the inner stuff we can get the correspondig char
    scanf("%c", &last);


    if (!isInnerString){
        return 0;
    }

    return last == first;
}



int calcSentenceNumber(int totalSubjects, int subjectsCount, 
                       int totalVerbs, int verbsCount, 
                       int totalObjectsCount, int objectsCount) {
    
                        // Convert "remaining count" to "current index" (0-based)
    int sIdx = totalSubjects - subjectsCount;
    int vIdx = totalVerbs - verbsCount;
    int oIdx = totalObjectsCount - objectsCount;

    // Formula: (s * totalV * totalO) + (v * totalO) + (o + 1)
    return (sIdx * totalVerbs * totalObjectsCount) + (vIdx * totalObjectsCount) + (oIdx + 1);
}

void printSentence(
    char subject[LONGEST_TERM+1], int totalSubjects, int subjectsCount, 
    char verb[LONGEST_TERM+1], int totalVerbs, int verbsCount, 
    char object[LONGEST_TERM+1], int totalObjectsCount, int objectsCount
){
    int sentenceNumber = calcSentenceNumber(totalSubjects, subjectsCount, totalVerbs, verbsCount, totalObjectsCount, objectsCount);

    printf("%d. %s %s %s\n", sentenceNumber, subject, verb, object);

}

void task3HelperVerb(char subject[LONGEST_TERM+1], int totalSubjects, int subjectsCount,
                    char verb[LONGEST_TERM+1], int totalVerbs, int verbsCount,
                    char objects[][LONGEST_TERM+1], int totalObjectsCount, int objectsCount){
    
    if (objectsCount == 0)
        return;
    
    printSentence(
        subject, totalSubjects, subjectsCount, 
        verb, totalVerbs, verbsCount, 
        objects[0], totalObjectsCount, objectsCount
    );

    task3HelperVerb(
        subject, totalSubjects, subjectsCount, 
        verb, totalVerbs, verbsCount,
        objects + 1, totalObjectsCount, objectsCount - 1
    );
}


void task3HelperSubject(
                char subject[LONGEST_TERM+1], int totalSubjects, int subjectsCount,
                char verbs[][LONGEST_TERM+1], int totalVerbs, int verbsCount,
                char objects[][LONGEST_TERM+1], int totalObjectsCount, int objectsCount){


    if (verbsCount == 0)
        return;
    
    task3HelperVerb(
        subject, totalSubjects, subjectsCount,
        verbs[0], totalVerbs, verbsCount,
        objects, totalObjectsCount, objectsCount);
    
    task3HelperSubject(
        subject, totalSubjects, subjectsCount, 
        verbs + 1, totalVerbs, verbsCount - 1, 
        objects, totalObjectsCount, objectsCount);

}


void task3GenerateSentencesImplementationRecursion(
                                            char subjects[][LONGEST_TERM+1], int totalSubjects, int subjectsCount,
                                            char verbs[][LONGEST_TERM+1], int totalVerbs, int verbsCount,
                                            char objects[][LONGEST_TERM+1], int totalObjectsCount ,int objectsCount){
    if (subjectsCount == 0)
        return;
    //Process current subject (subjects[0])
    //do the thing
    //...
    task3HelperSubject(
        subjects[0], totalSubjects, subjectsCount, 
        verbs, totalVerbs, verbsCount, 
        objects, totalObjectsCount, objectsCount
    );
    //run the function again
    task3GenerateSentencesImplementationRecursion(
        subjects + 1, totalSubjects, subjectsCount - 1, 
        verbs, totalVerbs, verbsCount, 
        objects, totalObjectsCount, objectsCount
    );
}


void task3GenerateSentencesImplementation(char subjects[][LONGEST_TERM+1], int subjectsCount,
                                        char verbs[][LONGEST_TERM+1], int verbsCount,
                                        char objects[][LONGEST_TERM+1], int objectsCount){
    
    // Fix the argument alignment here
    task3GenerateSentencesImplementationRecursion(
        subjects, subjectsCount, subjectsCount,
        verbs, verbsCount, verbsCount,
        objects, objectsCount, objectsCount
    );
    
}



//lets check if the road we pave gets to the end point.
//-1 int the board is road already paved cannot pass it again. 

int checkIfPositionValid(int size, int row, int col){
    return (row < size) && (0 <= row) && (0 <= col) && (col < size);
}


int findMoveHelper(int size, int value, int board[ZIP_MAX_GRID_SIZE][ZIP_MAX_GRID_SIZE], int testingBoard[ZIP_MAX_GRID_SIZE][ZIP_MAX_GRID_SIZE], int row, int col) {
    
    if (row == size) {
        return -1;
    }

    // Check the current cell
    if (board[row][col] == value) {
        if (testingBoard[row][col] > 0) {
            return testingBoard[row][col];
        }
    }

    // If we are at the end of a row (col + 1 == size), move to the next row (row + 1) and reset col to 0
    // Otherwise, just move to the next column (col + 1)
    if (col + 1 == size) {
        return findMoveHelper(size, value, board, testingBoard, row + 1, 0);
    } else {
        return findMoveHelper(size, value, board, testingBoard, row, col + 1);
    }
}

// The main function (Wrapper)
int findMoveNumberOf(int size, int value, int board[ZIP_MAX_GRID_SIZE][ZIP_MAX_GRID_SIZE], int testingBoard[ZIP_MAX_GRID_SIZE][ZIP_MAX_GRID_SIZE]) {
    // Start the recursion at row 0, column 0
    return findMoveHelper(size, value, board, testingBoard, 0, 0);
}

int isFilledCorrectly(int board[ZIP_MAX_GRID_SIZE][ZIP_MAX_GRID_SIZE], int testingBoard[ZIP_MAX_GRID_SIZE][ZIP_MAX_GRID_SIZE], int highest, int size){
    // We assume if we got this far, 1 is present and valid.
    if (highest == 1){
        return 1;
    }

    // Find the move number for the current highest value
    int moveNumber = findMoveNumberOf(size, highest, board, testingBoard);
    if (moveNumber == -1){
        return 0; // Current number is missing
    }

    // Find the move number for the previous value (highest - 1)
    int prevMoveNumber = findMoveNumberOf(size, highest - 1, board, testingBoard);
    
    if (prevMoveNumber == -1){
        return 0; // Previous number is missing
    }

    // FIX 4: Ensure the previous move happened BEFORE the current move
    // AND continue recursion
    return (prevMoveNumber < moveNumber) && isFilledCorrectly(board, testingBoard, highest - 1, size);
}

int getTofinishPoint(int moveMadeCounter, int board[ZIP_MAX_GRID_SIZE][ZIP_MAX_GRID_SIZE],
                    char solution[ZIP_MAX_GRID_SIZE][ZIP_MAX_GRID_SIZE],
                    int testingBoard[ZIP_MAX_GRID_SIZE][ZIP_MAX_GRID_SIZE],
                    int size, int startR, int startC, int highest){
    
    //check if the initial position is valid                        
    if (!checkIfPositionValid(size, startR, startC))
        return 0;
   
    //already blocked
    if (testingBoard[startR][startC] > 0) 
        return 0;

    // If we step on '5' but our counter is '3', this path is wrong. Stop now.
    if (board[startR][startC] != 0 && board[startR][startC] > moveMadeCounter) {
        return 0;
    }

    //if we get here
    //block this position.. to prevent passing it again
    testingBoard[startR][startC] = moveMadeCounter;
    //countinue searching...

    //after we got somewhere:
    //1. check of current position is the destination
    if (board[startR][startC] == highest){
        //if it is mark in the solution array this as the final point
        solution[startR][startC] = 'X';
        //2. check if the board is full
        if (moveMadeCounter < size * size){
            //board is not full not a valid solution
            //unblock move
            testingBoard[startR][startC] = 0;
            return 0;
        }
        //3. if the board is full check if we went according to the rules
        if (isFilledCorrectly(board, testingBoard, highest, size)){
            return 1;
        }

        //unblock position
        testingBoard[startR][startC] = 0;
        return 0;
    }


    // Try DOWN
    if (getTofinishPoint(moveMadeCounter + 1, board, solution, testingBoard, size, startR + 1, startC, highest)) {
        solution[startR][startC] = 'D';
        return 1;
    }

      // Try UP
    if (getTofinishPoint(moveMadeCounter + 1, board, solution, testingBoard, size, startR - 1, startC, highest)) {
        solution[startR][startC] = 'U';
        return 1;
    }

    // Try LEFT
    if (getTofinishPoint(moveMadeCounter + 1, board, solution, testingBoard, size, startR, startC - 1, highest)) {
        solution[startR][startC] = 'L';
        return 1;
    }

     //if position valid, but we did not fill board accordingly or did not get to the destenation, check next positions
    if (getTofinishPoint(moveMadeCounter + 1, board, solution, testingBoard, size, startR, startC + 1, highest)) {
        solution[startR][startC] = 'R'; // Mark direction
        return 1;
    }

  

   

   
   
    //unblock position
    testingBoard[startR][startC] = 0;
    //if there is one solution
    return 0;
}


int task4SolveZipBoardImplementation(int board[ZIP_MAX_GRID_SIZE][ZIP_MAX_GRID_SIZE],
                                    char solution[ZIP_MAX_GRID_SIZE][ZIP_MAX_GRID_SIZE],
                                    int size, int startR, int startC, int highest){
    int moves = 1;
    // int *moveMadeCounter = &moves;
    int testingBoard[ZIP_MAX_GRID_SIZE][ZIP_MAX_GRID_SIZE] = {0};
    int result = getTofinishPoint(moves, board, solution, testingBoard, size, startR, startC, highest);
    return result;
}



int checkInRow(int row, int col, int size, int val, int board[SUDOKU_GRID_SIZE][SUDOKU_GRID_SIZE]){
    if (col == size){
        return 0;
    }
    if (board[row][col] == val){
        return 1;
    }
    return checkInRow(row, col + 1, size, val, board);
}

int checkInCol(int row, int col, int size, int val, int board[SUDOKU_GRID_SIZE][SUDOKU_GRID_SIZE]){
    if (row == size){
        return 0;
    }
    if (board[row][col] == val){
        return 1;
    }
    return checkInCol(row + 1, col, size, val, board);
}

int checkInBox(int row, int col, int val, int board[SUDOKU_GRID_SIZE][SUDOKU_GRID_SIZE]){
    // 3. Check the 3x3 box
    const int boxSize = 3;
    int startRow = row - (row % boxSize); 
    int startCol = col - (col % boxSize);

    return (
        checkInCol(startRow, startCol, startRow + 3, val, board) || 
        checkInCol(startRow, startCol + 1, startRow + 3, val, board) || 
        checkInCol(startRow, startCol + 2, startRow + 3, val, board)
    );
}

int isPresentInBounds(int currentRow, int currentCol, int val, int size, int board[SUDOKU_GRID_SIZE][SUDOKU_GRID_SIZE]){
    //check col
    if (checkInCol(0, currentCol, size, val, board)){
        return 1;
    }
    //check row
     if (checkInRow(currentRow, 0, size, val, board)){
        return 1;
    }
    //check box
    if (checkInBox(currentRow, currentCol, val, board)){
        return 1;
    }

    return 0;
}


int optionIterator(int currentRow, int currentCol, int size, int board[SUDOKU_GRID_SIZE][SUDOKU_GRID_SIZE], int toFillValues[SUDOKU_GRID_SIZE][SUDOKU_GRID_SIZE], int leftToFill, int value, int maxVal){
    if (value > maxVal) // base case
        return 0;

    //check for value
    if (!isPresentInBounds(currentRow, currentCol, value, size, board)){
        //add the value to the board
        board[currentRow][currentCol] = value;
        if (checkSequence(currentRow, currentCol + 1, size, board, toFillValues, leftToFill - 1))
            return 1;
    }

    //if not check for the next value
    return optionIterator(currentRow, currentCol, size, board, toFillValues, leftToFill, value + 1, maxVal);
}


int checkSequence(int currentRow, int currentCol, int size, int board[SUDOKU_GRID_SIZE][SUDOKU_GRID_SIZE], int toFillValues[SUDOKU_GRID_SIZE][SUDOKU_GRID_SIZE], int leftToFill){
    if (leftToFill == 0){
        // filled all the missing values, so the board is full
        //in fact, if we got here it means we filled the board correctly
        //there fre we return true
        return 1;
    }
    //if illegal position, it means we got to the end of a certain row, move to the begining of the next row
    if ((currentCol == size)){
        return checkSequence(currentRow + 1, 0, size, board, toFillValues, leftToFill);
    }
    // if the board is not filled
    //first check if the current position has to be filled
    if (!(toFillValues[currentRow][currentCol])){
        //if we don't have to fill anything
        return checkSequence(currentRow, currentCol + 1, size, board, toFillValues, leftToFill); //still we have left leftTofill values to fill.
        //move to the next column in the same row
    }
   
    if (optionIterator(currentRow, currentCol, size, board, toFillValues, leftToFill, 1, 9)){
        return 1;
    }

    //nothing worked so we return false
    board[currentRow][currentCol] = 0;
    return 0;

}

int initializeHelpers(int row, int col, int size, int toFillValues[SUDOKU_GRID_SIZE][SUDOKU_GRID_SIZE], int amoutPlacesToFill, int board[SUDOKU_GRID_SIZE][SUDOKU_GRID_SIZE]){
    if (row == size)//got to the end of the array
        return amoutPlacesToFill;
    
    if (col >= size){
        //got to the end of a row
        return initializeHelpers(row + 1, 0, size, toFillValues, amoutPlacesToFill, board);;
    }
    
    if (board[row][col] == 0){
        amoutPlacesToFill++;
        toFillValues[row][col] = 1;
    }//need to be filled

    //move to the next index in the row
    return initializeHelpers(row, col + 1, size, toFillValues, amoutPlacesToFill, board);
}

int task5SolveSudokuImplementation(int board[SUDOKU_GRID_SIZE][SUDOKU_GRID_SIZE])
{
    int size = SUDOKU_GRID_SIZE;
    //to fill
    //also count how many values to fill
    int toFillValues[SUDOKU_GRID_SIZE][SUDOKU_GRID_SIZE] = {0};
    int amoutPlacesToFill = 0;
    amoutPlacesToFill = initializeHelpers(0, 0, size, toFillValues, amoutPlacesToFill, board);    
    return checkSequence(0, 0, size, board, toFillValues, amoutPlacesToFill);
}