#include <iostream>
#include <utility>

/* Only lvalues match a non-const reference parameter */
template <typename T>
void what_is_this(T &) {
  std::cout << "This is an Lvalue" << std::endl;
}

/* Only rvalues match a const reference parameter. If the const is removed
 * this becomes a universal reference (or forwarding reference), and that's a completely
 * different kind of beast! a universal reference matches both rvalues and lvalues! (comment
 * the lvalue function above, remove the const and try) */
template <typename T>
void what_is_this(const T &&) {
  std::cout << "This is an Rvalue" << std::endl;
}

std::string f() { return "string return value"; }

class ClassWithWritableDataMember {
 public:
  int &x() { return x_; }

 private:
  int x_;
};

int testFunction(int arg_1, const int &arg_2, int &&arg_3) {
  int lvalue_1 = 3;
  std::string lvalue_2{"what_is_this"};
  const int const_lvalue_3 = 99;
  ClassWithWritableDataMember class_with_writable_member;

  std::cout << "Things that it doesn't make sense to move from unintentionlly are lvalues. That's mostly variables."
            << std::endl;
  what_is_this(lvalue_1);                        // writable variables are lvalues
  what_is_this(lvalue_2);                        // regardless their type
  what_is_this(const_lvalue_3);                  // const variables are still lvalues!
  what_is_this(class_with_writable_member.x());  // functions returning a writable reference return lvalues too!

  std::cout << "Pretty much anything else is an rvalue" << std::endl;
  what_is_this(3);                      // this is literal
  what_is_this(3 * lvalue_1);           // this is the result of an expression
  what_is_this(lvalue_2 + "more");      // this is the result of an expression
  what_is_this(std::string{"rvalue"});  // this is a temporary object
  what_is_this(f());                    // this is the return value of a string
  what_is_this(std::move(lvalue_2));    // a lvalue can be turned into an rvalue using move

  std::cout << "Notice that function parameters are always lvalues, even rvalue references!" << std::endl;
  what_is_this(arg_1);  // This a by-copy paramters, so it makes sense for it to be an lvalue
  what_is_this(arg_2);  // This is by-const-reference, but still, makes sense
  what_is_this(arg_3);  // This is an rvalue-reference type, but the parameter is an lvalue!

  return 0;
}

int main() {
  testFunction(1, 2, 3);
  return 0;
}
