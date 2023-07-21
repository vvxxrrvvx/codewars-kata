def wordify(n):
    units = ['', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine', 'ten',
             'eleven', 'twelve', 'thirteen', 'fourteen', 'fifteen', 'sixteen', 'seventeen',
             'eighteen', 'nineteen']
    tens = ['', '', 'twenty', 'thirty', 'forty', 'fifty', 'sixty', 'seventy', 'eighty', 'ninety']
    if n == 0:
        return "zero"
    if n < 20:
        return units[n]
    if n < 100:
        return tens[n // 10] + (' ' + units[n % 10] if n % 10 != 0 else '')
    return units[n // 100] + ' hundred' + (' ' + wordify(n % 100) if n % 100 != 0 else '')