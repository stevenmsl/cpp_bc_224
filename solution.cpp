#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <stack>
#include <cstring>
using namespace sol224;
using namespace std;

/*takeaways
  - scan the string from left to right
    - whenever you encounter a '+' or '-' you
      know you are ready to calculate the operand
      on the left
  - use a sign variable to indicate if you should
    add or subtract an operand to/from the total
    - update the sign variable accordingly everytime
      you encounter a '+' or '-' opeator

*/

int Solution::calculate(string s)
{
  auto result = 0;
  auto operand = 0;
  /* the sign to indicate if a left parenthesis is
     behind a + or - operator
     - (1+(4+5)-(2+3))
     - the first left parenthesis is treated
       as if it is behind a '+' since
     - if there is no parenthesis at all this
       sign will determine should we add
       or subtract an operand from the total
       when a '+' or '-' operator is encountered
  */
  auto sign = 1;
  /* for the case where there is no
     parenthesis at all - to
     make the logic of adding a operand
     to the total more consistent with
     the case where you do have parenthesis
  */
  auto sign_stack = stack<int>{{sign}};

  for (auto c : s)
  {
    /* deal with multiple digits */
    if (isdigit(c))
      operand = operand * 10 + (c - '0');
    else if (c == '(')
      /*record the sign comes before this '(' */
      sign_stack.push(sign);
    else if (c == ')')
      sign_stack.pop();
    /* the operand on the left can be calculated now */
    else if (c == '+' || c == '-')
    {
      result += operand * sign;
      /* prepare the sign for the next '('
         - example  1-(2-3), for 3 there
           are two '-' before it so
           when calcualting the expression
          it will become +3
      */
      sign = (c == '+' ? 1 : -1) * sign_stack.top();
      operand = 0;
    }
  }

  /* don't forget the operand on the right */
  return result + operand * sign;
}