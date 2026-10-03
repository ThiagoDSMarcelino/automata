#pragma once

#include <memory>
#include <string>
#include <vector>

class State {
private:
  std::string m_name;

public:
  explicit State(std::string name);

  const std::string &get_name() const { return m_name; };
};

class States {
private:
  std::vector<std::shared_ptr<State>> m_states;

public:
  explicit States(std::vector<std::shared_ptr<State>> states);
  bool contains(const std::shared_ptr<State> &state) const;

  auto begin() const { return m_states.cbegin(); }
  auto end() const { return m_states.cend(); }
};
