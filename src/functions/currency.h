// Created by github@Xmind404 on 18:54 30.06.2026.

#ifndef CURRENCY_CONVERTER_CURRENCY_H
#define CURRENCY_CONVERTER_CURRENCY_H

#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include <chrono>

#include "table_generator.h"
#include "response.h"
#include "../assets/colors.h"
#include "../assets/ascii.h"
#include "../assets/regex_patterns.h"
#include "../api/keys.h"

namespace functions {
  namespace currency {
    void list_currencies();

    void convert_currency(std::string from, std::string to, float amount);
    void check_currency(std::string currency);
  }
}

#endif //CURRENCY_CONVERTER_CURRENCY_H

// currency-converter/currency.h
