// Created by github@Xmind404 on 16:51 30.06.2026.

#include <iostream>
#include <string>
#include <windows.h>

#include "api/keys.h"
#include "functions/response.h"
#include "functions/currency.h"

int main(int argc, char* argv[]) {
  // set charset for ascii
  SetConsoleOutputCP(CP_UTF8);

  bool hasList = false;
  bool hasConvert = false;
  bool hasCheck = false;
  bool showHelp = (argc == 1);

  std::string checkTarget = "";

  std::string from = "PLN";
  std::string to = "USD";
  std::string amount = "";

  for (int i = 1; i < argc; i++) {
    std::string arg = argv[i];

    if (arg == "--help") {
      showHelp = true;
    }
    else if (arg == "--list") {
      hasList = true;
    }
    else if (arg == "--convert") {
      hasConvert = true;
    }
    else if (arg == "--check") {
      hasCheck = true;
      if (i + 1 < argc) {
        checkTarget = argv[++i];
      }
    }
    else if (arg == "--from") {
      if (i + 1 < argc) from = argv[++i];
    }
    else if (arg == "--to") {
      if (i + 1 < argc) to = argv[++i];
    }
    else if (arg == "--amount") {
      if (i + 1 < argc) amount = argv[++i];
    }
  }

  if (showHelp) {
  std::cout
    << assets::colors::NICE_ORANGE
    << "▼ [Currency-Converter]"
    << assets::colors::RESET
    <<  " "
    << "arguments"
    << std::endl << std::endl

    << "  "
    << assets::colors::GREEN << "--list"
    << assets::colors::RESET
    << "                                                  List all available currencies"
    << std::endl

    << "  "
    << assets::colors::YELLOW << "--check"
    << assets::colors::RESET
    << "          "
    << assets::colors::BLUE << "<CODE>"
    << assets::colors::RESET
    << "                                 Show exchange rate for currency (e.g. PLN)"
    << std::endl

    << "  "
    << assets::colors::MAGENTA << "--convert"
    << assets::colors::RESET
    << " "
    << assets::colors::GRAY << "--from"
    << assets::colors::RESET
    << " "
    << assets::colors::BLUE << "<FROM>"
    << assets::colors::RESET
    << " "
    << assets::colors::GRAY << "--to"
    << assets::colors::RESET
    << " "
    << assets::colors::BLUE << "<TO>"
    << assets::colors::RESET
    << " "
    << assets::colors::GRAY << "--amount"
    << assets::colors::RESET
    << " "
    << assets::colors::BLUE << "<AMOUNT>"
    << assets::colors::RESET
    << "     Convert currency"
    << std::endl

    << std::endl

    << "  "
    << assets::colors::GRAY << "--from"
    << assets::colors::RESET
    << "           "
    << assets::colors::BLUE << "<FROM>"
    << assets::colors::RESET
    << "                                 Source currency (default: PLN)"
    << std::endl

    << "  "
    << assets::colors::GRAY << "--to"
    << assets::colors::RESET
    << "             "
    << assets::colors::BLUE << "<TO>"
    << assets::colors::RESET
    << "                                   Target currency (default: USD)"
    << std::endl

    << "  "
    << assets::colors::GRAY << "--amount"
    << assets::colors::RESET
    << "         "
    << assets::colors::BLUE << "<AMOUNT>"
    << assets::colors::RESET
    << "                               Amount to convert"
    << std::endl

    << std::endl

    << assets::colors::NICE_ORANGE
    << "▼ [Currency-Converter] examples:"
    << assets::colors::RESET
    << std::endl

    << "  "
    << assets::colors::DIM
    << "currency-converter --list"
    << assets::colors::RESET
    << std::endl

    << "  "
    << assets::colors::DIM
    << "currency-converter --check PLN"
    << assets::colors::RESET
    << std::endl

    << "  "
    << assets::colors::DIM
    << "currency-converter --convert --from PLN --to USD --amount 1000"
    << assets::colors::RESET
    << std::endl

    << std::endl;
}

  if (hasList) {
    functions::currency::list_currencies();
  }

  if (hasConvert && hasCheck) {
    std::cout << assets::colors::RED << "[ERROR] " << assets::colors::NICE_CREAM << "Cannot use --convert and --check in one sentence!" << std::endl;
  }

  if (hasConvert) {
    functions::currency::convert_currency(from, to, std::stof(amount));
  } else if (hasCheck) {
    if (checkTarget.empty()) {
      std::cout << assets::colors::RED << "[ERROR] " << assets::colors::NICE_CREAM << "Option --check requires providing currency (e.g. --check PLN)" << std::endl;
    }
    functions::currency::check_currency(checkTarget);
  }

  return 0;
}

// currency-converter/main.cpp
