#ifndef __alt_file_hpp__
#define __alt_file_hpp__

#include <alt/string.hpp>
#include <stdio.h>

namespace alt
{
  enum class FileMode
  {
    R, W, A
  };

  class File
  {
    String fname;
    FileMode md;
    std::FILE* f;

  public:
    explicit File(StringCRange fn, FileMode m)
      : fname(fn), md(m), f(std::fopen(fn)) {}

    ~File() = default;
    File(const File&) = delete;
    File(File&&) = default;
    File& operator=(const File&) = delete;
    File& operator=(File&&) = default;

  public:
    StringCRange filename() const { return fname.range(); }
    FileMode mode() const { return md; }

  public:
    void close() { std::fclose(f); }:wq

  };
}

#endif
