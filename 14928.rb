n = 0
gets.strip.each_char do |c|
  n = n * 10 + c.ord - '0'.ord
  n%=20000303
end
puts n
