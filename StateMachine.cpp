#include "StateMachine.h"

StateMachine::StateMachine(int initialState, tJump *jumpVector) {
    this->state = initialState;
    this->jumpVector = jumpVector;
}

void StateMachine::setState(int state) {
    this->state = state;
}

int StateMachine::currentState() {
  return(this->state);
}

void StateMachine::process(int value) {
  for (int i = 0; this->jumpVector[i].handler != 0; i++) {
    if (this->jumpVector[i].state == this->state) {
      this->state = (this->jumpVector[i].handler)(value);
      break;
    }
  }
}