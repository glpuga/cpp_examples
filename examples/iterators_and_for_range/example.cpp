#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

int main() {
  std::vector<int> vector_int{11, 22, 33, 44, 55, 66};

  // Old c-style for-loop:
  // Note that `vector_int.size()` and `index` are not the same type.
  std::cout << "----- Old For-loop style ------" << std::endl;
  for (int index = 0; index < vector_int.size(); index++) {
    std::cout << vector_int[index] << std::endl;
  }

  // Use iterators instead!
  // Safer and works for multiple kinds of containers.
  std::cout << "----- Using Iterators ------" << std::endl;
  for (auto it = vector_int.begin(); it != vector_int.end(); it++) {
    std::cout << *it << std::endl;
  }

  // Try to use `auto` keyword instead of typing the complete type:
  // - It saves typing.
  // - Avoids refactoring if the container type changes.
  std::vector<int>::iterator it_begin_without_auto = vector_int.begin();
  // is equal to:
  auto it_begin_with_auto = vector_int.begin();

  /////////////////////////////////////////////////////////////////////
  std::cout << "----- Some Iterators explained ------" << std::endl;
  // Iterator pointing to the first element.
  auto it_begin = vector_int.begin();
  std::cout << "Value of it_begin: " << *it_begin << std::endl;
  // Iterator pointing one position after the last element.
  auto it_end = vector_int.end();
  // The following line leads to an undefined behaviour: there are not guarantees on any outcome.
  // std::cout << "Value of it_end: "<< *it_end << std::endl;

  // All iterators could be incremented. it depends on the container but it could be decremented as well.
  std::cout << "Value before `end` iterator: " << *(it_end - 1) << std::endl;

  std::cout << "----- Using const Iterators ------" << std::endl;
  const auto it_cbegin = vector_int.cbegin();
  const auto it_cend = vector_int.cend();
  // You can read the values but you are not able to modify them. Try it!
  // *it_cbegin = 15;
  // begin() also returns a constant iterator when the instance is const:
  const auto it_c2begin = vector_int.begin();

  std::cout << "----- You can go backwards using reverse iterators  ------" << std::endl;
  // Iterator pointing to the first element.
  auto it_rbegin = vector_int.rbegin();
  std::cout << "Value of it_rbegin: " << *it_rbegin << std::endl;
  // Iterator pointing one position after the last element.
  auto it_rend = vector_int.rend();
  // Same way, "Segmentation Fault" could be appear here:
  // std::cout << "Value of it_rend: "<< *it_rend << std::endl;

  // There are CONST reverse iterator too.
  auto it_crbegin = vector_int.crbegin();
  auto it_crend = vector_int.crend();
  // Note: `Auto` keyword is your friend, there is no need to be extra verbose.

  ////////////////////////////////
  ////    Applying knowledge  ////
  ////////////////////////////////

  std::cout << "----- Modifying vector_int ------" << std::endl;
  for (auto it = vector_int.begin(); it != vector_int.end(); it++) {
    *it = *it * 2;
  }

  std::cout << "----- Reading vector_int ------" << std::endl;
  // Given that we just want to read the values, we could use cbegin and cend.
  for (auto it = vector_int.cbegin(); it != vector_int.cend(); it++) {
    std::cout << *it << std::endl;
  }

  std::cout << "----- Reading vector_int backwards ------" << std::endl;
  // Given that we just want to read the values, we could use crbegin and crend.
  for (auto it = vector_int.crbegin(); it != vector_int.crend(); it++) {
    std::cout << *it << std::endl;
  }

  std::cout << "----- Range based for loop ------" << std::endl;
  // Range based for loop could be used to avoid extra verbose expressions.
  // In the background, iterators are being used to iterate this loop.
  std::cout << " - `value` contains a copy of the i-th value of `vector_int`" << std::endl;
  for (auto value : vector_int) {
    // Values within `vector_int` won't be changed!.
    value = 0;
  }
  // Check those same values as before.
  for (auto value : vector_int) {
    std::cout << value << std::endl;
  }

  std::cout << " - `value` contains a reference of the i-th value of `vector_int`" << std::endl;
  // But if you want to modify them you can use reference instead.
  for (auto& value : vector_int) {
    // Values within `vector_int` will be splitted!.
    value = value / 2;
  }
  for (auto& value : vector_int) {
    std::cout << value << std::endl;
  }

  // If you just want to read the values, then a constant reference is the appropiate way, in order to avoid performance
  // drop. `const` is added in order to avoid modifying the values by mistake.
  std::cout << " - `value` contains a constant reference of the i-th value of `vector_int`" << std::endl;
  for (const auto& value : vector_int) {
    std::cout << value << std::endl;
  }

  // Iterators could be invalidated when:
  //  - an item is added to the container.
  //  - an item is erased from the container.
  //  - the container is resized.
  // The behaviour depends on the container type and where the iterator is pointint to:
  // One example with std::vector:
  std::cout << " - iterator invalidation" << std::endl;
  std::vector<int> vec{11, 55, 110, 155, 220};
  // You can check that the result is not the expected.
  for (auto it = vec.begin(); it != vec.end(); it++) {
    std::cout << *it << std::endl;
    if ((*it) == 110) {
      // inserting a new value while iterating the vector.
      vec.push_back(89);
    }
  }

  // You can use range based for loop with any container.
  std::cout << "----- Iterating a std::map ------" << std::endl;
  const std::map<std::string, double> students_grades_map{
      {"John", 7.58}, {"Pete", 4.68}, {"Carl", 9.99}, {"Jack", 8.73}};
  for (const auto& student_grade : students_grades_map) {
    // `student_grade` will hold a constant reference of type std::pair<std::string, double>
    // in each iteration.
    std::cout << "Student: " << student_grade.first << " -- Grade: " << student_grade.second << std::endl;
  }
  // Even when things are not ordered.
  std::cout << "----- Iterating a std::unordered_map ------" << std::endl;
  const std::unordered_map<std::string, double> students_grades_unordered_map{
      {"John", 7.58}, {"Pete", 4.68}, {"Carl", 9.99}, {"Jack", 8.73}};
  for (const auto& student_grade : students_grades_unordered_map) {
    // Here the outcome isn't the same as the std::map.
    // Run this several times. It is unordered and yet iterators works perfectly.
    std::cout << "Student: " << student_grade.first << " -- Grade: " << student_grade.second << std::endl;
  }

  std::cout << "----- Iterate old c-style arrays ------" << std::endl;
  // Can you iterate old c-style arrays this way? Sure!
  const std::string old_vector[4]{"uno", "dos", "tres", "c++"};
  for (const auto& value : old_vector) {
    std::cout << value << std::endl;
  }

  return 0;
}
