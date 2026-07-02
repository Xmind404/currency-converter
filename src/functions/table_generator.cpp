// Created by github@Xmind404 on 17:41 30.06.2026.
#include "table_generator.h"

namespace functions {
  namespace table_generator {
    void generate_table(int max_row, int max_column, std::vector<std::pair<std::string, float>> table){
      for (int row = 0; row < max_row; row++) {
        for (int col = 0; col < max_column; col++) {
          int index = col * max_row + row;

          if (index >= table.size()) {
            std::cout << "\n";
            continue;
          }

          std::cout << index + 1 << ". " << table[index].first << "\t\t";
        }
        std::cout << std::endl;
      }
    }
  }
}

// currency-converter/table_generator.cpp
