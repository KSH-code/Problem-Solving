# frozen_string_literal: true

class Result
  def print_result
    gets
    arr = gets.split(' ').map(&:to_i)

    positive_arrs = [[], []]
    positive_arrs.each_with_index do |positive_arr, j|
      positive = j.zero?
      min = 0
      first = true
      arr.each do |i|
        if first
          if positive && i < 0
            next
          elsif !positive && i > 0
            next
          end

          first = false
        end

        if positive && min < i
          min = i
          next
        end

        if positive && i < 0
          positive = false
          positive_arr.push(min)
          min = i
          next
        end

        if !positive && (min == 0 || min < i) && i < 0
          min = i
          next
        end

        next unless !positive && i > 0

        positive = true
        positive_arr.push(min)
        min = i
      end

      positive_arr.push(min) if min != 0
    end

    puts(if positive_arrs[0].size == positive_arrs[1].size
           positive_arrs.map(&:sum).max
         elsif positive_arrs[0].size > positive_arrs[1].size
           positive_arrs[0].sum
         else
           positive_arrs[1].sum
    end)
  end

  private

  attr_reader :n
end

gets.to_i.times do
  Result.new.print_result
end
