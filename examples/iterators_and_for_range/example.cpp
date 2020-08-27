#include<iostream>
#include<vector>

int main() {

  std::vector<int> vector_int{1,2,3,4,5,6};

  // Old c-style for-loop:
  // Note that `vector_int.size()` and `index` are not the same type.
  std::cout << "----- Old For-loop style ------" << std::endl;
  for(int index = 0; index < vector_int.size(); index++){
    std::cout << vector_int[index] << std::endl;
  }

  // Use iterators instead!
  // Safer and works for multiple kinds of containers.
  std::cout << "----- Using Iterators ------" << std::endl;
  for (auto it = vector_int.begin(); it != vector_int.end(); it++){
    std::cout << *it << std::endl;
  }

  /////////////////////////////////////////////////////////////////////
  std::cout << "----- Some Iterators explained ------" << std::endl;
  // Iterator pointing to the first element.
  std::vector<int>::iterator it_begin = vector_int.begin();
  std::cout << "Value of it_begin: "<< *it_begin << std::endl;
  // Iterator pointing one position after the last element.
  std::vector<int>::iterator it_end = vector_int.end();
  // "Segmentation Fault" could be appear here:
  // std::cout << "Value of it_end: "<< *it_end << std::endl;

  // All iterators could be incremented. it depends on the container but it could be decremented as well.
  std::cout << "Value before `end` iterator: " << *(it_end - 1) << std::endl;

  std::cout << "----- Using const Iterators ------" << std::endl;
  const std::vector<int>::const_iterator it_cbegin = vector_int.cbegin();
  const std::vector<int>::const_iterator it_cend = vector_int.cend();
  // You can read the values but you are not able to modify them. Try it!
  // *it_cbegin = 15;

  std::cout << "----- You can go backwards using reverse iterators  ------" << std::endl;
  // Iterator pointing to the first element.
  std::vector<int>::reverse_iterator it_rbegin = vector_int.rbegin();
  std::cout << "Value of it_rbegin: "<< *it_rbegin << std::endl;
  // Iterator pointing one position after the last element.
  std::vector<int>::reverse_iterator it_rend = vector_int.rend();
  // Same way, "Segmentation Fault" could be appear here:
  // std::cout << "Value of it_rend: "<< *it_rend << std::endl;

  // There are CONST reverse iterator too.
  std::vector<int>::const_reverse_iterator it_crbegin = vector_int.crbegin();
  std::vector<int>::const_reverse_iterator it_crend = vector_int.crend();
  // Note: `Auto` keyword is your friend, there is no need to be extra verbose.


  ////////////////////////////////
  ////    Applying knowledge  ////
  ////////////////////////////////

  std::cout << "----- Modifying vector_int ------" << std::endl;
  for (auto it = vector_int.begin(); it != vector_int.end(); it++){
    *it = *it * 2;
  }

  std::cout << "----- Reading vector_int ------" << std::endl;
  // Given that we just want to read the values, we could use cbegin and cend.
  for (auto it = vector_int.cbegin(); it != vector_int.cend(); it++){
    std::cout << *it << std::endl;
  }

  std::cout << "----- Reading vector_int backwars ------" << std::endl;
  // Given that we just want to read the values, we could use crbegin and crend.
  for (auto it = vector_int.crbegin(); it != vector_int.crend(); it++){
    std::cout << *it << std::endl;
  }

  std::cout << "----- Range based for loop ------" << std::endl;
  // Range based for loop could be used to avoid extra verbose expressions.
  // In the background, iterators are being used to iterate this loop.
  std::cout << " - `value` contains a copy of the i-th value of `vector_int`"<< std::endl;
  for(auto value : vector_int){
    // Values within `vector_int` won't be changed!.
    value = 0;
  }
  // Check those same values as before.
  for(auto value : vector_int){
    std::cout << value << std::endl;
  }
  std::cout << " - `value` contains a reference of the i-th value of `vector_int`"<< std::endl;
  // But if you want to modify them you can use reference instead.
  for(auto& value : vector_int){
    // Values within `vector_int` will be splitted!.
    value = value/2;
  }
  for(auto& value : vector_int){
    std::cout << value << std::endl;
  }
  // If you just want to read the values, then a constant reference is the appropiate, in order to avoid performance drop.
  // `const` is added in order to avoid modifying the values by mistake.
  std::cout << " - `value` contains a constant reference of the i-th value of `vector_int`"<< std::endl;
  for(const auto& value : vector_int){
    std::cout << value << std::endl;
  }

  std::cout << "----- Iterate old c-style arrays ------" << std::endl;
  // Can you iterate old c-style arrays this way? Sure!
  const std::string old_vector[4]{"uno", "dos", "tres", "c++"};
  for (const auto& value : old_vector){
    std::cout << value << std::endl;
  }

  return 0;
}
