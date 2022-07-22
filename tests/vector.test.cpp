#include <alt/vector.hpp>
#include <alt/test.hpp>


int main()
{
  "Vector test suite"_suite(
    
    "should build an empty vector"_test([]{
      alt::Vector<int> vec;
      alt::test::assert::equals(vec.size(), 0);
    }),
    
    "should build a vector with one item"_test([]{
      alt::Vector<int> vec; 
      vec.push(1);
      alt::test::assert::equals(vec.size(), 1);
      alt::test::assert::equals(vec[0], 1);
    }), 
    
    "should build a vector with 1000 item"_test([]{
      alt::Vector<int> vec(1000);
      alt::test::assert::equals(vec.capacity(), 1000);
      alt::test::assert::equals(vec.size(), 0);
      
      for (int i = 0; i < 1000; ++i)
        vec.lpush(i);

      alt::test::assert::equals(vec.capacity(), 1000);
      alt::test::assert::equals(vec.size(), 1000);

      for (int i = 0; i < 1000; ++i)
        alt::test::assert::equals(vec[i], i);
    }), 
    
    "should be equal to vector {0, 1, 2, 3, 4}"_test([]{
      alt::Vector<int> vec;
      alt::Vector<int> vec2;

      for (int i = 0; i < 5; ++i) 
      {
        vec.push(i);
        vec2.push(i);
      }

      for (int i = 0; i < 5; ++i)
      {  
        alt::test::assert::equals(vec[i], i);
        alt::test::assert::equals(vec2[i], i);
        alt::test::assert::equals(vec[i], vec2[i]);
      }
   })
  ).run().print();
}
