# frozen_string_literal: true

class Result
  def print_result
    n = gets.to_i
    2.upto(29) do |i|
      if n % (2**i - 1) == 0
        puts n / (2**i - 1)
        break
      end
    end
  end
end

gets.to_i.times do
  Result.new.print_result
end
