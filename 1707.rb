a,b, =gets.strip.split(' ')

q=[[a,0]]

found = -1
until q.empty?
  n, count = q.shift
  found = count + 1 if found == -1 && n == b
  next if n.to_i >= b.to_i

  q.push([(n.to_i * 2).to_s, count + 1])
  q.push([n + '1', count + 1])
end

puts found
