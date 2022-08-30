while str = gets.strip
  break if str == '#'
  result = 0
  puts(str.each_char do |c|
    result += 1 if /[aeiouAEIOU]/.match?(c.to_s)
  end && result)
end
