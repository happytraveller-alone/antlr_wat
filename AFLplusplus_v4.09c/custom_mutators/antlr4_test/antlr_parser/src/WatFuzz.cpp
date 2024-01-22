#include "WatFuzz.h"
int main() {
  // visit
  // StrOverrideVisitor visitor;
  CustomStrVisitor *visitor =
      new CustomStrVisitor("/home/xyf/antlr_wat/AFLplusplus_v4.09c/"
                           "custom_mutators/antlr4_test/input/seed1.txt");
  // visitor->visit(visitor->get_module());

  // output tree
  std::cout << visitor->get_module()->toStringTree(visitor->get_parser())
            << std::endl;
  visitor->visit(visitor->get_module());
  std::cout << visitor->get_rewriter()->getText() << std::endl;
  return 0;
}