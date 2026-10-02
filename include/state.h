#pragma once

#include <memory>
#include <string>
#include <vector>

class State {
private:
  std::string name;

public:
  explicit State(std::string name);

  const std::string &get_name() const;
};

class States {
private:
  std::vector<std::shared_ptr<State>> states;

public:
  explicit States(std::vector<std::shared_ptr<State>> states);
  bool contains(const std::shared_ptr<State> &state) const;
};
