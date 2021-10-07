str = gets
num = ''
type = ''
result = 0
is_negative = false
is_first = true
str.chars.each do |char|
  if char == '+'
  elsif char == '-'
  else
    num += char
    next
  end

  if is_first
    result = num.to_i
    is_first = false
  elsif type == '+' && !is_negative
    result += num.to_i
  else
    result -= num.to_i
  end

  num = ''

  type = char

  is_negative = true if type == '-'
end

if is_negative
  result -= num.to_i
else
  result += num.to_i
end

puts result
