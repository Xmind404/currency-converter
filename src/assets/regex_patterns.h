// Created by github@Xmind404 on 20:26 30.06.2026.

#ifndef CURRENCY_CONVERTER_REGEX_PATTERNS_H
#define CURRENCY_CONVERTER_REGEX_PATTERNS_H

#include <list>
#include <regex>

namespace assets {
  namespace regex_patterns {
    inline const std::regex list_currency_pattern(R"(\"([A-Z]{3})\":\s*([0-9.]+))");
    inline const std::regex converted_currency_pattern(R"(\"([A-Z]{3})\":\s*([0-9.]+))");
    std::regex check_currency_pattern(const std::string& currency);
  }
}

#endif //CURRENCY_CONVERTER_REGEX_PATTERNS_H

// currency-converter/regex_patterns.h
