#ifndef __lib_utility_hpp__
#define __lib_utility_hpp__

#include <alt/basic_types.hpp>
#include <alt/meta.hpp>

namespace alt
{
  constexpr int SUCCESS() noexcept
  {
    return 0;
  }

  constexpr int FAILURE() noexcept
  {
    return 1;
  }

  template <typename T>
  requires NotConst<T>
  constexpr decltype(auto) move(T &&t) noexcept
  {
    return static_cast<RemoveReference<T> &&>(t);
  }

  constexpr Size move(Size&& s) noexcept
  {
    Size s2 = s;
    s = 0;
    return s2; 
  }

  constexpr Size move(Size& s) noexcept
  {
    Size s2 = s; 
    s = 0; 
    return s2;
  }
  
  template <class T>
  constexpr T &&forward(RemoveReference<T> &t) noexcept
  {
    return static_cast<T &&>(t);
  }

  template <class T>
  constexpr T &&forward(RemoveReference<T> &&t) noexcept
  {
    // static_assert(!std::is_lvalue_reference<T>::value,
    //               "Can not forward an rvalue as an lvalue.");
    return static_cast<T &&>(t);
  }

  template <typename T>
  constexpr T &&declval();

  template <typename T>
  const T &as_const(T &&t) noexcept
  {
    return t;
  }

  template <typename C>
  struct StrLen
  {
    constexpr Size operator()(const char *cs) const noexcept
    {
      Size i = 0;

      if (cs != nullptr)
        while (cs[i] != '\0')
          ++i;

      return i;
    }
  };
}

#endif
