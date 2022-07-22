#include <alt/range.hpp>
#include <alt/test.hpp>

int main()
{
  "Range test suite"_suite(
    "Hello world test"_test([] {
      alt::test::assert::equals(1, 1);
      }))
    .run()
    .print();
}
