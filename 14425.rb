require 'set'

n, m = gets.strip.split.map(&:to_i)
strs = n.times.map {gets.strip}.to_a.to_set
puts m.times.map.select {strs.include? gets.strip}.size
