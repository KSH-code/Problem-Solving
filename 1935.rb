n = gets.to_i

str = gets

arr = n.times.map {gets.to_f}

stack = []
str.each_char do |c|
    if c <= 'Z' && c >= 'A'
        stack.push(arr[c.ord - 'A'.ord])
    else
        b = stack.pop
        a = stack.pop
        stack.push(eval("#{a}#{c}#{b}"))
    end
end
print "%.2f"%stack.pop