_, m = gets.split.map(&:to_i)
cards = gets.split.map(&:to_i)

result = 99_999_999
0.upto(cards.size - 1) do |i|
  (i + 1).upto(cards.size - 1) do |j|
    (j + 1).upto(cards.size - 1) do |k|
      sum = cards[i] + cards[j] + cards[k]
      result = sum if m >= sum && (m - result).abs > m - sum
    end
  end
end

print(result)
