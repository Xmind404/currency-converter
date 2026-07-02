// Created by github@Xmind404 on 18:02 30.06.2026.

#ifndef CURRENCY_CONVERTER_RESPONSE_H
#define CURRENCY_CONVERTER_RESPONSE_H

#include <string>
#include <regex>

#include <cpr/cpr.h>
namespace functions {
  namespace response {
    std::string collect_body(std::string url);

    void search_body(std::string body, std::regex pattern, std::vector<std::pair<std::string, float>>& latest_currencies);

    void search_body(std::string body, const std::regex pattern, std::pair<std::string, float>& latest_currency);
  }
}

#endif //CURRENCY_CONVERTER_RESPONSE_H

// currency-converter/response.h
