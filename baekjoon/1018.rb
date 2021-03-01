n, m = gets.split.map(&:to_i)

def change_color(color)
  color == 'W' ? 'B' : 'W'
end

def result(map, start_i, start_j, start_color)
  return 12_312_312_312 if start_i + 7 >= map.length || start_j + 7 >= map[start_i].length

  count = 0
  color = start_color

  start_i.upto(start_i + 7) do |i|
    start_j.upto(start_j + 7) do |j|
      count += 1 if color == map[i][j]
      color = change_color(color)
    end
    color = change_color(color)
  end
  64 - count
end

map = []
n.times do
  map.push(gets.strip.split(''))
end

r = 12_312_312_312
0.upto(n - 1) do |i|
  0.upto(m - 1) do |j|
    r = [r, result(map, i, j, 'W'), result(map, i, j, 'B')].min
  end
end
print r
