n = gets.to_i
str = '1'
(2).upto(n) do |i|
  str = "#{str} #{i} #{str}"
end
print str
