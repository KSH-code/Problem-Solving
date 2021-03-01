# frozen_string_literal: true

class Result
  def print_result
    n, k = gets.split(' ').map(&:to_i)
    arr = gets.split(' ').map(&:to_i)
    count = 0
    sums = {}
    0.upto(n / 2 - 1) do |i|
      result = arr[i] + arr[n - 1 - i]
      sums[result] ||= [0, []]
      sums[result][0] += 1
      sums[result][1] << [arr[i], arr[n - 1 - i]]
    end

    remains = sums.to_a.sort_by(&:last)
    return puts 0 if remains.size == 1

    puts remains.sum(&:last)
  end
end

gets.to_i.times do
  Result.new.print_result
end
