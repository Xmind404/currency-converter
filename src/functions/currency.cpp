// Created by github@Xmind404 on 18:58 30.06.2026.
#include "currency.h"


namespace functions {
  namespace currency {

    void list_currencies() {
      std::vector<std::pair<std::string, float>> latest_currencies;

      std::string body_list_currencies = functions::response::collect_body(api::keys::FRANKFURTER_KEY + "latest");


      // generate ascii
      std::cout << assets::colors::NICE_ORANGE;
      std::cout << assets::ascii::logo << std::endl << std::endl << std::endl;

      // generate table from latest_currencies
      std::cout << assets::colors::NICE_CREAM << assets::colors::UNDERLINE << "▼ List of Currencies" << assets::colors::RESET << std::endl << std::endl;
      functions::response::search_body(body_list_currencies, assets::regex_patterns::list_currency_pattern, latest_currencies);
      functions::table_generator::generate_table(3,10,latest_currencies);
    }

    void convert_currency(std::string from, std::string to, float amount) {
      std::pair<std::string, float> converted_currency;
      std::string body_converted_currency = functions::response::collect_body(api::keys::FRANKFURTER_KEY + "latest" + "?base=" + from + "&symbols=" + to + "&amount=" + std::to_string(amount));

      std::cout << assets::colors::NICE_CREAM << assets::colors::UNDERLINE << "▼ Converted Currency" << assets::colors::RESET << std::endl << std::endl;
      functions::response::search_body(body_converted_currency, assets::regex_patterns::converted_currency_pattern, converted_currency);



      std::cout << assets::colors::YELLOW << "[FROM] " << assets::colors::NICE_CREAM << std::format("{:.2f}", amount) << " " << from << assets::colors::YELLOW << "\t" << "[TO] " << assets::colors::NICE_ORANGE << converted_currency.second << " " << to << assets::colors::RESET << std::endl << std::endl;
    }

    void check_currency(std::string currency) {
      std::pair<std::string, float> latest_currencies;
      std::pair<std::string, float> previous_currencies;


      auto latest_date = std::chrono::year_month_day(
        std::chrono::floor<std::chrono::days>(
          std::chrono::system_clock::now()
        )
      );

      auto previous_date = std::chrono::year_month_day(
        std::chrono::floor<std::chrono::days>(
          std::chrono::system_clock::now()
        ) - std::chrono::days(1)
      );

      std::string latest_date_str = std::format("{:04}-{:02}-{:02}",
          int(latest_date.year()),
          unsigned(latest_date.month()),
          unsigned(latest_date.day())
      );

      std::string previous_date_str = std::format("{:04}-{:02}-{:02}",
          int(previous_date.year()),
          unsigned(previous_date.month()),
          unsigned(previous_date.day())
      );

      std::string body_latest_currencies = functions::response::collect_body(api::keys::FRANKFURTER_KEY + latest_date_str);
      std::string body_previous_currencies = functions::response::collect_body(api::keys::FRANKFURTER_KEY + previous_date_str);

      functions::response::search_body(body_latest_currencies, assets::regex_patterns::check_currency_pattern(currency), latest_currencies);
      functions::response::search_body(body_previous_currencies, assets::regex_patterns::check_currency_pattern(currency), previous_currencies);

      float changed_currency = (latest_currencies.second - previous_currencies.second) / previous_currencies.second * 100.0f;

      std::cout << assets::colors::NICE_CREAM << assets::colors::UNDERLINE << "▼ Checked Currency" << assets::colors::RESET << std::endl << std::endl;
      std::cout << assets::colors::NICE_ORANGE << "[" << currency << "] " << assets::colors::NICE_CREAM << ((changed_currency >= 0) ? "Went up by " + assets::colors::GREEN : "Went down by " + assets::colors::RED ) << changed_currency << "%" << assets::colors::NICE_CREAM << std::endl << std::endl;
    }
  }
}

// currency-converter/currency.cpp
