#include "state.h"

#include <algorithm>
#include <stdexcept>
#include <utility>

State::State(std::string name) : name(std::move(name)) {
  if (this->name.empty()) {
    throw std::invalid_argument("State name cannot be empty");
  }
}

const std::string &State::get_name() const { return name; }

States::States(std::vector<std::shared_ptr<State>> states)
    : states(std::move(states)) {}

bool States::contains(const std::shared_ptr<State> &state) const {
  return std::find(states.begin(), states.end(), state) != states.end();
}
