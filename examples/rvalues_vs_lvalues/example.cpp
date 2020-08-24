#include <iostream>
#include <utility>

/* Only lvalues match a non-const reference parameter */
template <typename T>
void what_is_this(T&) {
  std::cout << "This is an Lvalue" << std::endl;
}

/* Only rvalues match a const reference parameter. If the const is removed
 * this becomes a universal reference (or forwarding reference), and that's a completely
 * different kind of beast! a universal reference matches both rvalues and lvalues! (comment
 * the lvalue function above, remove the const and try) */
template <typename T>
void what_is_this(const T&&) {
  std::cout << "This is an Rvalue" << std::endl;
}

std::string f() { return "string return value"; }

int main() {
  std::cout << "These are variables, and as such they are lvalues" << std::endl;
  int lvalue_1 = 3;
  std::string lvalue_2{"what_is_this"};
  what_is_this(lvalue_1);
  what_is_this(lvalue_2);

  std::cout << "Pretty much anything else is an rvalue" << std::endl;
  what_is_this(3);                  // this is literal
  what_is_this(3 * lvalue_1);       // this is the result of an expression
  what_is_this(lvalue_2 + "more");  // this is the result of an expression

  what_is_this(std::string{"rvalue"});  // this is a temporary object
  what_is_this(f());                    // this is the return value of a string

  return 0;
}
