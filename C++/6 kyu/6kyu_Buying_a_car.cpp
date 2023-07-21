#include <vector>
#include <cmath>

class BuyCar
{
public:
  static std::vector<int> nbMonths(int startPriceOld, int startPriceNew, int savingperMonth, double percentLossByMonth) {
    int months = 0;
    double savings = 0.0;
    double priceOld = startPriceOld;
    double priceNew = startPriceNew;

    while (savings + priceOld < priceNew) {
      months++;
      savings += savingperMonth;
      priceOld -= priceOld * (percentLossByMonth / 100.0);
      priceNew -= priceNew * (percentLossByMonth / 100.0);

      if (months % 2 == 1)
        percentLossByMonth += 0.5;
    }

    int moneyLeft = std::round(savings + priceOld - priceNew);
    return {months, moneyLeft};
  }
};
