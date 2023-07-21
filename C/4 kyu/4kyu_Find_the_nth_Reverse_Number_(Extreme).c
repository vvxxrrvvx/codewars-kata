unsigned long long int find_reverse_number (unsigned long long int num) {
  if (num == 0) return 0;
  if (num < 11) return num - 1;
  
  unsigned long long int div = 10, nth;
  while(num / div >= 10) div *= 10;
  if (num / div > 1) {
    num -= div;
    nth = num / 10;
    
    }
  else if(num / (div / 10) < 11) {
    num -= (div / 10);
    nth = num / 10;
    }
  else{
    num -= div;
    nth = num;
    }
  while(num) {
    nth = nth * 10 + num % 10;
    num /= 10;
    }  
    return nth;
}