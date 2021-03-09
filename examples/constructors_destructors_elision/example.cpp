#include <iostream>
#include <string>

using namespace std;

static std::string op_prefix{" "};

class Object {
 public:
  // default constructor
  Object() {}
  // direct constructor
  Object(const std::string id) : id_(id) { cout << op_prefix << "Direct construction of " << id_ << endl; }
  // copy constructor
  Object(const Object &source) {
    id_ = source.id_;
    cout << op_prefix << "Copy construction of " << id_ << endl;
  }
  // move constructor
  Object(Object &&source) {
    id_ = source.id_;
    cout << op_prefix << "Move construction of " << id_ << endl;
    source.id_ = "empty object (was " + source.id_ + ")";
  }
  // copy assignment
  Object &operator=(const Object &source) {
    id_ = source.id_;
    cout << op_prefix << "Copy assignment of " << id_ << endl;
    return *this;
  }
  // move assignment
  Object &operator=(Object &&source) {
    id_ = source.id_;
    cout << op_prefix << "Move assignment of " << id_ << endl;
    source.id_ = "empty object (was " + source.id_ + ")";
    return *this;
  }
  // Destructor
  ~Object() { std::cout << op_prefix << "Destruction of " << id_ << std::endl; }

  Object operator+(const Object &b) {
    auto new_id = id_ + "+" + b.id_;
    cout << op_prefix << "Summation of " << id_ << " and " << b.id_ << endl;
    return Object(new_id);
  }

  std::string getId() const { return id_; }

 private:
  std::string id_;
};

int main() {
  cout << "For this example, build with and without -fno-elide-constructors" << endl;

  cout << endl;
  cout << "Creation of objects objects" << endl;
  Object A("A");
  Object B("B");
  Object C("C");
  Object D("D");

  cout << endl;
  cout << "The following object gets created in a private scope" << endl;
  { Object X("X"); }

  cout << endl;
  cout << "How many objects do you see here? Try with and without elision." << endl;
  { Object X(Object(Object(Object("X")))); }

  cout << endl;
  cout << "Simple summation, can you follow what's going on?" << endl;
  Object AB;
  AB = A + B;

  cout << endl;
  cout << "Quadruple summation, can you follow what's going on?" << endl;
  Object ABCD;
  ABCD = A + B + C + D;

  cout << endl;
  cout << "How is this different from before?" << endl;
  ABCD = (A + B) + (C + D);

  cout << endl;
  cout << "Exiting program" << endl;
  return 0;
}
