@result = -1
gets.to_i.times do
  x,y = gets.split.map(&:to_i)
  if x <= y
    @result = y if @result == -1
    @result = [y, @result].min
  end
end
p @result
