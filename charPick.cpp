//
//  charPick.cpp
//
//  A practice coding project (bc i havent coded anything in
//  a while LOL & school is starting soon SOOOO)
//
//  Program that generates a random Smash character for you to play!
//  There's also a setting that asks you if you want to keep or remove
//  that character as a choice for the next generation.
//

#include <iostream>
#include <random>
#include <fstream>
using namespace std;

struct Node{
    string characterName;
    
    Node* next;
    Node* prev;
};

void insert(Node*& head, string smashCharacter) {
    Node* newPtr = new Node;
    
    newPtr->characterName = smashCharacter;
    newPtr->next = NULL;
    newPtr->prev = NULL;
    
    // list is empty, first node gets inserted
    if (head == NULL) {
        head = newPtr;
        
    } else if (head->characterName >= newPtr->characterName) {
        // node inserted at front
        newPtr->next = head;
        newPtr->prev = NULL; // before is empty
        
    }
        
    
}

int main(int argc, char* argv[]) {
    string firstColumn;
    Node* headPtr, tailPtr;
    
    fstream input(argv[1]);
    
    while (input >> firstColumn) {
        string smashCharacter = firstColumn;
        insert(headPtr, smashCharacter);
        
        if (!input) break;
    }
    input.close();

    out << endl << "List contents: " << endl;
    print(headPtr);
}


