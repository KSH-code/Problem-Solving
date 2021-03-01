cards = gets.to_i.times.map do |i|
  i + 1
end

while cards.size > 1
  cards.shift
  cards.push(cards.shift)
end

print cards.pop
