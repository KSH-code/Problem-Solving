# frozen_string_literal: true

class Problem
  def solve
    init_input
    @visits = {}
    puts dfs(s, 0)
  end

  private

  def dfs(s, depth)
    visits[s] = true

    can_go = map[s].reject { |i| visits[i] }
    return 1 if can_go.empty?

    can_go.reduce(0) do |sum, i|
      sum + dfs(i, depth + 1)
    end
  end

  def init_input
    @n, @s, @d = gets.split(' ').map(&:to_i)
    @map = {}
    (n - 1).times do |_i|
      s, e = gets.split(' ').map(&:to_i)
      map[s] ||= []
      map[e] ||= []
      map[s].push(e)
      map[e].push(s)
    end
  end

  attr_reader :n, :s, :d, :map, :visits
end

Problem.new.solve
