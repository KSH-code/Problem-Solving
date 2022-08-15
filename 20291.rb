gets.to_i.times.map{gets.strip.split('.')[1]}.tally.sort_by(&:first).each{|a,b|puts"#{a} #{b}"}
