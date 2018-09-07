#include <iostream>
#include "insertion-mode.hh"

int insertion_mode::state;

void insertion_mode::switchToBfrHTML() {
  state = BEFORE_HTML;
}

int insertion_mode::getState() {
  return state;
}

int main() {
  insertion_mode::switchToBfrHTML();
  int a = insertion_mode::getState();
  std::cout << a << std::endl;  
}

