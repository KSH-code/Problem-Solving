# 6
# ABACAB
# ABBA
# AC
# ABC
# CABCBB
# BCBCBCBCBCBCBCBC

n = gets.to_i
puts(n.times.map do
  s = gets.strip
  loop do
    if s.include?('B') && s.include?('C')
      s = s.sub('B', '')
      s = s.sub('C', '')
    elsif s.include?('B') && s.include?('A')
      s = s.sub('B', '')
      s = s.sub('A', '')
    else
      break
    end
  end
  s.empty? ? 'YES' : 'NO'
end.join("\n"))
