#pragma once

#include "state.h"
#include <memory>
#include <string>
#include <vector>

class Transition {
protected:
  std::string symbol;
  std::shared_ptr<State> from;
  std::vector<std::shared_ptr<State>> to;

public:
  Transition(std::string symbol, std::shared_ptr<State> from,
             std::vector<std::shared_ptr<State>> to);
  virtual ~Transition() = default;
};

class TransitionD : public Transition {
public:
  TransitionD(std::string symbol, std::shared_ptr<State> from,
              std::shared_ptr<State> to);

  const std::shared_ptr<State> &get_target() const;
};

class TransitionN : public Transition {
public:
  TransitionN(std::string symbol, std::shared_ptr<State> from,
              std::vector<std::shared_ptr<State>> to);
};
