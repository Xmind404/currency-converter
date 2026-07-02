// Created by github@Xmind404 on 22:28 30.06.2026.

#include "regex_patterns.h"

namespace assets {
  namespace regex_patterns {
    std::regex check_currency_pattern(const std::string& currency) {
      return std::regex(R"(\"()" + currency + R"()\"\s*:\s*([0-9.]+))");
    }
  }
}

// currency-converter/regex_patterns.cpp
