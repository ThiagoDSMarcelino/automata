#include "alphabet.h"
#include "automata.h"
#include "state.h"
#include "transition.h"
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using Symbols = std::vector<std::string>;

void test(const std::vector<std::string> &word,
          const std::shared_ptr<Automata> a) {
  std::cout << "Testing word: \"";
  for (size_t i = 0; i < word.size(); i++) {
    std::cout << word[i];
    if (i < word.size() - 1) {
      std::cout << " ";
    } else {
      std::cout << "\" ";
    }
  }
  std::cout << "in automtata: " << a->get_name() << "\n";

  std::cout << "Result: " << std::boolalpha << a->accept(word) << "\n";
}

int main() {
  auto q1 = std::make_shared<State>("q1");

  auto binary = std::make_shared<Alphabet>("Binary", Symbols{"0", "1"});

  auto t = std::make_shared<TransitionD>("0", q1, q1);

  auto states =
      std::make_unique<States>(std::vector<std::shared_ptr<State>>{q1});

  auto final_states =
      std::make_unique<States>(std::vector<std::shared_ptr<State>>{q1});

  auto dfa = std::make_shared<DFA>("Teste", std::move(states), binary,
                                   std::vector<std::shared_ptr<TransitionD>>{t},
                                   q1, std::move(final_states));

  std::vector<std::vector<std::string>> words = {
      {"0"}, {"0", "0"}, {"0", "0", "1"}};

  for (auto &word : words) {
    test(word, dfa);
  }

  return 0;
}
