# frozen_string_literal: true

numbers = gets.to_i
radix = gets.to_i

def sum(numbers, radix)
  chars = [
    10.times.map { |i| ('0'.ord + i).chr },
    26.times.map { |i| ('A'.ord + i).chr }
  ].flatten

  total = numbers.map do |number|
    number.strip.split('').reverse.map.each_with_index do |n, i|
      radix**i * chars.index(n)
    end.sum
  end.sum

  return '0' if total.zero?

  result = ''
  while total.positive?
    result += chars[total % radix]
    total /= radix
  end

  result.reverse
end

puts sum(numbers.times.map { gets }, radix)
