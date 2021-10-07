# It could not solve with ruby.

require 'set'

def result
  base, target = gets.split.map(&:to_i)

  queue = []
  queue << base

  top = nil
  visited = Set[base]
  result = Array.new(10_000)
  while queue.size > 0
    top = queue.shift
    cur_base = top
    break if cur_base == target

    d_base = cur_base * 2 % 10_000
    if visited.add?(d_base)
      queue << d_base
      result[d_base] = { result: 'D', prev: cur_base }
    end

    s_base = cur_base - 1 == 0 ? 9999 : cur_base - 1
    if visited.add?(s_base)
      queue << s_base
      result[s_base] = { result: 'S', prev: cur_base }
    end

    cur_base_s = cur_base.to_s
    l_base = "#{cur_base_s[1].to_i}#{cur_base_s[2].to_i}#{cur_base_s[3].to_i}#{cur_base_s[0].to_i}".to_i
    if visited.add?(l_base)
      queue << l_base
      result[l_base] = { result: 'L', prev: cur_base }
    end

    r_base = "#{cur_base_s[3].to_i}#{cur_base_s[0].to_i}#{cur_base_s[1].to_i}#{cur_base_s[2].to_i}".to_i
    if visited.add?(r_base)
      queue << r_base
      result[r_base] = { result: 'R', prev: cur_base }
    end
  end

  hello = ''
  prev = top
  while result[prev]
    hello << result[prev][:result]
    prev = result[prev][:prev]
  end
  hello.reverse
end

n = gets.to_i
puts(n.times.map do
  result
end.join("\n"))
