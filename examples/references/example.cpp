#include <iostream>
#include <utility>

using namespace std;

// Only used to figure the type of the most vexing parse below
template <typename C>
class D;

void f(int &&) { cout << "- f() got called with an R-value reference, ready to MOVE" << endl; }

void f(const int &) { cout << "- f() got called with an L-value reference, ready to COPY" << endl; }

class TestClass {
 public:
  TestClass() = default;

  TestClass(const TestClass &) { cout << "- Matched COPY constructor with L-value argument" << endl; }

  TestClass(TestClass &&) { cout << "- Matched MOVE constructor with R-value argument" << endl; }

 private:
  const int cte{3};
};

int main() {
  int lvalue = 3;  // ok
  lvalue = 4;      // ok

  // int &lvalue_ref = 3;       // build error, cant hook to an rvalue

  const int &lvalue_cref = 3;  // this is ok! const T& hooks to rvalues!
  // lvalue_cref = 5;           // but you can't update its value, its const

  int &&rvalue_ref = 3;  // this is ok, albeit not very useful
  rvalue_ref = 5;        // and this is, weirdly, ok too

  const int &&rvalue_cref = 3;  // this is ok
  // rvalue_cref = 5;           // is is not, it's const

  // They get mostly used in function calls, mostly constructors but not only
  cout << "Calling f() with an lvalue" << endl;
  f(lvalue);
  cout << "Calling f() with an rvalue" << endl;
  f(4);
  cout << "Calling f() with an rvalue casted from an lvalue" << endl;
  f(std::move(lvalue));

  // In constructors they are closely related to move-semantics
  TestClass lvalue_object;

  cout << "Copy construct from lvalue" << endl;
  TestClass copy_constructed{lvalue_object};
  cout << "Move construct from temporary object (DISABLE COPY ELISION)" << endl;
  TestClass move_constructed_1{TestClass()};
  cout << "Move construct from lvalue with std::move" << endl;
  TestClass move_constructed_2{std::move(lvalue_object)};
  cout << "Move construct from rvalue returned by function" << endl;
  auto return_temporary = []() { return TestClass{}; };
  TestClass move_constructed_3{return_temporary()};

  // Bonus!
  // Beware of the "most vexing parse"!
  // This is not what you would expect...

  // TestClass move_constructed2(TestClass()); Most vexing parse!

  // D<decltype(move_constructed2)> aux;
  return 0;
}
