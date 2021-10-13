# 2
# 4
# 1 0 0 1 0
# 0 1 0 0 1
# 0 0 0 1 0
# 0 1 0 1 0
# 2
# 0 0 0 1 0
# 0 0 0 1 0

require 'set'

n = gets.to_i

def result
  n = gets.to_i
  arrs = n.times.map { gets.split.map(&:to_i) }
  counts = Array.new(5) { Set.new }
  arrs.each.with_index do |arr, j|
    5.times do |i|
      counts[i].add(j) if arr[i] == 1
    end
  end

  counts = counts.select { |c| c.size >= n / 2 }
  counts.size.times do |i|
    first_group = counts[i]
    (i + 1).upto(counts.size - 1) do |j|
      second_group = counts[j]
      big_group, small_group = if second_group.size < first_group.size
                                 [first_group,
                                  second_group]
                               else
                                 [second_group, first_group]
                               end
      f = 0
      s = 0
      b = 0
      big_group.each do |stu|
        if small_group === stu
          b += 1
        else
          f += 1
        end
      end
      small_group.each do |stu|
        next if big_group === stu

        s += 1
      end
      return 'YES' if n / 2 - f >= 0 && n / 2 - s >= 0 && b == n - f - s
    end
  end
  'NO'
end

n.times do
  puts result
end
