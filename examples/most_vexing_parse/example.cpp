#include <iostream>
#include <utility>

using namespace std;

// Only used to figure the type of the most vexing parse below
template <typename C>
class Reveal;

class TestClass {};

int main() {
  // Bonus!
  // Beware of the "most vexing parse"!

  TestClass obj_1;    // this is fine
  TestClass obj_2{};  // this is fine too
  TestClass obj_3();  // this will be unexpected

  // Uncomment one below to see the resulting type

  // Reveal<decltype(obj_1)> aux;
  // Reveal<decltype(obj_2)> aux;
  // Reveal<decltype(obj_3)> aux;

  // That's not the only way the most vexing parse can show up!

  auto f_returning_testclass = [] { return TestClass{}; };

  TestClass move_constructed_1{TestClass{}};              // this will behave as expected
  TestClass move_constructed_2{f_returning_testclass()};  // this will behave as expected too
  TestClass move_constructed_3(TestClass());              // this will not be what you expect...

  // Reveal<decltype(move_constructed_1)> aux;
  // Reveal<decltype(move_constructed_2)> aux;
  // Reveal<decltype(move_constructed_3)> aux;

  return 0;
}
