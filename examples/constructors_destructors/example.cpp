// Use the following options
// -std=c++14 -fno-elide-constructors
#include <iostream>

#define log() \
  { std::cout << "Uses " << __PRETTY_FUNCTION__ << std::endl; }

class Complex1 {
 public:
  Complex1() : x_{0}, y_{0} { log(); }                                // default constructor
  Complex1(const double x, const double y) : x_{x}, y_{y} { log(); }  // constructor

  // copy and move semantics, constructors
  Complex1(const Complex1 &src) {
    log();
    x_ = src.x_;
    y_ = src.y_;
  }
  Complex1(Complex1 &&src) {
    log();
    x_ = src.x_;
    y_ = src.y_;
  }

  // copy and move semantics, assignments
  Complex1 &operator=(const Complex1 &src) {
    log();
    x_ = src.x_;
    y_ = src.y_;
    return *this;
  }
  Complex1 &operator=(Complex1 &&src) {
    log();
    x_ = src.x_;
    y_ = src.y_;
    return *this;
  }

  double &x() { return x_; }
  const double &x() const { return x_; }
  double &y() { return y_; }
  const double &y() const { return y_; }

 private:
  double x_{0.0};
  double y_{0.0};
};

class Complex2 {
 public:
  explicit Complex2() : x_{0}, y_{0} { log(); }
  explicit Complex2(const double x, const double y) : x_{x}, y_{y} { log() }
  Complex2(const Complex2 &src) {
    log();
    x_ = src.x_;
    y_ = src.y_;
  }
  Complex2(Complex2 &&src) {
    log();
    x_ = src.x_;
    y_ = src.y_;
  }
  Complex2 &operator=(const Complex2 &src) {
    log();
    x_ = src.x_;
    y_ = src.y_;
    return *this;
  }
  Complex2 &operator=(Complex2 &&src) {
    log();
    x_ = src.x_;
    y_ = src.y_;
    return *this;
  }

 private:
  double x_{0.0};
  double y_{0.0};
};

int main() {
  std::cout << "These are direct initialization" << std::endl;
  Complex1 c1_a{};
  Complex1 c1_c{2, 3};

  std::cout << std::endl;
  std::cout << "These are copy initialization, but the compiler might" << std::endl;
  std::cout << "chose to elide the copy and make them into direct initialization" << std::endl;
  Complex1 c1_d = Complex1{};
  Complex1 c1_f = Complex1(2, 3);
  std::cout << "These ones use implicit conversion!" << std::endl;
  Complex1 c1_g = {};
  Complex1 c1_i = {2, 3};

  std::cout << std::endl;
  std::cout << "Complex2 has not explicit constructors, so implicit conversions fail to build" << std::endl;
  Complex2 c2_a{};
  Complex2 c2_c{2, 3};
  Complex2 c2_d = Complex2{};
  Complex2 c2_f = Complex2{2, 3};
  // Complex2 c2_g = {};
  // Complex2 c2_i = {2, 3};

  std::cout << std::endl;
  std::cout << "implicit/explicit conversions can also happen for assignments" << std::endl;
  std::cout << "For Complex1" << std::endl;
  c1_a = {};
  c1_a = {1, 2};
  c1_a = Complex1{};
  c1_a = Complex1{1, 2};
  std::cout << "For Complex2" << std::endl;
  // c2_a = {};           // implicit, fails to build
  // c2_a = {1, 2};       // implicit, fails to build
  c2_a = Complex2{};      // explicit
  c2_a = Complex2{1, 2};  // explicit

  std::cout << std::endl;
  std::cout << "more generally, implicit/explicit conversions can also happen when you call functions" << std::endl;
  std::cout << "For Complex1" << std::endl;
  auto process_complex_1 = [](const Complex1 &c) {};
  auto process_complex_2 = [](const Complex2 &c) {};

  process_complex_1({});              // implicit
  process_complex_1({1, 2});          // implicit
  process_complex_1(Complex1{});      // explicit
  process_complex_1(Complex1{1, 2});  // explicit

  std::cout << "For Complex2" << std::endl;
  // process_complex_2({});           // implicit, fails to build
  // process_complex_2({1, 2});       // implicit, fails to build
  process_complex_2(Complex2{});      // explicit
  process_complex_2(Complex2{1, 2});  // explicit

  return 0;
}