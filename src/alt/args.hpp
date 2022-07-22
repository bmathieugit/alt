#ifndef __lib_args_hpp__
#define __lib_args_hpp__

#include <alt/string.hpp>
#include <alt/array.hpp>
#include <alt/basic_types.hpp>

namespace alt
{
  class CommandLine
  {
  private:
    Range<char **> args;

  public:
    CommandLine(int argc, char **argv) noexcept;
    CommandLine(const CommandLine &) noexcept = default;
    CommandLine(CommandLine &&) noexcept = default;
    CommandLine &operator=(const CommandLine &) noexcept = default;
    CommandLine &operator=(CommandLine &&) noexcept = default;
    ~CommandLine() noexcept = default;

  public:
    Size size() const noexcept;
    bool empty() const noexcept;

  public:
    bool contains(StringCRange wanted) const noexcept;
    StringCRange value(StringCRange wanted) const noexcept;
    Size uinteger(StringCRange wanted) const noexcept;
    long long integer(StringCRange wanted) const noexcept;
    bool flag(StringCRange wanted) const noexcept;

  public:
    StringCRange operator[](Size i) const noexcept
    {
      return alt::sr(args[i]);
    }
  };
}

#endif
