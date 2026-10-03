#include "automata.h"

#include <memory>
#include <set>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

Automata::Automata(std::string name, std::unique_ptr<States> states,
                   std::shared_ptr<Alphabet> alphabet,
                   std::vector<std::shared_ptr<Transition>> transitions,
                   std::shared_ptr<State> initial_state,
                   std::unique_ptr<States> final_states)
    : m_name(std::move(name)), m_states(std::move(states)),
      m_alphabet(std::move(alphabet)), m_transitions(std::move(transitions)),
      m_initial_state(std::move(initial_state)),
      m_final_states(std::move(final_states)) {
  if (this->m_name.empty()) {
    throw std::invalid_argument("Automata name cannot be empty");
  }

  if (this->m_states == nullptr) {
    throw std::invalid_argument("Automata states cannot be NULL");
  }

  if (this->m_alphabet == nullptr) {
    throw std::invalid_argument("Automata alphabet cannot be NULL");
  }

  if (this->m_initial_state == nullptr) {
    throw std::invalid_argument("Automata initial state cannot be NULL");
  }

  if (!this->m_states->contains(this->m_initial_state)) {
    throw std::invalid_argument(
        "Automata initial state does not belong to the Automata");
  }

  if (this->m_final_states == nullptr) {
    throw std::invalid_argument("Automata final states cannot be NULL");
  }

  for (const auto &state : *this->m_final_states) {
    if (!this->m_states->contains(state)) {
      throw std::invalid_argument(
          "One of the Automata final states does not belong to the Automata");
    }
  }

  for (const auto &state : *this->m_states) {
    m_transitions_by_state[state];
  }

  for (const auto &transition : this->m_transitions) {
    if (transition == nullptr) {
      throw std::invalid_argument("Automata transition cannot be NULL");
    }

    if (!this->m_states->contains(transition->get_from())) {
      throw std::invalid_argument(
          "Transition origin state does not belong to the Automata");
    }

    for (const auto &destination : transition->get_to()) {
      if (!this->m_states->contains(destination)) {
        throw std::invalid_argument(
            "Transition destination state does not belong to the Automata");
      }
    }

    m_transitions_by_state[transition->get_from()].push_back(transition);
  }
}

bool Automata::accept(const std::vector<std::string> &word) const {
  std::vector<std::shared_ptr<State>> current_states = {this->m_initial_state};
  std::vector<std::shared_ptr<State>> next_states;

  for (auto &symbol : word) {
    if (!this->m_alphabet->contains(symbol)) {
      return false;
    }

    for (auto state : current_states) {
      const auto &transitions = this->m_transitions_by_state.at(state);

      for (auto t : transitions) {
        if (t->get_symbol() != symbol) {
          continue;
        }

        for (auto next : t->get_to()) {
          next_states.push_back(next);
        }
      }
    }

    if (next_states.empty()) {
      return false;
    }

    std::swap(current_states, next_states);
    next_states.clear();
  }

  for (const auto &state : current_states) {
    if (this->m_final_states->contains(state)) {
      return true;
    }
  }
  return false;
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
               std::move(initial_state), std::move(final_states)) {
  std::set<std::pair<std::shared_ptr<State>, std::string>> seen;
  for (const auto &transition : this->m_transitions) {
    auto pair =
        std::make_pair(transition->get_from(), transition->get_symbol());

    if (!seen.insert(pair).second) {
      throw std::invalid_argument("Duplicate transition from state " +
                                  transition->get_from()->get_name() +
                                  " for symbol " + transition->get_symbol());
    }
  }
}
