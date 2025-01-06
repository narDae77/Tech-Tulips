#include <iostream>
#include <string>
using namespace std;
//hi there tell me this works
int main() {
    // Declare variables to hold words and game stats
    string startWord, endWord, currentWord, nextWord;
    int totalRounds = 0, player1Wins = 0, player2Wins = 0, player1Losses = 0, player2Losses = 0; 

    // A larger dictionary of valid English words
    string dictionary[] = {
        "FISH", "WISH", "WASH", "MASH", "MAST", "CAST", "FAST", "LAST",
        "BARK", "MARK", "LARK", "CARK", "CART", "PART", "PARK", "PARK",
        "COLD", "BOLD", "TOLD", "HOLD", "GOLD", "MOLD", "FOLD",
        "RACE", "BASE", "CASE", "FACE", "FAME", "NAME",
        "CANE", "DANE", "FANE", "LAME", "TAME", "SAME",
        "MIND", "BIND", "KIND", "FIND", "WIND", "LINED",
        "CANE", "DING", "SING", "RING", "KING", "PING",
        "MART", "PART", "HEAT", "MEAT", "SEAT", "BEAT", "FEAT",
        "HAT", "CAT", "BAT", "PAT", "MAT", "SAT",
        "WIND", "WEND", "LEND", "SEND", "BEND", "FEND",
        "ROAD", "LOAD", "GOAT", "GLOAT", "FLOAT", "FLOOD"
    };

    // Welcome message
    cout << "Welcome to the Word Ladder Game!" << endl;
    cout << "Rules: Player 1 provides a start and end word. Player 2 creates a ladder by changing one letter at a time." << endl;
    cout << "All words must be valid English words. Enter '0' to give up." << endl;

    while (true) {
        // Start a new round
        totalRounds++;
        cout << "\n--- Round " << totalRounds << " ---\n";

        // Player 1 provides start and end words
        a:
        cout << "Player 1, enter a start word (or 0 to finish): ";
        cin >> startWord;
        
        if(cin.fail() || !isalpha( startWord[0])) {
            cout << "Invalid Input! Please enter valid word." <<< endl;
            goto a; // Ask for input again
                }
        if (startWord == "0") break; // Exit the game if Player 1 quits

       b:
       cout << "Player 1, enter an end word: ";
        cin >> endWord;
       if(cin.fail() || !isalpha( startWord[0])) {
            cout << "Invalid Input! Please enter valid word." <<< endl;
            goto b;
                } 

        // Initialize the current word
        currentWord = startWord;
        bool ladderComplete = false;

        cout << "Player 2, create a word ladder starting from " << startWord << " to " << endWord << "." << endl;

        // Player 2 tries to build the ladder
        while (true) {
            c:
            if (cin.fail()|| !isalpha(startword[0])){
            cout << "Player 2, enter the next word (or 0 to give up): ";
            cin >> nextWord;

            // Check if Player 2 gives up
            if (nextWord == "0") {
                cout << "Player 2 gave up. You Lose!" << endl;
                player2Losses++;
                player1Wins++;
                break;
            }

            // Check if the word is in the dictionary
            bool validWord = false;
            for (int i = 0; i < sizeof(dictionary) / sizeof(dictionary[0]); i++) {
                 string word = dictionary[i];
                if (word == nextWord) {
                    validWord = true;
                    break;
                }
            
            }

            // Check if the word differs by exactly one letter
            int diffCount = 0;
            for (int i = 0; i < currentWord.size(); ++i) {
                if (currentWord[i] != nextWord[i]) diffCount++;
            }

            if (diffCount != 1) {
                cout << "Word must differ by exactly one letter. Try again." << endl;
                continue; // Ask for a valid word
            }

            // Update the current word
            currentWord = nextWord;

            // Check if the end word is reached
            if (currentWord == endWord) {
                cout << "Congratulations! You built the word ladder!" << endl;
                player2Wins++;
                ladderComplete = true;
                break;
            }
        }

        if (!ladderComplete) {
            cout << "Player 1 wins this round!" << endl;
            player1Wins++;
        }

        cout << "Switching roles...\n";
    }

    // Print final results
    cout << "\nGame Over!" << endl;
    cout << "Total Rounds Played: " << totalRounds << endl;
    cout << "Player 1 - Wins: " << player1Wins << ", Losses: " << player1Losses << endl;
    cout << "Player 2 - Wins: " << player2Wins << ", Losses: " << player2Losses << endl;

    return 0;
}
