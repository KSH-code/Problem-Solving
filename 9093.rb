gets.to_i.times do
  puts gets.strip.split(' ').map(&:reverse).join(' ')
end