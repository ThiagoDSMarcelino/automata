#include "automata.h"

#include <stdexcept>
#include <utility>

Automata::Automata(std::string name, std::unique_ptr<States> states,
                   std::shared_ptr<Alphabet> alphabet,
                   std::vector<std::shared_ptr<Transition>> transitions,
                   std::shared_ptr<State> initial_state,
                   std::unique_ptr<States> final_states)
    : name(std::move(name)), states(std::move(states)),
      alphabet(std::move(alphabet)), transitions(std::move(transitions)),
      initial_state(std::move(initial_state)),
      final_states(std::move(final_states)) {
  if (this->name.empty()) {
    throw std::invalid_argument("Automata name cannot be empty");
  }

  if (this->alphabet == nullptr) {
    throw std::invalid_argument("Automata alphabet cannot be NULL");
  }

  if (this->initial_state == nullptr) {
    throw std::invalid_argument("Automata initial state cannot be NULL");
  }
}

const std::string &Automata::get_name() const { return name; }

bool Automata::accept(const std::vector<std::string> &word) const {
  auto current_state = this->initial_state;

  for (auto &symbol : word) {
    if (!this->alphabet->contains(symbol)) {
      return false;
    }

    // TODO
  }

  return true;
}

DFA::DFA(std::string name, std::unique_ptr<States> states,
         std::shared_ptr<Alphabet> alphabet,
         std::vector<std::shared_ptr<TransitionD>> transitions,
         std::shared_ptr<State> initial_state,
         std::unique_ptr<States> final_states)
    : Automata(std::move(name), std::move(states), std::move(alphabet),
               std::vector<std::shared_ptr<Transition>>(
                   std::make_move_iterator(transitions.begin()),
                   std::make_move_iterator(transitions.end())),
               std::move(initial_state), std::move(final_states)) {}
