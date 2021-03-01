n = gets.to_i
@map = n.times.map do
  gets.strip.split('')
end

def bfs(i, j)
  @visited[i][j] = true
  q = [[i, j]]

  while q.size > 0
    i, j = q.shift

    [-1, 0, 1, 0].zip([0, 1, 0, -1]).each do |x, y|
      next_x = i + x
      next_y = j + y
      if next_x < 0 || next_y < 0 || next_x >= @map.size || next_y >= @map.size || !@same_colors.include?(@map[next_x][next_y]) || @visited[next_x][next_y]
        next
      end

      @visited[next_x][next_y] = true
      q.push([next_x, next_y])
    end
  end

  1
end

def area_count(colors_info)
  @visited = @map.size.times.map { @map.size.times.map { false } }

  count = 0
  0.upto(@map.size - 1) do |i|
    0.upto(@map.size - 1) do |j|
      next if @visited[i][j]

      @same_colors = colors_info.find { |colors| colors.include?(@map[i][j]) }
      bfs(i, j)
      count += 1
    end
  end

  count
end

puts "#{area_count(%w[R G B])} #{area_count(%w[RG B])}"
