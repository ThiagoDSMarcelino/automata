#pragma once

#include "alphabet.h"
#include "state.h"
#include "transition.h"
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

class Automata {
private:
  std::unordered_map<std::shared_ptr<State>,
                     std::vector<std::shared_ptr<Transition>>>
      m_transitions_by_state;

protected:
  Automata(std::string name, std::unique_ptr<States> states,
           std::shared_ptr<Alphabet> alphabet,
           std::vector<std::shared_ptr<Transition>> transitions,
           std::shared_ptr<State> initial_state,
           std::unique_ptr<States> final_states);

  std::string m_name;
  std::unique_ptr<States> m_states;
  std::shared_ptr<Alphabet> m_alphabet;
  std::vector<std::shared_ptr<Transition>> m_transitions;
  std::shared_ptr<State> m_initial_state;
  std::unique_ptr<States> m_final_states;

public:
  const std::string &get_name() const { return m_name; };
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
;
