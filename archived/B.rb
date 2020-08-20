# frozen_string_literal: true

lines = gets.to_i
lines.times do
  numbers = gets.to_i
  number_permutation = gets.split(' ').map(&:to_i)
  find_map = {}
  number_permutation.each do |i|
    next if find_map[i]

    find_map[i] = true
  end
  print find_map.keys.join(' '), "\n"
end
