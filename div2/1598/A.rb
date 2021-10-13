# 4
# 3
# 000
# 000
# 4
# 0011
# 1100
# 4
# 0111
# 1110
# 6
# 010101
# 101010

n = gets.to_i

def result
  n = gets.to_i
  arr = 2.times.map { gets.split('').map(&:to_i) }
  if n.times.all? do |i|
    arr[0][i] == 0 || arr[1][i] == 0
  end
    'YES'
  else
    'NO'
  end
end

n.times do
  puts result
end
