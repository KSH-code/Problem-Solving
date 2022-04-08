result = 1
1000.downto(2) do |i|
  result *= i-1 if result % i != i-1
end
print result
