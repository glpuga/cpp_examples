#include <iostream>
#include <map>
#include <utility>
#include <vector>

template <typename X>
class reveal_type;

class Person {
 public:
  Person(const std::string &name, const int age) : name_{name}, age_{age} {}

  void sayHi() const { std::cout << "Hi! I'm " << name_ << ", and I'm " << age_ << " years old." << std::endl; }

 private:
  std::string name_;
  int age_;
};

class MyVectorStorage {
 public:
  MyVectorStorage(const std::initializer_list<bool> &il) : v_{il} {
    std::cout << "Creating MyVectorStorage by initializer_list!" << std::endl;
  }
  MyVectorStorage(const MyVectorStorage &o) : v_{o.v_} {
    std::cout << "Creating MyVectorStorage by copy!" << std::endl;
  }

  std::vector<bool> get() const { return v_; }

  operator int() { return v_.size(); }

 private:
  std::vector<bool> v_;
};

int main() {
  std::cout << "Using braces initialization is the new trend in C++1X" << std::endl;

  int var_1 = 2;  // this means, initialize with 2 as value
  int var_2(2);   // this means the same
  int var_3{2};   // this is the same too!

  Person bob("bob", 34);        // you can also use braces
  Person louise{"louise", 33};  // for complex constructors
  bob.sayHi();
  louise.sayHi();

  std::cout << "..so many choices, what to use?" << std::endl;

  std::cout << std::endl;
  std::cout << "Uniform initialization has one defining advantage: it doesn't allow narrowing conversions."
            << std::endl;

  int precise_age_1(24.5);  // this will build just fine!

  // int precise_age_3{24.5};  // decimals would be lost, so this would not build
  // int precise_age_4{24.0};  // no decimals? still, double to int is a narrowing conversion

  Person john("john", 39.99);  // this will build just fine, but you'll lose some information...
  john.sayHi();                // no, John, you're not 39...

  // Person lisa{"lisa", 34.11}; // this won't build, the compiler won't let you do a narrowing conversion
  // lisa.sayHi();

  std::cout << std::endl;
  std::cout << "So, I should always use braces? not so fast..." << std::endl;

  std::cout << std::endl;
  std::cout << "If the object being created has a std::initializer_list constructor, {} will make that constructor"
            << std::endl;
  std::cout << "match the call, even if another constructor would be a better match..." << std::endl;

  // if you've been paying attention you would expect the following two to be the same, but they are not

  std::vector<int> v_1(7, 9);  // creates a vector of seven elements, whose values are all 9's
  std::vector<int> v_2{7, 9};  // creates a vector of two elements, a 3 and a 9!

  auto show_me = [](const std::string &name, const auto &v) {
    std::cout << name << " contains ";
    for (const auto &item : v) {
      std::cout << item << " ";
    }
    std::cout << std::endl;
  };

  show_me("v_1", v_1);
  show_me("v_2", v_2);  // not the same

  std::cout << "... even if that better match is the copy/move constructor." << std::endl;

  MyVectorStorage my_weird_vector_1 = {true, false, true, true};

  MyVectorStorage my_weird_vector_2(my_weird_vector_1);  // Invokes copy constructor
  MyVectorStorage my_weird_vector_3{my_weird_vector_1};  // Invokes initializer-list constructor!

  std::cout << "In this case the operator int() and the initializer_list constructor conspire to do this wonder:"
            << std::endl;
  show_me("my_weird_vector_1", my_weird_vector_1.get());
  show_me("my_weird_vector_2", my_weird_vector_2.get());
  show_me("my_weird_vector_3", my_weird_vector_3.get());

  std::cout << std::endl;
  std::cout << "Ok. No braces for classes that have a std::initializer_list constructor. Is that it?" << std::endl;
  std::cout << "No, it still gets a bit weirder." << std::endl;

  double my_age_1 = 38.0;  // this is fine
  double my_age_2(38.0);   // this is fine too
  auto my_age_3 = 38.0;    // this is fine three
  auto my_age_4{38.0};     // this is fine, but not the same, or at least it wasn't.

  // In C++11 and initially in C++14 as well, that would have created an std::initializer<double> with
  // a single element in it.
  // People realized that was silly (the wording says "it's considered a defect") after the fact, and
  // a new proposal (paper N3922) was accepted to correct the behavior in C++17.
  //
  // However, for better or for worse, some compilers (including clang and gcc) have now retrofitted proposal
  // N3922 into their implementations of C++11 and C++14, so the above code will now work as "expected" in
  // those compilers.
  //
  // That is, if what you expected is for the outcome to depend on what compiler and compiler version
  // combination you're using. Not all compilers will implement N3922 as far back as C++11; clang and gcc
  // do, but if your installed version is old enough they don't.

  std::cout << std::endl;
  std::cout << "The type resulting from `auto x{3.0}` is compiler and compiler version dependent on C++11/14"
            << std::endl;
  std::cout << "So, please do yourself a favor and don't use auto with braces unless you're using C++17" << std::endl;

  // reveal_type<decltype(my_age_1)> aux_1;
  // reveal_type<decltype(my_age_2)> aux_2;
  // reveal_type<decltype(my_age_3)> aux_3;
  // reveal_type<decltype(my_age_4)> aux_4; // Check your compiler! What side of N3922 are you on?

  return 0;
}
