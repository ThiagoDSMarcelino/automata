#pragma once

#include "state.h"
#include <memory>
#include <string>
#include <vector>

class Transition {
protected:
  std::string m_symbol;
  std::shared_ptr<State> m_from;
  std::vector<std::shared_ptr<State>> m_to;

public:
  Transition(std::string symbol, std::shared_ptr<State> from,
             std::vector<std::shared_ptr<State>> to);
  virtual ~Transition() = default;

  const std::string &get_symbol() const { return m_symbol; }
  const std::shared_ptr<State> &get_from() const { return m_from; }
  const std::vector<std::shared_ptr<State>> &get_to() const { return m_to; }
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
