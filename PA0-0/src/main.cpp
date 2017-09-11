#ifndef __MAIN_CPP_
#define __MAIN_CPP_

#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

const int MAX_BOAT_SIZE = 2;

void printTabs(int num) {
  for (int i = 0; i < num; i++) {
    cout << "   ";
  }
}

enum Direction {
  LEFT,
  RIGHT
};

struct Action {
  int numMissionariesMoving;
  int numCannibalsMoving;
};

struct GameState {
  int numMissionariesLeft;
  int numMissionariesRight;
  int numCannibalsLeft;
  int numCannibalsRight;
  Action action;
  GameState* parent;
  Direction locationOfBoat;
  int iteration;

  ~GameState() {
  }

  bool isValid() const {
    if (numCannibalsLeft > numMissionariesLeft && numMissionariesLeft > 0) {
      return false;
    }
    if (numCannibalsRight > numMissionariesRight && numMissionariesRight > 0) {
      return false;
    }
    return true;
  }

  bool isSolution() const {
    return (numCannibalsLeft == 0 && numMissionariesLeft == 0);
  }

  void print(int tabs = 0) const {
    printTabs(tabs);
    cout << "State [" << iteration << "]" << endl;
    printTabs(tabs);
    cout << "               Left                Right" << endl;
    printTabs(tabs);
    cout << "   Cannibals:  " << numCannibalsLeft << "                   " << numCannibalsRight << endl;
    printTabs(tabs);
    cout << "Missionaries:  " << numMissionariesLeft << "                   " << numMissionariesRight << endl;
    printTabs(tabs);
    cout << "  Boat is on:  " << ((locationOfBoat == LEFT) ? "LEFT" : "RIGHT") << endl;
    if (parent != NULL) {
      parent->print(tabs+1);
    }
  }

  void clear() {
    numMissionariesLeft = 0;
    numMissionariesRight = 0;
    numCannibalsLeft = 0;
    numCannibalsRight = 0;
    action.numMissionariesMoving = 0;
    action.numCannibalsMoving = 0;
  }

  void copy(GameState* src) {
    numMissionariesLeft = src->numMissionariesLeft;
    numMissionariesRight = src->numMissionariesRight;
    numCannibalsLeft = src->numCannibalsLeft;
    numCannibalsRight = src->numCannibalsRight;
    iteration = src->iteration+1;
  }
};

GameState* makeNewState(GameState *parentGameState, int numMissionariesToMove, int numCannibalsToMove) {
  GameState *proposedGameState = new GameState();
  proposedGameState->clear();
  proposedGameState->copy(parentGameState);

  if (parentGameState->locationOfBoat == LEFT) {
    if (numMissionariesToMove > parentGameState->numMissionariesLeft || numCannibalsToMove > parentGameState->numCannibalsLeft) {
      return NULL;
    }
    proposedGameState->locationOfBoat = RIGHT;
  } else {
    if (numMissionariesToMove > parentGameState->numMissionariesRight || numCannibalsToMove > parentGameState->numCannibalsRight) {
      return NULL;
    }
    proposedGameState->locationOfBoat = LEFT;
  }


  // move the number of missionaries said
  for (int m = 0; m < numMissionariesToMove; m++) {
    if (parentGameState->locationOfBoat == LEFT) {
      proposedGameState->numMissionariesLeft--;
      proposedGameState->numMissionariesRight++;
    } else if (parentGameState->locationOfBoat == RIGHT) {
      proposedGameState->numMissionariesLeft++;
      proposedGameState->numMissionariesRight--;
    }
  }

  // move over the number of cannibals told
  for (int c = 0; c < numCannibalsToMove; c++) {
    if (parentGameState->locationOfBoat == LEFT) {
      proposedGameState->numCannibalsLeft--;
      proposedGameState->numCannibalsRight++;
    } else if (parentGameState->locationOfBoat == RIGHT) {
      proposedGameState->numCannibalsLeft++;
      proposedGameState->numCannibalsRight--;
    }
  }

  // set the action and parent
  proposedGameState->action.numMissionariesMoving = numMissionariesToMove;
  proposedGameState->action.numCannibalsMoving = numCannibalsToMove;
  proposedGameState->parent = parentGameState;

  return proposedGameState;
}

bool haveSeenBefore(GameState *state, const std::vector<GameState*>& history) {
  for (unsigned int i = 0; i < history.size(); i++) {
    if (state->numMissionariesLeft == history[i]->numMissionariesLeft &&
        state->numMissionariesRight == history[i]->numMissionariesRight &&
        state->numCannibalsLeft == history[i]->numCannibalsLeft &&
        state->numCannibalsRight == history[i]->numCannibalsRight &&
        state->locationOfBoat == history[i]->locationOfBoat) {
          return true;
        }
  }
  return false;
}

int main(int argc, char const *argv[]) {
  // BREADTH FIRST SEARCH
  GameState *root, *currentGameState, *proposedGameState;
  bool solutionFound = false;
  queue<GameState*> q;
  vector<GameState*> history;

  root = new GameState();
  root->numMissionariesLeft = 3;
  root->numCannibalsLeft = 3;
  root->numMissionariesRight = 0;
  root->numCannibalsRight = 0;
  root->parent = NULL;
  root->locationOfBoat = LEFT;
  root->iteration = 0;

  // init queue
  q.push(root);
  // while solution not found
  while (!solutionFound && q.size() > 0) {
    // pop off
    cout << "Queue has: " << q.size() << " - History has: " << history.size() << endl;
    currentGameState = q.front();
    q.pop();
    history.push_back(currentGameState);

    // otherwise, make all possible children
    for (int peopleCounter = MAX_BOAT_SIZE; peopleCounter > 0; peopleCounter--) {
      for (int m = peopleCounter; m >= 0; m--) {
        proposedGameState = makeNewState(currentGameState, m, (peopleCounter - m));
        // if this state is exists (is able to be produced...)
        if (proposedGameState != NULL) {
          if (proposedGameState->isSolution()) {
            cout << "solution: ";
            proposedGameState->print();
            solutionFound = true;
          } else if (proposedGameState->isValid() && !haveSeenBefore(proposedGameState, history)) {
            q.push(proposedGameState);
          } else {
            delete proposedGameState;
          }
        }
      }
    }
    // char dummyChar;
    // cin >> dummyChar;
  }

  if (!solutionFound) {
    cout << "Game space searched, solution not found" << endl;
  }

  // delete everything in history (for memory management)
  for (unsigned int i = 0; i < history.size(); i++) {
    delete history[i];
  }

}

#endif
