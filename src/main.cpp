#include "alphabet.h"
#include "automata.h"
#include "state.h"
#include "transition.h"
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using Symbols = std::vector<std::string>;

int main() {

  auto q1 = std::make_shared<State>("q1");

  auto binary = std::make_shared<Alphabet>("Binary", Symbols{"0", "1"});

  auto t = std::make_shared<TransitionD>("0", q1, q1);

  auto states =
      std::make_unique<States>(std::vector<std::shared_ptr<State>>{q1});

  auto final_states =
      std::make_unique<States>(std::vector<std::shared_ptr<State>>{});

  auto dfa = new DFA("Teste", std::move(states), binary,
                     std::vector<std::shared_ptr<TransitionD>>{t}, q1,
                     std::move(final_states));

  std::vector<std::string> word = {"0", "0", "0", "1"};

  std::cout << "Testing word: \"";
  for (size_t i = 0; i < word.size(); i++) {
    std::cout << word[i];
    if (i < word.size() - 1) {
      std::cout << " ";
    } else {
      std::cout << "\" ";
    }
  }
  std::cout << "in automtata: " << dfa->get_name() << "\n";

  std::cout << "Result: " << dfa->accept(word) << "\n";

  return 0;
}
