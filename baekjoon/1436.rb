n = gets.to_i

def six?(i)
  i.to_s.match?(/666/)
end

i = 666
while n > 0
  n -= 1 if six?(i)
  i += 1
end

print(i - 1)
