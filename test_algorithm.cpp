#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "sort.h"

#include "unit_test.h"

using std::equal;
using std::string;
using std::vector;

////////////////////////////////////////////////////////////////////////////////
/// @brief Testing of algorithm
/// @ingroup Testing
////////////////////////////////////////////////////////////////////////////////
class algorithm_test : public test_class {

  protected:

    void test() {
	  test_slow_sort_integers();
	  
      test_slow_sort_integers_already_sorted();

      test_slow_sort_strings();

      test_sort_integers();

      test_sort_integers_already_sorted();

      test_sort_strings();
    }

  private:

    
    ///@brief Test slow_sort using integers
    void test_slow_sort_integers() {
      vector<int> v = {3, 2, 5, 6, 8, 4, 3, 1};
      vector<int> sorted = {1, 2, 3, 3, 4, 5, 6, 8};

      my_algorithm::slow_sort(v.begin(), v.end(), std::less<int>());

      assert_msg(v.size() == sorted.size() &&
          equal(sorted.begin(), sorted.end(), v.begin()),
          "Slow sort on integers failed");
    }

    ///@brief Test slow_sort using integers on an already sorted list
    void test_slow_sort_integers_already_sorted() {
      vector<int> v = {1, 2, 3, 3, 4, 5, 6, 8};
      vector<int> sorted = {1, 2, 3, 3, 4, 5, 6, 8};

      my_algorithm::slow_sort(v.begin(), v.end(), std::less<int>());

      assert_msg(v.size() == sorted.size() &&
          equal(sorted.begin(), sorted.end(), v.begin()),
          "Slow sort on integers already sorted failed");
    }

    ///@brief Test slow_sort using strings
    void test_slow_sort_strings() {
      vector<string> v = {"a", "h", "b", "z", "b", "e", "d"};
      vector<string> sorted = {"z", "h", "e", "d", "b", "b", "a"};

      my_algorithm::slow_sort(v.begin(), v.end(), std::greater<string>());

      assert_msg(v.size() == sorted.size() &&
          equal(sorted.begin(), sorted.end(), v.begin()),
          "Slow sort on strings failed");
    }

    ///@brief Test sort using integers
    void test_sort_integers() {
      vector<int> v = {3, 2, 5, 6, 8, 4, 3, 1};
      vector<int> sorted = {1, 2, 3, 3, 4, 5, 6, 8};

      my_algorithm::merge_sort(v.begin(), v.end(), std::less<int>());

      assert_msg(v.size() == sorted.size() &&
          equal(sorted.begin(), sorted.end(), v.begin()),
          "Merge sort on integers failed");
    }

    ///@brief Test sort using integers on an already sorted list
    void test_sort_integers_already_sorted() {
      vector<int> v = {1, 2, 3, 3, 4, 5, 6, 8};
      vector<int> sorted = {1, 2, 3, 3, 4, 5, 6, 8};

      my_algorithm::merge_sort(v.begin(), v.end(), std::less<int>());

      assert_msg(v.size() == sorted.size() &&
          equal(sorted.begin(), sorted.end(), v.begin()),
          "Merge sort on integers already sorted failed");
    }

    ///@brief Test sort using strings
    void test_sort_strings() {
      vector<string> v = {"a", "h", "b", "z", "b", "e", "d"};
      vector<string> sorted = {"z", "h", "e", "d", "b", "b", "a"};

      my_algorithm::merge_sort(v.begin(), v.end(), std::greater<string>());

      assert_msg(v.size() == sorted.size() &&
          equal(sorted.begin(), sorted.end(), v.begin()),
          "Merge sort on strings failed");
    }

};

int main() {
  algorithm_test at;

  if(at.run())
    std::cout << "All tests passed." << std::endl;

  return 0;
}

