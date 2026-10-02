#include "alphabet.h"

#include <algorithm>
#include <stdexcept>
#include <unordered_set>
#include <utility>

Alphabet::Alphabet(std::string name, std::vector<std::string> symbols)
    : name(std::move(name)), symbols(std::move(symbols)) {
  if (this->name.empty()) {
    throw std::invalid_argument("Alphabet name cannot be empty");
  }

  if (this->symbols.empty()) {
    throw std::invalid_argument("Alphabet must have at least one symbol");
  }

  std::unordered_set<std::string> seen;
  for (const auto &symbol : this->symbols) {
    if (symbol.empty()) {
      throw std::invalid_argument("Alphabet symbols cannot be empty");
    }

    if (!seen.insert(symbol).second) {
      throw std::invalid_argument("Duplicate symbol in alphabet: " + symbol);
    }
  }
}

const std::string &Alphabet::get_name() const { return name; }

const std::vector<std::string> &Alphabet::get_symbols() const {
  return symbols;
}

bool Alphabet::contains(const std::string &symbol) const {
  return std::ranges::find(symbols, symbol) != symbols.end();
}
