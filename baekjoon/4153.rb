def is_right_triangle?(sides)
  a, b, c = sides.sort
  a**2 + b**2 == c**2
end

while true
  sides = gets.split.map(&:to_i)
  break if sides.sum.zero?

  result = is_right_triangle?(sides) ? 'right' : 'wrong'
  puts result
end
