#include "transition.h"

#include <cstring>
#include <stdexcept>
#include <utility>

Transition::Transition(std::string symbol, std::shared_ptr<State> from,
                       std::vector<std::shared_ptr<State>> to)
    : m_symbol(std::move(symbol)), m_from(std::move(from)),
      m_to(std::move(to)) {
  if (this->m_from == nullptr) {
    throw std::invalid_argument("Transition from state cannot be NULL");
  }
}

TransitionD::TransitionD(std::string symbol, std::shared_ptr<State> from,
                         std::shared_ptr<State> to)
    : Transition(std::move(symbol), std::move(from), {std::move(to)}) {
  if (this->m_symbol.empty()) {
    throw std::invalid_argument(
        "Deterministic transition symbol cannot be empty");
  }
  if (this->m_to.front() == nullptr) {
    throw std::invalid_argument("Transition target state cannot be null");
  }
}

const std::shared_ptr<State> &TransitionD::get_target() const {
  return m_to.front();
}

TransitionN::TransitionN(std::string symbol, std::shared_ptr<State> from,
                         std::vector<std::shared_ptr<State>> to)
    : Transition(std::move(symbol), std::move(from), std::move(to)) {
  if (this->m_symbol.empty()) {
    throw std::invalid_argument(
        "Nondeterministic transition symbol cannot be empty");
  }
}
