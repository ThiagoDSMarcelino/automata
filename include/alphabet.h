#pragma once

#include <string>
#include <vector>

class Alphabet {
private:
  std::string name;
  std::vector<std::string> symbols;

public:
  Alphabet(std::string name, std::vector<std::string> symbols);

  const std::string &get_name() const;

  const std::vector<std::string> &get_symbols() const;

  bool contains(const std::string &symbol) const;
};
