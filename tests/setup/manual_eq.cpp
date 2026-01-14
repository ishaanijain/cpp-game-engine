#include <catch_amalgamated.hpp>
#include <test_utils.h>

bool manual_eq(const std::string &lhs, const std::string &rhs) noexcept {
  bool are_size_equal = lhs.size() == rhs.size();
  if (not are_size_equal) {
    UNSCOPED_INFO("Lhs has size " << lhs.size() << ", while rhs has size "
                         << rhs.size());
  }
  const auto size_to_walk = std::min(lhs.size(), rhs.size());

  for (auto i = size_t{}; i < size_to_walk; ++i) {
    if (lhs[i] != rhs[i]) {
      UNSCOPED_INFO("First disagreement @ " << i << '\n'
                                   << "lhs: " << lhs.substr(i, 25) << '\n'
                                   << "rhs: " << rhs.substr(i, 25));
      return false;
    }
  }

  return are_size_equal;
}