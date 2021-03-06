#include <iostream>
#include "html-driver.hh"

int
main (int argc, char *argv[])
{
  int res = 0;
  html_driver driver;
  for (int i = 1; i < argc; ++i)
    if (argv[i] == std::string ("-p"))
      driver.trace_parsing = true;
    else if (argv[i] == std::string ("-s"))
      driver.trace_scanning = true;
    else if (!driver.parse (argv[i]))
      std::cout << driver.result << '\n';
    else
      res = 1;

  for (Node* node : driver.document.children) {
    std::cout << node->nodeName() << std::endl;
  }
  return res;
}
