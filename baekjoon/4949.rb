def find_open_bracket(bracket)
  if bracket == ')'
    '('
  elsif bracket == ']'
    '['
  end
end

def brackets?(str)
  only_brackets = str.scan(/[(\[\])]/)

  stack = []
  only_brackets.each do |bracket|
    if find_open_bracket(bracket)
      return false if stack.empty?
      return false if stack.pop != find_open_bracket(bracket)
    else
      stack.push(bracket)
    end
  end

  stack.empty?
end

while true
  str = gets.sub("\n", '')
  break if str == '.'

  puts brackets?(str) ? 'yes' : 'no'
end
