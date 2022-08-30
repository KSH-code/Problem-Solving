n = gets.to_i
pattern = gets.strip.gsub('*', '.*')
n.times do
    puts(Regexp.new("^#{pattern}$").match?(gets.strip) ? "DA" : "NE")
end
