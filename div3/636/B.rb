# frozen_string_literal: true

class Result
  def print_result
    n = gets.to_i
    return puts 'NO' if (n / 2).odd?

    puts 'YES'

    (n / 2).times do |i|
      print (i + 1) * 2, ' '
    end
    (n / 2).times do |i|
      print (i * 2) + 1 + (i + 1 == n / 2 ? n / 2 : 0), ' '
    end
    puts
  end
end

gets.to_i.times do
  Result.new.print_result
end
