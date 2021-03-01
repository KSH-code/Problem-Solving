while true
  i = gets.strip
  break if i.to_i.zero?

  puts i.to_s.reverse == i ? 'yes' : 'no'
end
