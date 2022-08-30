gets.to_i.times do
    n = gets.strip
    puts (n.size >= 6 && n.size <= 9) ? "yes" : "no"
end
