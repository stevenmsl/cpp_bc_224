#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol224;

/*
Input: "1 + 1"
Output: 2
*/

tuple<string, int>
testFixture1()
{
  return make_tuple("1+1", 2);
}

/*
Input: " 2-1 + 2 "
Output: 3
*/

tuple<string, int>
testFixture2()
{
  return make_tuple(" 2-1 + 2 ", 3);
}

/*
Input: "(1+(4+5+2)-3)+(6+8)"
Output: 23
*/

tuple<string, int>
testFixture3()
{
  return make_tuple("(1+(4+5+2)-3)+(6+8)", 23);
}

void test1()
{
  auto f = testFixture1();
  cout << "Expect to see " << to_string(get<1>(f)) << endl;
  Solution sol;
  cout << sol.calculate(get<0>(f)) << endl;
}

void test2()
{
  auto f = testFixture2();
  cout << "Expect to see " << to_string(get<1>(f)) << endl;
  Solution sol;
  cout << sol.calculate(get<0>(f)) << endl;
}

void test3()
{
  auto f = testFixture3();
  cout << "Expect to see " << to_string(get<1>(f)) << endl;
  Solution sol;
  cout << sol.calculate(get<0>(f)) << endl;
}

main()
{
  test1();
  test2();
  test3();
  return 0;
}