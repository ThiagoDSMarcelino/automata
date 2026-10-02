#pragma once

#include "alphabet.h"
#include "state.h"
#include "transition.h"
#include <memory>
#include <string>
#include <vector>

class Automata {
protected:
  Automata(std::string name, std::unique_ptr<States> states,
           std::shared_ptr<Alphabet> alphabet,
           std::vector<std::shared_ptr<Transition>> transitions,
           std::shared_ptr<State> initial_state,
           std::unique_ptr<States> final_states);

  std::string name;
  std::unique_ptr<States> states;
  std::shared_ptr<Alphabet> alphabet;
  std::vector<std::shared_ptr<Transition>> transitions;
  std::shared_ptr<State> initial_state;
  std::unique_ptr<States> final_states;

public:
  const std::string &get_name() const;
  bool accept(const std::vector<std::string> &word) const;
  virtual ~Automata() = default;
};

class DFA : public Automata {
public:
  DFA(std::string name, std::unique_ptr<States> states,
      std::shared_ptr<Alphabet> alphabet,
      std::vector<std::shared_ptr<TransitionD>> transitions,
      std::shared_ptr<State> initial_state,
      std::unique_ptr<States> final_states);
};
