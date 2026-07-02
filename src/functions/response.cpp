// Created by github@Xmind404 on 18:04 30.06.2026.

#include "response.h"

namespace functions {
  namespace response {
    std::string collect_body(std::string url) {
      // collecting body from response
      cpr::Response response = cpr::Get(cpr::Url{url});
      std::string body = response.text;

      return body;
    }

    void search_body(std::string body, const std::regex pattern, std::vector<std::pair<std::string, float>>& latest_currencies) {
      std::smatch matches;

      // iteration on response with regex
      while (std::regex_search(body, matches, pattern)) {
        latest_currencies.push_back({matches[1].str(), std::stof(matches[2].str())});

        body = matches.suffix().str();
      }
    }

    void search_body(std::string body, const std::regex pattern, std::pair<std::string, float>& latest_currency) {
      std::smatch matches;

      if (std::regex_search(body, matches, pattern)) {
        latest_currency.first = matches[1].str();
        latest_currency.second = std::stof(matches[2].str());
      }
    }
  }
}

// currency-converter/response.cpp
