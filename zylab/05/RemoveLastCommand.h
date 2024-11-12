#ifndef REMOVELASTCOMMAND_H
#define REMOVELASTCOMMAND_H

#include "UndoCommand.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class RemoveLastCommand : public UndoCommand {
private:
  std::vector<std::string> *sourceVector;

public:
  RemoveLastCommand(std::vector<std::string> *vector) { sourceVector = vector; }

  void Execute() override {
    std::string cmd = sourceVector->back();
    sourceVector->pop_back();
  }
};

#endif
