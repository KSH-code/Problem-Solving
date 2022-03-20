n = gets.to_i
l = 1
r = n
while l < r
  m = (l + r) / 2
  if m * m == n
    print m
    break
  elsif m * m < n
    l = m + 1
  else
    r = m
  end
end
