def get_max_profit(stock_prices_yesterday)
  min_price = stock_prices_yesterday[0]
  max_profit = 0
  optimum_buy_price = 0
  optimum_sell_price = 0
  
  stock_prices_yesterday.each do |price|
    # Check if this price is a new minimum
    if price < min_price
      min_price = price
    
    # Check if selling at this price would give us a new maximum profit
    else
      profit = price - min_price
      if profit > max_profit
        max_profit = profit
        optimum_buy_price = min_price
        optimum_sell_price = price
      end
    end
  end
  
  [optimum_buy_price, optimum_sell_price, max_profit]
end