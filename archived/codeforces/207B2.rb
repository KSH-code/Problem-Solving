# frozen_string_literal: true

n = gets.to_i
radius_of_each_tank = n.times.map { gets.to_i }

@full_tanks = radius_of_each_tank.reverse
radius_of_each_tank.each { |r| @full_tanks << r }
@dp = Array.new(radius_of_each_tank.size) { Array.new(radius_of_each_tank.size) { 9_999_999_999} }

def traverse(s, m, e)
  @full_tanks
end

radius_of_each_tank.last.times do |i|
  traverse(radius_of_each_tank.size, radius_of_each_tank.size - i - 1, 0)
end
